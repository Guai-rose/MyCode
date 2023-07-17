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
        std::cout << m_name << "调用构造函数AA()。" << std::endl;
    }
    AA(const string &name) : m_name(name)
    {
        std::cout << "调用构造函数AA(" << m_name << ")。" << std::endl;
    }
    ~AA()
    {
        std::cout << "调用了析构函数~AA(): " << m_name << std::endl;
    }
};

// 删除器，普通函数。
void deletefunc(AA *a)
{
    std::cout << "自定义删除器（全局函数）。" << std::endl;
    delete a;
}
// 删除器，仿函数。
struct deleteclass
{
    void operator()(AA *a)
    {
        std::cout << "自定义删除器（仿函数）。" << std::endl;
        delete a;
    }
};
// 删除器，lambda表达式。
auto deletelamb = [](AA *a)
{
    std::cout << "自定义删除器（lambda表达式）。" << std::endl;
    delete a;
};

int main()
{
    // AA *p = new AA("西施");
    // // c++11标准,more efficient(make_unique是c++14标准)
    // // shared_ptr<AA> ptr0 = std::make_shared<AA>("西施");
    shared_ptr<AA> p1(new AA("西施a"), deletefunc);    // 删除器，普通函数
    shared_ptr<AA> p2(new AA("西施b"), deleteclass()); // 删除器，仿函数
    shared_ptr<AA> p3(new AA("西施c"), deletelamb);    // 删除器，lambda表达式
    // shared_ptr<AA> ptr(p);
    // shared_ptr<AA> ptr1(ptr);

    // std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl; // 显示引用计数的值
    // std::cout << "m_name: " << ptr->m_name << std::endl;
    // std::cout << "ptr.get(): " << ptr.get() << std::endl;
    // std::cout << std::endl;

    // std::cout << "ptr1.use_count(): " << ptr1.use_count() << std::endl; // 显示引用计数的值
    // std::cout << "m_name: " << ptr1->m_name << std::endl;
    // std::cout << "ptr1.get(): " << ptr1.get() << std::endl;
    // std::cout << std::endl;

    // shared_ptr<AA> ptr2(ptr); // 用户存在的shared_ptr初始化,计数加1;
    // // shared_ptr<AA> ptr2 = ptr1;// 用户存在的shared_ptr初始化,计数加1;

    // std::cout << "ptr2.use_count(): " << ptr2.use_count() << std::endl; // 显示引用计数的值
    // std::cout << "m_name: " << ptr2->m_name << std::endl;
    // std::cout << "ptr2.get(): " << ptr2.get() << std::endl;

    // e.g.
    shared_ptr<AA> ptr(new AA("西施a"));                              // 初始化资源西施a;
    shared_ptr<AA> ptr1(ptr);                                         // 用户存在的shared_ptr初始化,计数加1;
    shared_ptr<AA> ptr2(ptr1);                                        // 用户存在的shared_ptr初始化,计数加1;
    std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl; // 显示引用计数的值(3)

    shared_ptr<AA> ptrb(new AA("西施b"));                               // 初始化资源西施a;
    shared_ptr<AA> ptrb1 = ptrb;                                        // 用户存在的shared_ptr初始化,计数加1;
    std::cout << "ptrb.use_count(): " << ptrb.use_count() << std::endl; // 显示引用计数的值(2)

    ptrb1 = ptr1;
    ptrb = ptr1; // 执行这句时,在指向西施a的同时释放西施b的资源;

    std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl;   // 显示引用计数的值(4)
    std::cout << "ptrb.use_count(): " << ptrb.use_count() << std::endl; // 显示引用计数的值(2)
}