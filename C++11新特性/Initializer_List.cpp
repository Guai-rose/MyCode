#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// initializer_list<>只能输出相同类型的不同个数参数
// variable template 可以输出不同类型的不同个数参数（更强大）
// narrowing initialization.int i(4.5)[ok] int i{4.5}[warning narrowing]
class P
{
private:
public:
    P(int a, int b)
    {
        cout << "P(int a,int b), a=" << a << ", b=" << b << endl;
    }
    P(initializer_list<int> vals)
    {
        cout << "P(initializer_list<int>),values= ";
        for (auto i : vals)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
void print(initializer_list<int> vals)
{
    for (auto ptr = vals.begin(); ptr != vals.end(); ptr++)
    {
        cout << *ptr;
    }
    cout << endl;
}

int main()
{
    print({1, 2, 3, 4});
    print({1, 2, 6, 7, 8, 9, 4, 10});

    P p(77, 5);     // P(int ,int )
    P q{77, 5};     // P(initializer_list<int>)
    P r{77, 5, 42}; // P(initializer_list<int>)
    P s = {77, 5};  // P(initializer_list<int>)

    vector<int> v1{2, 5, 6, 13, 69, 83, 50};
    vector<int> v2({2, 5, 6, 13, 69, 83, 50});
    vector<int> v3;
    v3 = {2, 5, 6, 13, 69, 83, 50};
    v3.insert(v3.begin() + 2, {0, 1, 2, 3, 4});

    for (auto i : v3)
    {
        cout << i << " ";
    }
    cout << endl; // 2 5 0 1 2 3 4 57 13 69 83 50

    cout << max({string("Ace"), string("Stacy"), string("Sabrina"), string("Barkley")}); // Stacy
    cout << min({string("Ace"), string("Stacy"), string("Sabrina"), string("Barkley")}); // Ace
    cout << max({54, 16, 48, 5});                                                        // 54
    cout << min({54, 16, 48, 5});                                                        // 5
}