#include <iostream>
#include <functional>
using namespace std;

struct Hero // Ӣ�ۻ���
{
    string message = "";
    // virtual void show() { cout << "Ӣ���ͷ��˼���" << endl; }
    function<void(const string &)> m_callback; // ���ڰ�����ĳ�Ա����

    // ע�������Ա����,�����Ա����û�в���
    template <typename Fn, typename... Args>
    void callback(Fn &&fn, Args &&...args)
    {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)..., placeholders::_1);
    }
    void show() { m_callback(message); } // ��������ĳ�Ա����
};

struct XS : public Hero // ��ʩ����
{
    void show(const string &message) { cout << message << "�ͷ��˼���" << endl; }
};

struct HX : public Hero // ���Ż���
{
    void show(const string &message) { cout << message << "�ͷ��˼���" << endl; }
};

int main()
{
    // �����û�ѡ���Ӣ�ۣ�ʩչ����
    int id = 0; // Ӣ��id
    cout << "������Ӣ��(1-��ʩ; 2-����): ";
    cin >> id;

    // ��������ָ�룬ָ������������û���ָ�����������ĳ�Ա����
    Hero *ptr = nullptr;

    if (id == 1)
    {
        ptr = new XS;
        // ��������������,ע�����ĳ�Ա����,ע��ص�����;
        ptr->message = "��ʩ";
        ptr->callback(&XS::show, static_cast<XS *>(ptr));
    }
    else if (id == 2)
    {
        ptr = new HX;
        // ��������������,ע�����ĳ�Ա����,ע��ص�����;
        ptr->message = "����";
        ptr->callback(&HX::show, static_cast<HX *>(ptr));
    }

    if (nullptr != ptr)
    {
        ptr->show();
        delete ptr;
    }
}
