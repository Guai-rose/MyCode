#include <iostream>
#include <memory>
#include <string>

using std::ostream;
using std::shared_ptr;
using std::string;
using std::weak_ptr;
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
    // shared_ptr<AA> pa = std::make_shared<AA>("西施a");
    // shared_ptr<BB> pb = std::make_shared<BB>("西施b");

    // std::cout << "pa.use_count()=" << pa.use_count() << std::endl;
    // std::cout << "pb.use_count()=" << pb.use_count() << std::endl;

    // pa->m_p = pb;
    // pb->m_p = pa;

    // std::cout << "pa.use_count()=" << pa.use_count() << std::endl;
    // std::cout << "pb.use_count()=" << pb.use_count() << std::endl;

    shared_ptr<AA> pa = std::make_shared<AA>("西施a");
    // 语句块
    {
        shared_ptr<BB> pb = std::make_shared<BB>("西施b");

        std::cout << "pa.use_count()=" << pa.use_count() << std::endl;
        std::cout << "pb.use_count()=" << pb.use_count() << std::endl;

        pa->m_p = pb;
        pb->m_p = pa;

        if (pa->m_p.expired() == true)
            std::cout << "语句块内部：pa->m_p已过期" << std::endl;
        else
            std::cout << "语句块内部：pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
    }

    if (pa->m_p.expired() == true)
        std::cout << "语句块外部：pa->m_p已过期" << std::endl;
    else
        std::cout << "语句块外部：pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
}