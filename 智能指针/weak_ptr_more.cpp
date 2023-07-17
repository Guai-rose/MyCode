// 1.weak_ptr不控制对象的生命周期，但是他知道对象是否还活着。
// 2.用lock函数可以把它提升为shared_ptr，如果对象还活着，返回有效的shared_ptr，
// 如果对象已经死了，提升则会失败，返回空的shared_ptr
// 3.提升的行为（lock（））是原子操作，是线程安全的。
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
    weak_ptr<BB> m_p;
};

class BB
{
public:
    string m_name;
    BB()
    {
        std::cout << m_name << "调用构造函数BB()。" << std::endl;
    }
    BB(const string &name) : m_name(name)
    {
        std::cout << "调用构造函数BB(" << m_name << ")。" << std::endl;
    }
    ~BB()
    {
        std::cout << "调用了析构函数~BB(): " << m_name << std::endl;
    }
    weak_ptr<AA> m_p;
};

int main()
{
    shared_ptr<AA> pa = std::make_shared<AA>("西施a");
    // 语句块
    {
        shared_ptr<BB> pb = std::make_shared<BB>("西施b");

        std::cout << "pa.use_count()=" << pa.use_count() << std::endl;
        std::cout << "pb.use_count()=" << pb.use_count() << std::endl;

        pa->m_p = pb;
        pb->m_p = pa;

        shared_ptr<BB> pp = pa->m_p.lock(); // 把weak_ptr提升为shared_ptr。
        // 此处if，else非原子操作，在多线程中，资源可能在这两步骤之间被其他线程释放了
        if (pp == nullptr) // 判断资源是否过期，未过期就将weak_ptr提升为shared_ptr。
            std::cout << "语句块内部：pa->m_p已过期" << std::endl;
        else
            std::cout << "语句块内部：pp->m_name" << pp->m_name << std::endl;
        // std::cout << "语句块内部：pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
    }

    shared_ptr<BB> pp = pa->m_p.lock(); // 把weak_ptr提升为shared_ptr。
    // 此处if，else非原子操作，在多线程中，资源可能在这两步骤之间被其他线程释放了
    if (pp == nullptr) // 判断资源是否过期，未过期就将weak_ptr提升为shared_ptr。过期就置为nullptr
        std::cout << "语句块外部：pa->m_p已过期" << std::endl;
    else
        std::cout << "语句块外部：pp->m_name" << pp->m_name << std::endl;
    // if (pa->m_p.expired() == true)
    //     std::cout << "语句块外部：pa->m_p已过期" << std::endl;
    // else
    //     std::cout << "语句块外部：pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
}