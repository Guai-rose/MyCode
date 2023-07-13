#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    std::map<string, int> mp;
    string str = "test.py";
    mp["haha"] = 1;
    mp["test"] = 2;

    std::map<string, int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << "¼ü=" << itr->first << " Öµ=" << itr->second << endl;
    }
    cout << endl;

    auto iter = mp.find(str.assign(str.begin(), str.end() - 3));
    if (iter != mp.end())
    {
        mp.erase(iter);
    }
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << "¼ü=" << itr->first << " Öµ=" << itr->second << endl;
    }
}
// struct point
// {
//     friend ostream &operator<<(ostream &out, const point &obj)
//     {
//         out << "(" << obj.x << "," << obj.y << ")" << endl;
//         return out;
//     }
//     point(int x, int y) : x(x), y(y) {}
//     int x;
//     int y;
// };

// int main()
// {
//     std::vector<point> vp;

//     srand((unsigned int)time(NULL));

//     for (int i = 0; i < 50; i++)
//         vp.push_back(point(rand() % 100, rand() % 100));

//     cout << vp[0];

//     cout << vp.size();
// }
