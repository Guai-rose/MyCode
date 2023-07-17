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
        cout << m_name << "调用构造函数AA()。" << endl;
    }
    AA(const string &name) : m_name(name)
    {
        cout << "调用构造函数AA(" << m_name << ")。" << endl;
    }
    ~AA()
    {
        cout << "调用了析构函数~AA()" << endl;
    }

private:
};

// 删除器，普通函数。
void deletefunc(AA *a)
{
    cout << "自定义删除器（全局函数）。" << endl;
    delete a;
}
// 删除器，仿函数。
struct deleteclass
{
    void operator()(AA *a)
    {
        cout << "自定义删除器（仿函数）。" << endl;
        delete a;
    }
};
// 删除器，lambda表达式。
auto deletelamb = [](AA *a)
{
    cout << "自定义删除器（lambda表达式）。" << endl;
    delete a;
};

// 函数func1()需要一个指针，但不会对这个指针负责
void func1(const AA *a)
{
    cout << a->m_name << endl;
}
// 函数func2()需要一个指针，并且会对这个指针负责。
void func2(AA *a)
{
    cout << a->m_name << endl;
    delete a;
}
// 函数func3()需要一个unique_ptr指针，不会对这个unique_ptr指针负责。
void func3(const unique_ptr<AA> &a)
{
    cout << a->m_name << endl;
}
// 函数func4()需要一个unique_ptr指针，并且会对这个unique_ptr指针负责。
void func4(unique_ptr<AA> a)
{
    cout << a->m_name << endl;
}
int main()
{
    // AA *p = new AA("西施");
    // unique_ptr<AA> p(new AA("西施"));
    unique_ptr<AA, decltype(deletefunc) *> p1(new AA("西施1"), deletefunc); // 删除器，普通函数。
    unique_ptr<AA, void (*)(AA *)> p1(new AA("西施1"), deletefunc);         // 删除器，普通函数。
    unique_ptr<AA, deleteclass> p2(new AA("西施2"), deleteclass());         // 删除器，仿函数。
    unique_ptr<AA, decltype(deletelamb)> p3(new AA("西施3"), deletelamb);   // 删除器，lambda表达式。
    // unique_ptr<AA> p = std::make_unique<AA>("西施");//c++14标准,more efficient
    // cout << "name=" << p->m_name << endl;
    // cout << "name=" << (*p).m_name << endl;

    // cout << "开始调用函数。" << endl;
    // func1(p.get());     // 函数func1()需要一个指针，但不会对这个指针负责
    // func2(p.release()); // 函数func2()需要一个指针，并且会对这个指针负责。
    // func3(p);           // 函数func3()需要一个unique_ptr指针，不会对这个unique_ptr指针负责。
    // func4(move(p));     // 函数func4()需要一个unique_ptr指针，并且会对这个unique_ptr指针负责。
    // cout << "函数调用完成。" << endl;

    // if (nullptr == p)
    //     cout << "p是空指针." << endl;

    // unique_ptr<int> p(int a[10]);
    // unique_ptr<MySelf> m_ptr(new MySelf());\

    // 创建智能指针数组
    // 1.普通指针数组
    //  AA *ptr1 = new AA[2];
    //  AA *ptr1 = new AA[2]{string("西施"), string("冰冰")};
    //  ptr1[0].m_name = "西施1";
    //  cout << "ptr1[0].m_name = " << ptr1[0].m_name << endl;
    //  ptr1[1].m_name = "西施2";
    //  cout << "ptr1[1].m_name = " << ptr1[1].m_name << endl;
    //  delete[] ptr1;

    // 2.智能指针数组
    unique_ptr<AA[]> ptr2(new AA[2]);
    // unique_ptr<AA[]> ptr2(new AA[2]{string("西施"), string("冰冰")});
    ptr2[0].m_name = "西施1";
    cout << "ptr2[0].m_name = " << ptr2[0].m_name << endl;
    ptr2[1].m_name = "西施2";
    cout << "ptr2[1].m_name = " << ptr2[1].m_name << endl;
}
