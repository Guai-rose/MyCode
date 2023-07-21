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

// ��һ�γ��ԣ��Ż�
//  template <typename Container, typename T>
//  void test_moveable(Container cntr, T elem)
//  {
//      Container<T> c;

//     for (long i = 0; i < SIZE; ++i)
//         c.insert(c.end(), T());

//     output_static_data(T());
//     Container<T> c1(c);            // ��������
//     Container<T> c2(std::move(c)); // �ƶ�����
//     c1.swap(c2);
// }

// ��һģ��ֱ�Ӵ���һ��������������������һ��class tmeplate��ȡ��������template����
// e.g. vector<string>,�ܹ�ȡ��Ԫ������string
// test_moveable(list,mystring);
// test_moveable(list,mymovestring);

// �ڶ��γ��ԣ��Ż�
// ����function template+iterator+traits
template <typename Container>
void test_moveable(Container c)
{
    // �����ĵ�����->iterator_traits->value_type����׼ģ���һ���У������׼��˵��
    typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;

    for (long i = 0; i < SIZE; ++i)
        c.insert(c.end(), Valtype());

    output_static_data(*(c.begin()));
    Container<T> c1(c);            // ��������
    Container<T> c2(std::move(c)); // �ƶ�����
    c1.swap(c2);
}
// test_moveable(list<mystring>());
// test_moveable(list<mymovestring>());

// test_moveable(vector<mystring>());
// test_moveable(vector<mymovestring>());
int main()
{
}