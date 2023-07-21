// template <typename T>
// using Vec = std::vector<T, MyAlloc<T>>;
// Vec<int> coll;
// is equivalent to
// std::vector<int, MyAlloc<int>> coll;

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// 第一次尝试，优化
//  template <typename Container, typename T>
//  void test_moveable(Container cntr, T elem)
//  {
//      Container<T> c;

//     for (long i = 0; i < SIZE; ++i)
//         c.insert(c.end(), T());

//     output_static_data(T());
//     Container<T> c1(c);            // 拷贝语义
//     Container<T> c2(std::move(c)); // 移动语义
//     c1.swap(c2);
// }

// 向一模板直接传入一个容器，容器本身又是一个class tmeplate，取出容器的template参数
// e.g. vector<string>,能够取出元素类型string
// test_moveable(list,mystring);
// test_moveable(list,mymovestring);

// 第二次尝试，优化
// 采用function template+iterator+traits
template <typename Container>
void test_moveable(Container c)
{
    // 容器的迭代器->iterator_traits->value_type（标准模板库一定有，脱离标准另说）
    typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;

    for (long i = 0; i < SIZE; ++i)
        c.insert(c.end(), Valtype());

    output_static_data(*(c.begin()));
    Container<T> c1(c);            // 拷贝语义
    Container<T> c2(std::move(c)); // 移动语义
    c1.swap(c2);
}
// test_moveable(list<mystring>());
// test_moveable(list<mymovestring>());

// test_moveable(vector<mystring>());
// test_moveable(vector<mymovestring>());
int main()
{
}