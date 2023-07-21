#include <iostream>
#include <complex>
using namespace std;

class Zoo
{
private:
    int d1, d2;

public:
    Zoo(int i1, int i2) : d1(i1), d2(i2) {}
    Zoo(const Zoo &) = delete;
    Zoo(Zoo &&) = default;
    Zoo &operator=(const Zoo &) = default;
    Zoo &operator=(Zoo &&) = delete;
    virtual ~Zoo();
};
int main()
{
}