#include <iostream>
#include <functional>
using namespace std;

void show(int n, const string &m)
{
    cout << n << ", " << m << endl;
}
class AA
{
public:
    static void show(int n, const string &m)
    {
        cout << n << ", " << m << endl;
    }
};
class BB
{
public:
    void operator()(int n, const string &m)
    {
        cout << n << ", " << m << endl;
    }
};
class CC
{
public:
    void show(int n, const string &m)
    {
        cout << n << ", " << m << endl;
    }
};
class DD
{
public:
    using func = void (*)(int, const string &);
    operator func()
    {
        return show;
    }
};

// function:
int main()
{
    //
    function<void(int, const string &)> fn1 = bind(show, placeholders::_1, placeholders::_2);
    try
    {
        fn1(1, "超耐磨");
    }
    catch (const std::bad_function_call &e)
    {
        std::cerr << e.what() << '\n';
    }
    //
    function<void(int, const string &)> fn2 = bind(&AA::show, placeholders::_1, placeholders::_2);
    fn2(2, "超耐磨");
    //
    BB bb;
    function<void(int, const string &)> fn3 = bind(bb, placeholders::_1, placeholders::_2);
    fn3(3, "超耐磨");
    //
    auto lb = [](int n, const string &m)
    { cout << n << ", " << m << endl; };
    function<void(int, const string &)> fn4 = bind(lb, placeholders::_1, placeholders::_2);
    fn4(4, "超耐磨");
    //
    CC cc;
    // function<void(CC &, int, const string &)> fn5 = bind(&CC::show, placeholders::_1, placeholders::_2, placeholders::_3);
    // fn5(cc, 5, "超耐磨");
    function<void(int, const string &)> fn5 = bind(&CC::show, &cc, placeholders::_1, placeholders::_2);
    fn5(5, "超耐磨");
    //
    DD dd;
    function<void(int, const string &)> fn6 = bind(DD(), placeholders::_1, placeholders::_2);
    fn6(6, "超耐磨");
}

// bind:
// 普通函数;
// void show(int n, const string &m)
// {
//     cout << "dear:" << n << ", " << m << endl;
// }
// int main()
// {
//     function<void(int, const string &)> fn1 = show;

//     // bind模板函数参数：placeholders::_1 表示参数占位符
//     function<void(int, const string &)> fn2 = bind(show, placeholders::_1, placeholders::_2);
//     fn1(1, "超耐磨");
//     fn2(1, "超耐磨");

//     // function对象参数位置与函数参数为自不一样
//     function<void(const string &, int)> fn3 = bind(show, placeholders::_2, placeholders::_1);
//     fn3("超耐磨", 1);
//     // bind参数提前绑定是值传递，
//     // int bh=3;
//     // function<void(const string &)> fn4 = bind(show, bh, placeholders::_1);
//     // hb=8;运行结果bh=3不是8，若要改变则需要传引用，利用函数std::ref(bh);
//     // fn4("超耐磨");

//     // function函数对象参数比函数参数少
//     function<void(const string &)> fn4 = bind(show, 1, placeholders::_1);
//     fn4("超耐磨");

//     // function函数对象参数比函数参数多
//     function<void(int, const string &, int)> fn5 = bind(show, placeholders::_1, placeholders::_2);
//     fn5(1, "超耐磨", 888);
// }