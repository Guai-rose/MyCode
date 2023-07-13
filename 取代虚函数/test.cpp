#include <iostream>
#include <functional>
using namespace std;

struct Hero // 英雄基类
{
    string message = "";
    // virtual void show() { cout << "英雄释放了技能" << endl; }
    function<void(const string &)> m_callback; // 用于绑定子类的成员函数

    // 注册子类成员函数,子类成员函数没有参数
    template <typename Fn, typename... Args>
    void callback(Fn &&fn, Args &&...args)
    {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)..., placeholders::_1);
    }
    void show() { m_callback(message); } // 调用子类的成员函数
};

struct XS : public Hero // 西施基类
{
    void show(const string &message) { cout << message << "释放了技能" << endl; }
};

struct HX : public Hero // 韩信基类
{
    void show(const string &message) { cout << message << "释放了技能" << endl; }
};

int main()
{
    // 更具用户选择的英雄，施展技能
    int id = 0; // 英雄id
    cout << "请输入英雄(1-西施; 2-韩信): ";
    cin >> id;

    // 创建基类指针，指向派生类对象，用基类指针调用派生类的成员函数
    Hero *ptr = nullptr;

    if (id == 1)
    {
        ptr = new XS;
        // 创建派生类对象后,注册它的成员函数,注册回调函数;
        ptr->message = "西施";
        ptr->callback(&XS::show, static_cast<XS *>(ptr));
    }
    else if (id == 2)
    {
        ptr = new HX;
        // 创建派生类对象后,注册它的成员函数,注册回调函数;
        ptr->message = "韩信";
        ptr->callback(&HX::show, static_cast<HX *>(ptr));
    }

    if (nullptr != ptr)
    {
        ptr->show();
        delete ptr;
    }
}
