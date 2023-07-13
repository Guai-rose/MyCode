#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;

class myTest
{
    friend ostream &operator<<(ostream &out, const myTest &mytest)
    {
        out << mytest._s << endl;
        return out;
    }

public:
    myTest(const char *s = "");
    myTest(const myTest &other);            // 拷贝构造
    myTest &operator=(const myTest &other); // 拷贝赋值
    myTest(myTest &&other);                 // 移动构造
    myTest &operator=(myTest &&other);      // 移动赋值
    ~myTest();                              // 析构

private:
    char *_s;
};

myTest::myTest(const char *s)
{
    _s = new char[strlen(s) + 1];
    strcpy(_s, s);
    cout << "构造函数构造字符串：" << _s << endl;
}

myTest::myTest(const myTest &other)
{
    _s = new char[strlen(other._s) + 1];
    strcpy(_s, other._s);
    cout << "拷贝构造函数构造字符串：" << _s << endl;
}

myTest &myTest::operator=(const myTest &other)
{
    if (nullptr != _s)
        delete[] _s;
    _s = new char[strlen(other._s) + 1];
    strcpy(_s, other._s);
    cout << "拷贝赋值函数构造字符串：" << _s << endl;
    return *this;
}

myTest::myTest(myTest &&other)
{
    this->_s = other._s;
    other._s = nullptr;
    cout << "移动构造函数构造字符串：" << _s << endl;
}

myTest &myTest::operator=(myTest &&other)
{
    if (nullptr != _s)
    {
        cout << "释放字符串：" << _s;
        delete[] _s;
    }
    this->_s = other._s;
    other._s = nullptr;
    cout << ","
         << "移动赋值函数移动字符串：" << _s << endl;
    return *this;
}

myTest::~myTest()
{
    cout << "析构函数析构字符串";
    if (nullptr != _s)
    {
        cout << ": " << _s;
        delete[] _s;
    }
    cout << endl;
}

int main()
{
    // myTest t1("haha");
    // myTest t2 = myTest("xixi");
    // myTest t3(t1);
    // myTest t4;
    // t4 = myTest("heihei");
    // cout << endl;
    list<myTest> li;
    li.push_back(myTest("xixi"));
    li.push_back("haha");
    cout << endl;

    copy(li.begin(), li.end(), ostream_iterator<myTest>(cout, ""));
    cout << endl;

    cout << "------析构函数析构------" << endl;
}
