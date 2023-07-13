#include <iostream>
#include <list>
using namespace std;

class abstractHero
{
public:
    virtual void update() = 0;
};
class HeroA : public abstractHero
{
public:
    HeroA()
    {
        cout << "A  fighting!!" << endl;
    }
    virtual void update()
    {
        cout << "A  STOP!!!,Waiting" << endl;
    }
};
class HeroB : public abstractHero
{
public:
    HeroB()
    {
        cout << "B  fighting!!" << endl;
    }
    virtual void update()
    {
        cout << "B  STOP!!!,Waiting" << endl;
    }
};
class HeroC : public abstractHero
{
public:
    HeroC()
    {
        cout << "C  fighting!!" << endl;
    }
    virtual void update()
    {
        cout << "C  STOP!!!,Waiting" << endl;
    }
};
class HeroD : public abstractHero
{
public:
    HeroD()
    {
        cout << "D  fighting!!" << endl;
    }
    virtual void update()
    {
        cout << "D  STOP!!!,Waiting" << endl;
    }
};
class HeroE : public abstractHero
{
public:
    HeroE()
    {
        cout << "E  fighting!!" << endl;
    }
    virtual void update()
    {
        cout << "E  STOP!!!,Waiting" << endl;
    }
};

class abstractMonster
{
public:
    virtual void addHero(abstractHero *hero) = 0;
    virtual void deleteHero(abstractHero *hero) = 0;
    virtual void notify() = 0;
};
class MosterA : public abstractMonster
{
    virtual void addHero(abstractHero *hero)
    {
        herolist.push_back(hero);
    }
    virtual void deleteHero(abstractHero *hero)
    {
        herolist.remove(hero);
    }
    virtual void notify()
    {
        for (auto i : herolist)
        {
            i->update();
        }
    }

public:
    list<abstractHero *> herolist;
};

void test()
{
    abstractHero *heroA = new HeroA;
    abstractHero *heroB = new HeroB;
    abstractHero *heroC = new HeroC;
    abstractHero *heroD = new HeroD;
    abstractHero *heroE = new HeroE;

    abstractMonster *bossA = new MosterA;
    bossA->addHero(heroA);
    bossA->addHero(heroB);
    bossA->addHero(heroC);
    bossA->addHero(heroD);
    bossA->addHero(heroE);

    cout << "heroC die" << endl;
    bossA->deleteHero(heroC);

    cout << "boss die" << endl;

    bossA->notify();
}
int main()
{
    test();
    return 0;
}