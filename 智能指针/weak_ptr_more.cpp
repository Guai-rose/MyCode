// 1.weak_ptr�����ƶ�����������ڣ�������֪�������Ƿ񻹻��š�
// 2.��lock�������԰�������Ϊshared_ptr��������󻹻��ţ�������Ч��shared_ptr��
// ��������Ѿ����ˣ��������ʧ�ܣ����ؿյ�shared_ptr
// 3.��������Ϊ��lock��������ԭ�Ӳ��������̰߳�ȫ�ġ�
#include <iostream>
#include <memory>
#include <functional>

using namespace std;
class BB;
class AA
{
public:
    string m_name;
    AA()
    {
        std::cout << m_name << "���ù��캯��AA()��" << std::endl;
    }
    AA(const string &name) : m_name(name)
    {
        std::cout << "���ù��캯��AA(" << m_name << ")��" << std::endl;
    }
    ~AA()
    {
        std::cout << "��������������~AA(): " << m_name << std::endl;
    }
    weak_ptr<BB> m_p;
};

class BB
{
public:
    string m_name;
    BB()
    {
        std::cout << m_name << "���ù��캯��BB()��" << std::endl;
    }
    BB(const string &name) : m_name(name)
    {
        std::cout << "���ù��캯��BB(" << m_name << ")��" << std::endl;
    }
    ~BB()
    {
        std::cout << "��������������~BB(): " << m_name << std::endl;
    }
    weak_ptr<AA> m_p;
};

int main()
{
    shared_ptr<AA> pa = std::make_shared<AA>("��ʩa");
    // ����
    {
        shared_ptr<BB> pb = std::make_shared<BB>("��ʩb");

        std::cout << "pa.use_count()=" << pa.use_count() << std::endl;
        std::cout << "pb.use_count()=" << pb.use_count() << std::endl;

        pa->m_p = pb;
        pb->m_p = pa;

        shared_ptr<BB> pp = pa->m_p.lock(); // ��weak_ptr����Ϊshared_ptr��
        // �˴�if��else��ԭ�Ӳ������ڶ��߳��У���Դ��������������֮�䱻�����߳��ͷ���
        if (pp == nullptr) // �ж���Դ�Ƿ���ڣ�δ���ھͽ�weak_ptr����Ϊshared_ptr��
            std::cout << "�����ڲ���pa->m_p�ѹ���" << std::endl;
        else
            std::cout << "�����ڲ���pp->m_name" << pp->m_name << std::endl;
        // std::cout << "�����ڲ���pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
    }

    shared_ptr<BB> pp = pa->m_p.lock(); // ��weak_ptr����Ϊshared_ptr��
    // �˴�if��else��ԭ�Ӳ������ڶ��߳��У���Դ��������������֮�䱻�����߳��ͷ���
    if (pp == nullptr) // �ж���Դ�Ƿ���ڣ�δ���ھͽ�weak_ptr����Ϊshared_ptr�����ھ���Ϊnullptr
        std::cout << "�����ⲿ��pa->m_p�ѹ���" << std::endl;
    else
        std::cout << "�����ⲿ��pp->m_name" << pp->m_name << std::endl;
    // if (pa->m_p.expired() == true)
    //     std::cout << "�����ⲿ��pa->m_p�ѹ���" << std::endl;
    // else
    //     std::cout << "�����ⲿ��pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
}