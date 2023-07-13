#include <iostream>
#include <list>
#include <functional>

using namespace std;

// class abstractObserver // ����۲���
// {
// public:
//     virtual void update(int) = 0;
// };

// class Subject // ���۲���
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
// class ObserverA : public abstractObserver // ����۲���
// {
// public:
//     virtual void update(int x)
//     {
//         cout << "A copy that!" << x << endl;
//     }
// };
// class ObserverB : public abstractObserver // ����۲���
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

// ��װ����д�۲���ģʽ
// function��װ�ĺ������ͱ���һ��������ֵ�������б�
template <typename Func>
class Subject // ���۲���
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

// function��װ��:ȫ�ֺ���
void fa(int x)
{
    cout << "ȫ�ֺ����۲쵽" << x << endl;
}
// function��װ��:��̬��Ա����
struct stb
{
    static void update(int x)
    {
        cout << "��̬�����۲쵽" << x << endl;
    }
};
// function��װ��:�º���
struct stc
{
    void operator()(int x)
    {
        cout << "�º����۲쵽" << x << endl;
    }
};

// function��װ��:lambda���ʽ
// function��װ��:��Ա����
struct ste
{
public:
    ste(string name) : name(name) {}
    void update(int x)
    {
        cout << name << "�۲쵽" << x << endl;
    }

private:
    string name;
};
int main()
{
    Subject<function<void(int)>> subject; // ���۲��߶���
    subject.attach(fa);
    subject.notify(10);
    cout << endl;

    subject.attach(stb::update);
    subject.notify(10);
    cout << endl;

    // function��װ��:lambda����
    auto lam = [](int x) -> void
    { cout << "lambda���ʽ�۲쵽" << x << endl; };
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