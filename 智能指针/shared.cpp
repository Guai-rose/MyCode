#include <iostream>
#include <memory>

using std::shared_ptr;
using std::string;

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
};

// ɾ��������ͨ������
void deletefunc(AA *a)
{
    std::cout << "�Զ���ɾ������ȫ�ֺ�������" << std::endl;
    delete a;
}
// ɾ�������º�����
struct deleteclass
{
    void operator()(AA *a)
    {
        std::cout << "�Զ���ɾ�������º�������" << std::endl;
        delete a;
    }
};
// ɾ������lambda���ʽ��
auto deletelamb = [](AA *a)
{
    std::cout << "�Զ���ɾ������lambda���ʽ����" << std::endl;
    delete a;
};

int main()
{
    // AA *p = new AA("��ʩ");
    // // c++11��׼,more efficient(make_unique��c++14��׼)
    // // shared_ptr<AA> ptr0 = std::make_shared<AA>("��ʩ");
    shared_ptr<AA> p1(new AA("��ʩa"), deletefunc);    // ɾ��������ͨ����
    shared_ptr<AA> p2(new AA("��ʩb"), deleteclass()); // ɾ�������º���
    shared_ptr<AA> p3(new AA("��ʩc"), deletelamb);    // ɾ������lambda���ʽ
    // shared_ptr<AA> ptr(p);
    // shared_ptr<AA> ptr1(ptr);

    // std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl; // ��ʾ���ü�����ֵ
    // std::cout << "m_name: " << ptr->m_name << std::endl;
    // std::cout << "ptr.get(): " << ptr.get() << std::endl;
    // std::cout << std::endl;

    // std::cout << "ptr1.use_count(): " << ptr1.use_count() << std::endl; // ��ʾ���ü�����ֵ
    // std::cout << "m_name: " << ptr1->m_name << std::endl;
    // std::cout << "ptr1.get(): " << ptr1.get() << std::endl;
    // std::cout << std::endl;

    // shared_ptr<AA> ptr2(ptr); // �û����ڵ�shared_ptr��ʼ��,������1;
    // // shared_ptr<AA> ptr2 = ptr1;// �û����ڵ�shared_ptr��ʼ��,������1;

    // std::cout << "ptr2.use_count(): " << ptr2.use_count() << std::endl; // ��ʾ���ü�����ֵ
    // std::cout << "m_name: " << ptr2->m_name << std::endl;
    // std::cout << "ptr2.get(): " << ptr2.get() << std::endl;

    // e.g.
    shared_ptr<AA> ptr(new AA("��ʩa"));                              // ��ʼ����Դ��ʩa;
    shared_ptr<AA> ptr1(ptr);                                         // �û����ڵ�shared_ptr��ʼ��,������1;
    shared_ptr<AA> ptr2(ptr1);                                        // �û����ڵ�shared_ptr��ʼ��,������1;
    std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl; // ��ʾ���ü�����ֵ(3)

    shared_ptr<AA> ptrb(new AA("��ʩb"));                               // ��ʼ����Դ��ʩa;
    shared_ptr<AA> ptrb1 = ptrb;                                        // �û����ڵ�shared_ptr��ʼ��,������1;
    std::cout << "ptrb.use_count(): " << ptrb.use_count() << std::endl; // ��ʾ���ü�����ֵ(2)

    ptrb1 = ptr1;
    ptrb = ptr1; // ִ�����ʱ,��ָ����ʩa��ͬʱ�ͷ���ʩb����Դ;

    std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl;   // ��ʾ���ü�����ֵ(4)
    std::cout << "ptrb.use_count(): " << ptrb.use_count() << std::endl; // ��ʾ���ü�����ֵ(2)
}