#include <iostream>

using namespace std;

// 1.using-directives for namespaces and using-declarations for namespace members
// using namespace std; using std::count
// 2.using-declarations for class members
// 在stl_bvector.h中
// protect :
// using _Base::_M_allocate;
// using _Base::_S_nword;
// using _Bse::_M_dealocate;
// using _Bse::_M_get_Bit_allocator;
// 3.type alias and alias template declaration(since c++11)
void example(int, int) {}
using func = void (*)(int, int);

// noexcept(不抛出异常)
// void foo()noexcept->void foo()noexcept(ture)
// void swap(type &x, type &y) noexcept(noexcept(x.swap(y)))
// {
//     x.swap(y);
// }

// override(编译器帮助检查是否正确重写基类虚函数，如果没有，编译器表明错误)
struct Base
{
    virtual void vfunc(float) {}
};
struct Derived1 : Base
{
    virtual void vfunc(int) {}
};
struct Derived2 : Base
{
    // virtual void vfunc(int) override {}
    virtual void vfunc(float) override {}
};

// final
// 1.修饰class，表示该类已是继承体系的最后一位，不能再有其他类继承它
// struct Base1 final
// {
// };
// struct Derive1 : Base1
// {
// };

// 2.修饰virtual函数,不允许被复写
// struct Base2
// {
//     virtual void f() final;
// };
// struct Derive1 : Base2
// {
//     virtual void f();
// };
int main()
{
}