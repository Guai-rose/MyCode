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
        fn1(1, "����ĥ");
    }
    catch (const std::bad_function_call &e)
    {
        std::cerr << e.what() << '\n';
    }
    //
    function<void(int, const string &)> fn2 = bind(&AA::show, placeholders::_1, placeholders::_2);
    fn2(2, "����ĥ");
    //
    BB bb;
    function<void(int, const string &)> fn3 = bind(bb, placeholders::_1, placeholders::_2);
    fn3(3, "����ĥ");
    //
    auto lb = [](int n, const string &m)
    { cout << n << ", " << m << endl; };
    function<void(int, const string &)> fn4 = bind(lb, placeholders::_1, placeholders::_2);
    fn4(4, "����ĥ");
    //
    CC cc;
    // function<void(CC &, int, const string &)> fn5 = bind(&CC::show, placeholders::_1, placeholders::_2, placeholders::_3);
    // fn5(cc, 5, "����ĥ");
    function<void(int, const string &)> fn5 = bind(&CC::show, &cc, placeholders::_1, placeholders::_2);
    fn5(5, "����ĥ");
    //
    DD dd;
    function<void(int, const string &)> fn6 = bind(DD(), placeholders::_1, placeholders::_2);
    fn6(6, "����ĥ");
}

// bind:
// ��ͨ����;
// void show(int n, const string &m)
// {
//     cout << "dear:" << n << ", " << m << endl;
// }
// int main()
// {
//     function<void(int, const string &)> fn1 = show;

//     // bindģ�庯��������placeholders::_1 ��ʾ����ռλ��
//     function<void(int, const string &)> fn2 = bind(show, placeholders::_1, placeholders::_2);
//     fn1(1, "����ĥ");
//     fn2(1, "����ĥ");

//     // function�������λ���뺯������Ϊ�Բ�һ��
//     function<void(const string &, int)> fn3 = bind(show, placeholders::_2, placeholders::_1);
//     fn3("����ĥ", 1);
//     // bind������ǰ����ֵ���ݣ�
//     // int bh=3;
//     // function<void(const string &)> fn4 = bind(show, bh, placeholders::_1);
//     // hb=8;���н��bh=3����8����Ҫ�ı�����Ҫ�����ã����ú���std::ref(bh);
//     // fn4("����ĥ");

//     // function������������Ⱥ���������
//     function<void(const string &)> fn4 = bind(show, 1, placeholders::_1);
//     fn4("����ĥ");

//     // function������������Ⱥ���������
//     function<void(int, const string &, int)> fn5 = bind(show, placeholders::_1, placeholders::_2);
//     fn5(1, "����ĥ", 888);
// }