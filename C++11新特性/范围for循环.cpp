// for (decl:coll)
//  {
//      statement
//  }
// for (auto _pos = coll.begin(), _end = coll.end(); _pos != _end;++_pos)
// {
//     decl = *_pos;
//     statement;
// }
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for (int i : {1, 2, 3, 4, 5, 6, 7, 8})
    {
        cout << i << " ";
    }
    cout << endl;

    vector<double> vec{1.0, 2.0, 3.0, 4.0};

    for (auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;

    // for (auto elem : vec)
    // {
    //     elem *= 3;
    // }
}