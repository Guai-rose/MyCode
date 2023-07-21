// decltype: define a type equivalent to type of an expression

#include <iostream>
#include <bits/stdc++.h>
#include <winsock2.h>
#include <map>
using namespace std;

// map<string, float> coll;
// decltype(coll)::value_type elem;

// map<string, float>::value_type elem;

// 1.to declare return types
template <class T1, class T2>
auto add(T1 x, T2 y) -> decltype(x + y);
// 2.in metaprogramming
template <class T>
void test18_decltype(T obj)
{
    // ������������type����ȡ��inner typedef��û����
    map<string, float>::value_type elem1;

    // ���objȡ��class type��inner typedef
    // ��Ϊ����������˹���decltype
    map<string, float> coll;
    decltype(coll)::value_type elem;

    // ����������
    // ��::��һ��Ҫ��typename������Ϊ�˰���������ȥȷ���������Ǹ�typename,
    // ��Ϊ�������ʱobj����֪����ʲô
    // typedef typename decltype(obj)::iterator iType;
    typedef typename T::iterator iType;
}
// 3.pass(����) the type of a lambda
auto cmp = [](const Person &p1, const Person &p2)
{
    return p1.lastname() < p2.lastname() ||
           (p1.lastname() == p2.lastname() &&
            p1.firstname() < p2.firstname());
};
std::set<Person, decltype(cmp)> coll(cmp);
int main()
{
}