// template template parameter

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// alias template
// template template parameter+alias template
template <typename T>
using Vec = vector<T, allocator<T>>;
template <typename T>
using Lst = list<T, allocator<T>>;

template <typename T,
          template <class>
          class Container>
class XCLs
{
private:
    Container<T> c;

public:
    XCLs()
    { // construtor
        for (long i = 0; i < SIZE; ++i)
            c.insert(c.end(), T());

        output_static_data(T());
        Container<T> c1(c);            // øΩ±¥”Ô“Â
        Container<T> c2(std::move(c)); // “∆∂Ø”Ô“Â
        c1.swap(c2);
    }
};

int main()
{
    // XCLs<MyString, Vec> c1;
    // XCLs<MyStrnomove, Vec> c2;

    // XCLs<MyString, Lst> c3;
    // XCLs<MyStrnomove, Lst> c4;
}