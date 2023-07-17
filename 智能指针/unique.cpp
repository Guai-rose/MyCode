#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

// class MySelf
// {
// public:
//     MySelf(const char *name = " ", size_t age)
//     {
//         m_Name = new char[strlen(name) + 1];
//         strcpy(m_Name, name);
//     }
//     ~MySelf()
//     {
//         if (m_Name != nullptr)
//             delete m_Name;
//     }

// private:
//     char *m_Name;
//     size_t m_Age;
// };
class AA
{
public:
    string m_name;
    AA()
    {
        cout << m_name << "���ù��캯��AA()��" << endl;
    }
    AA(const string &name) : m_name(name)
    {
        cout << "���ù��캯��AA(" << m_name << ")��" << endl;
    }
    ~AA()
    {
        cout << "��������������~AA()" << endl;
    }

private:
};

// ɾ��������ͨ������
void deletefunc(AA *a)
{
    cout << "�Զ���ɾ������ȫ�ֺ�������" << endl;
    delete a;
}
// ɾ�������º�����
struct deleteclass
{
    void operator()(AA *a)
    {
        cout << "�Զ���ɾ�������º�������" << endl;
        delete a;
    }
};
// ɾ������lambda���ʽ��
auto deletelamb = [](AA *a)
{
    cout << "�Զ���ɾ������lambda���ʽ����" << endl;
    delete a;
};

// ����func1()��Ҫһ��ָ�룬����������ָ�븺��
void func1(const AA *a)
{
    cout << a->m_name << endl;
}
// ����func2()��Ҫһ��ָ�룬���һ�����ָ�븺��
void func2(AA *a)
{
    cout << a->m_name << endl;
    delete a;
}
// ����func3()��Ҫһ��unique_ptrָ�룬��������unique_ptrָ�븺��
void func3(const unique_ptr<AA> &a)
{
    cout << a->m_name << endl;
}
// ����func4()��Ҫһ��unique_ptrָ�룬���һ�����unique_ptrָ�븺��
void func4(unique_ptr<AA> a)
{
    cout << a->m_name << endl;
}
int main()
{
    // AA *p = new AA("��ʩ");
    // unique_ptr<AA> p(new AA("��ʩ"));
    unique_ptr<AA, decltype(deletefunc) *> p1(new AA("��ʩ1"), deletefunc); // ɾ��������ͨ������
    unique_ptr<AA, void (*)(AA *)> p1(new AA("��ʩ1"), deletefunc);         // ɾ��������ͨ������
    unique_ptr<AA, deleteclass> p2(new AA("��ʩ2"), deleteclass());         // ɾ�������º�����
    unique_ptr<AA, decltype(deletelamb)> p3(new AA("��ʩ3"), deletelamb);   // ɾ������lambda���ʽ��
    // unique_ptr<AA> p = std::make_unique<AA>("��ʩ");//c++14��׼,more efficient
    // cout << "name=" << p->m_name << endl;
    // cout << "name=" << (*p).m_name << endl;

    // cout << "��ʼ���ú�����" << endl;
    // func1(p.get());     // ����func1()��Ҫһ��ָ�룬����������ָ�븺��
    // func2(p.release()); // ����func2()��Ҫһ��ָ�룬���һ�����ָ�븺��
    // func3(p);           // ����func3()��Ҫһ��unique_ptrָ�룬��������unique_ptrָ�븺��
    // func4(move(p));     // ����func4()��Ҫһ��unique_ptrָ�룬���һ�����unique_ptrָ�븺��
    // cout << "����������ɡ�" << endl;

    // if (nullptr == p)
    //     cout << "p�ǿ�ָ��." << endl;

    // unique_ptr<int> p(int a[10]);
    // unique_ptr<MySelf> m_ptr(new MySelf());\

    // ��������ָ������
    // 1.��ָͨ������
    //  AA *ptr1 = new AA[2];
    //  AA *ptr1 = new AA[2]{string("��ʩ"), string("����")};
    //  ptr1[0].m_name = "��ʩ1";
    //  cout << "ptr1[0].m_name = " << ptr1[0].m_name << endl;
    //  ptr1[1].m_name = "��ʩ2";
    //  cout << "ptr1[1].m_name = " << ptr1[1].m_name << endl;
    //  delete[] ptr1;

    // 2.����ָ������
    unique_ptr<AA[]> ptr2(new AA[2]);
    // unique_ptr<AA[]> ptr2(new AA[2]{string("��ʩ"), string("����")});
    ptr2[0].m_name = "��ʩ1";
    cout << "ptr2[0].m_name = " << ptr2[0].m_name << endl;
    ptr2[1].m_name = "��ʩ2";
    cout << "ptr2[1].m_name = " << ptr2[1].m_name << endl;
}
