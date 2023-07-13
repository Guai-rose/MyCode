#include <iostream>
#include <thread>
#include <functional>
using namespace std;
void show0() // 普通函数
{
    cout << "dear ,i am your babe!" << endl;
}

void show1(const string &message) // 普通函数
{
    cout << "dear, " << message << endl;
}

struct CC // 类中有普通成员函数
{
    void show2(int bh, const string &message)
    {
        cout << "dear " << bh << ", " << message << endl;
    }
};

template <typename Fn, typename... Args>
auto show(Fn &&fn, Args &&...args) -> decltype(bind(forward<Fn>(fn), forward<Args>(args)...))
{
    cout << "------before------" << endl;

    // function<> = bind(fn,agrs...);
    auto f = bind(forward<Fn>(fn), forward<Args>(args)...);
    f();

    cout << "------after------" << endl;
    return f;
}
int main()
{

    show(show0);
    cout << endl;
    show(show1, "i am your babe!");
    cout << endl;
    CC cc;
    show(&CC::show2, &cc, 3, "i am your babe!");
    cout << endl;

    // thread t1(show0);
    // thread t2(show1, "i am your babe!");
    // CC cc;
    // thread t3(&CC::show2, &cc, 3, "i am your babe!");
    // t1.join();
    // t2.join();
    // t3.join();
}