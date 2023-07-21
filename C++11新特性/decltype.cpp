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
    // 当我们手上有type，可取其inner typedef，没问题
    map<string, float>::value_type elem1;

    // 面对obj取其class type的inner typedef
    // 因为如今我们有了工具decltype
    map<string, float> coll;
    decltype(coll)::value_type elem;

    // 还可以这样
    // 有::就一定要加typename，这是为了帮助编译器去确定这整个是个typename,
    // 因为编译这段时obj还不知道是什么
    // typedef typename decltype(obj)::iterator iType;
    typedef typename T::iterator iType;
}
// 3.pass(传递) the type of a lambda
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