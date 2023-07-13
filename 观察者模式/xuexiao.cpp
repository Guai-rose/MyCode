#include <iostream>
#include <list>
#include <functional>

using namespace std;

// class abstractObserver // 抽象观察者
// {
// public:
//     virtual void update(int) = 0;
// };

// class Subject // 被观察者
// {
// public:
//     void attach(abstractObserver *op)
//     {
//         listop.push_back(op);
//     }
//     void detech(abstractObserver *op)
//     {
//         listop.remove(op);
//     }
//     void notify(int x)
//     {
//         std::list<abstractObserver *>::iterator it = listop.begin();
//         for (; it != listop.end(); ++it)
//         {
//             (*it)->update(x);
//         }
//     }

// private:
//     std::list<abstractObserver *> listop;
// };
// class ObserverA : public abstractObserver // 具体观察者
// {
// public:
//     virtual void update(int x)
//     {
//         cout << "A copy that!" << x << endl;
//     }
// };
// class ObserverB : public abstractObserver // 具体观察者
// {
// public:
//     virtual void update(int x)
//     {
//         cout << "B copy that!" << x << endl;
//     }
// };
// int main()
// {
//     Subject sub;
//     ObserverA *pa = new ObserverA;
//     sub.attach(pa);
//     sub.notify(10);
//     cout << endl;

//     sub.attach(new ObserverB);
//     sub.notify(20);
//     cout << endl;

//     sub.detech(pa);
//     sub.notify(30);
// }

// 包装器改写观察者模式
// function包装的函数类型必须一样：返回值，参数列表
template <typename Func>
class Subject // 被观察者
{
public:
    void attach(Func f)
    {
        listop.push_back(f);
    }
    void detech(Func f)
    {
        listop.remove(f);
    }
    void notify(int x)
    {
        // for (auto it = listop.begin(); it != listop.end(); ++it)
        // {
        //     (*it)(x);
        // }
        for (const Func &f : listop)
        {
            f(x);
        }
    }

private:
    std::list<Func> listop;
};

// function包装器:全局函数
void fa(int x)
{
    cout << "全局函数观察到" << x << endl;
}
// function包装器:静态成员函数
struct stb
{
    static void update(int x)
    {
        cout << "静态函数观察到" << x << endl;
    }
};
// function包装器:仿函数
struct stc
{
    void operator()(int x)
    {
        cout << "仿函数观察到" << x << endl;
    }
};

// function包装器:lambda表达式
// function包装器:成员函数
struct ste
{
public:
    ste(string name) : name(name) {}
    void update(int x)
    {
        cout << name << "观察到" << x << endl;
    }

private:
    string name;
};
int main()
{
    Subject<function<void(int)>> subject; // 被观察者对象
    subject.attach(fa);
    subject.notify(10);
    cout << endl;

    subject.attach(stb::update);
    subject.notify(10);
    cout << endl;

    // function包装器:lambda函数
    auto lam = [](int x) -> void
    { cout << "lambda表达式观察到" << x << endl; };
    subject.attach(lam);
    subject.notify(10);
    cout << endl;

    subject.attach(stc());
    subject.notify(10);
    cout << endl;

    ste d("D");
    subject.attach(bind(&ste::update, &d, placeholders::_1));
    subject.notify(10);
    cout << endl;
}