#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template <typename T,
          template <class>
          class container>
using my_vec = vector<T, allocator<T>>;

int main()
{
    // []
    // {
    //     cout << "hello lambda" << endl;
    // }(); // print hello lambda
    auto l = []
    {
        cout << "hello lambda!" << endl;
    };
    l();

    // size_t id = 0;
    // auto f = [id]() mutable // copy of outside id
    // {
    //     ++id; // 如果没加mutable,id不能++;
    //     cout << "id:" << id << endl;
    // };
    // id = 42;
    // f();
    // f();
    // cout << "id:" << id << endl;

    size_t id = 0;
    auto f1 = [&id](int param)
    {
        cout << "id:" << id << endl;
        ++id;
        ++param;
    };
    id = 42;
    f1(7);
    f1(7);
    cout << "id:" << id << endl;

    // size_t id = 0;
    // auto f3 = [id]()
    // {
    //     cout << "id:" << id << endl;
    //     ++id; // error
    // };
    // id = 42;
    // f3();
    // f3();
    // cout << "id:" << id << endl;

    // size_t id = 0;
    // auto f3 = [id]() mutable
    // {
    //     cout << "id:" << id << endl;
    //     ++id;
    //     static int x = 5;
    //     int y = 6;
    //     return id;
    // };
    // cout << "id:" << id << endl;
}