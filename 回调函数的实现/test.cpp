// ��������-����������ģ��
#include <iostream>
#include <string>
#include <thread> //�߳���ͷ�ļ�
#include <mutex>  //��������ͷ�ļ�
#include <deque>
#include <queue>
#include <condition_variable> //����������ͷ�ļ�
#include <functional>
using namespace std;

void show(const string &message) // ����ҵ�����ͨ����
{
    cout << "��������: " << message << endl;
}

struct BB // ����ҵ����
{
    void show(const string &message)
    {
        cout << "����������: " << message << endl;
    }
};

class AA
{
    mutex m_mutex;                             // ������
    condition_variable m_cond;                 // ��������
    queue<string, deque<string>> m_q;          // ������У��ײ�������deque;
    function<void(const string &)> m_callback; // �ص���������

    // function<void(BB &, const string &)> f1 = &BB::show;
    // function<void(BB &, const string &)> f2 = bind(&BB::show, placeholders::_1, placeholders::_2);

public:
    template <typename Fn, typename... Args>
    void callback(Fn &&fn, Args &&...args)
    {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)..., placeholders::_1); // �󶨻ص�����
    }
    void incache(int num) // ��������,numָ�����ݵĸ���;
    {
        lock_guard<mutex> lock(m_mutex); // �������
        for (int ii = 0; ii < num; ii++)
        {
            static int bh = 1;                           // ��Ů���
            string message = to_string(bh++) + "�ų�Ů"; // ƴ�ӳ�һ������;
            m_q.push(message);                           // �������������������;
        }
        // m_cond.notify_one();//����һ������ǰ���������������߳�
        m_cond.notify_all(); // ����ȫ������ǰ���������������߳�
    }
    void outchache() // �������߳�������
    {
        while (true)
        {
            // �ѻ�����ת����unique_lock<mutex>,���������
            unique_lock<mutex> lock(m_mutex);

            // ����������ٻ���:�������̱߳����Ѻ�,���������û������
            // while(m_q.empty())//������п�,����ѭ��,����ֱ�Ӵ�������,������ѭ��,������if
            // m_cond.wait(lock);1)�ѻ�������;2)����,�ȴ�������;3)������������
            m_cond.wait(lock, [this]
                        { return !m_q.empty(); });

            // ����Ԫ�س���
            string message = m_q.front();
            m_q.pop();
            cout << "�̣߳�" << this_thread::get_id() << ", " << message << endl;
            lock.unlock(); // �ֹ�����

            // ������ӵ�����(���������ѵ�)
            // this_thread::sleep_for(chrono::milliseconds(1)); // ���账��������Ҫ1����
            if (m_callback)
                m_callback(message); // �ص�����,�ѽ��յ������ݴ�����
        }
    }
};

int main()
{
    AA aa;
    // �ڴ����߳�֮ǰ��ע��ص�����
    aa.callback(show); // ��ͨ����
    BB bb;
    // function<void(const string &)> f3 = bind(&BB::show, &bb, placeholders::_1);
    // f3("cao");
    aa.callback(&BB::show, &bb); // ��ĳ�Ա����

    thread t1(&AA::outchache, &aa); // �����������߳�t1
    thread t2(&AA::outchache, &aa); // �����������߳�t2
    thread t3(&AA::outchache, &aa); // �����������߳�t3

    this_thread::sleep_for(chrono::seconds(2)); // ��������
    aa.incache(2);                              // ����2������

    this_thread::sleep_for(chrono::seconds(3)); // ��������
    aa.incache(5);                              // ����5������

    t1.join();
    t2.join();
    t3.join();
}