#include <iostream>

using namespace std;

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
    explicit P(int a, int b, int c)
    {
        cout << "explicit P(int a, int b,int c) \n";
    }
};
void fp(const P &)
{
}

int main()
{
    P p1(77, 5);     // P(int ,int )
    P p2{77, 5};     // P(initializer_list<int>)
    P p3{77, 5, 42}; // P(initializer_list<int>)
    P p4 = {77, 5};  // P(initializer_list<int>)
    // P p5 = {77, 5, 42}; //[error] convertuing to 'P' from initializer_list would use explicit constructor
    P p6(77, 5, 42); // explicit P(int a, int b, int c)

    fp({47, 11}); // P(initializer_list<int>)
    // fp({47, 11, 3});  //[error] convertuing to 'P' from initializer_list would use explicit constructor
    fp(P{47, 11});    // P(initializer_list<int>)
    fp(P{47, 11, 3}); // P(initializer_list<int>)

    P p11{77, 5, 42, 500};    // P(initializer_list<int>)
    P p12 = {77, 5, 42, 500}; // P(initializer_list<int>)
    P p13{10};                // P(initializer_list<int>)
}