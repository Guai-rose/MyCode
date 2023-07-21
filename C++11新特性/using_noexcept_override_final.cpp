#include <iostream>

using namespace std;

// 1.using-directives for namespaces and using-declarations for namespace members
// using namespace std; using std::count
// 2.using-declarations for class members
// ��stl_bvector.h��
// protect :
// using _Base::_M_allocate;
// using _Base::_S_nword;
// using _Bse::_M_dealocate;
// using _Bse::_M_get_Bit_allocator;
// 3.type alias and alias template declaration(since c++11)
void example(int, int) {}
using func = void (*)(int, int);

// noexcept(���׳��쳣)
// void foo()noexcept->void foo()noexcept(ture)
// void swap(type &x, type &y) noexcept(noexcept(x.swap(y)))
// {
//     x.swap(y);
// }

// override(��������������Ƿ���ȷ��д�����麯�������û�У���������������)
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
// 1.����class����ʾ�������Ǽ̳���ϵ�����һλ����������������̳���
// struct Base1 final
// {
// };
// struct Derive1 : Base1
// {
// };

// 2.����virtual����,��������д
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