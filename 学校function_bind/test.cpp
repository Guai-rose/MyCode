#include <functional>
#include <iostream>

using namespace std;
// 普通函数
tuple<char, int> add(int a, int b)
{
    return make_tuple('+', a + b);
}
// 仿函数
struct Sub
{
    tuple<char, int> operator()(int a, int b)
    {
        return make_tuple('-', a - b);
    }
};
// 静态成员函数
struct Mul
{
    static tuple<char, int> mul(int a, int b)
    {
        return make_tuple('*', a * b);
    }
};
// lambda表达式

// 成员函数
struct square
{
    tuple<char, int> sqr(int a)
    {
        return make_tuple('^', a * a);
    }
};
struct square sq1;
function<tuple<char, int>(int, int)> f1 =
    bind(&square::sqr, &sq1, placeholders::_1);

// template <typename T>
// void print(function<tuple<char, T>(int, int)> ft, int a, int b)
template <typename Func>
void print(Func ft, int a, int b)
// template <typename... Func>
// void print(Func&&... args)
{
    auto r = ft(a, b);
    cout << a << get<0>(r) << b << "=" << get<1>(r) << endl;
}

tuple<char, int> addmul(int a, int b, int c)
{
    return make_tuple('#', (a + b) * c);
}
function<tuple<char, int>(int, int)> addMul =
    bind(&addmul, placeholders::_1, placeholders::_2, 2);

struct addmod // 先加计算余数 20%3=2
{
    addmod(int module) : module(module) {}
    tuple<char, int> addMod(int a, int b)
    {
        return make_tuple('$', (a + b) / module);
    }
    int module; // 模
};

int main()
{
    print(&add, 1, 2);
    print(Sub(), 5, 4);
    print(&Mul::mul, 3, 6);

    auto div = [](int a, int b) -> tuple<char, float>
    { //->: 后置返回值类型；
        return make_tuple('/', (float)a / b);
    };
    print(div, 8, 5);

    print(f1, 2, 2);
    print(addMul, 10, 20);

    addmod am(10);
    print(bind(&addmod::addMod, &am, placeholders::_1, placeholders::_2), 11, 22);
}