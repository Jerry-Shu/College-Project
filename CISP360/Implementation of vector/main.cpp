#include "Vector.h"
using namespace Vector;

int main()
{
    vector vector1;
    vector1.push_back(8);
    vector1.push_back(7);
    vector1.push_back(6);
    vector1.push_back(5);
    vector1.push_back(4);
    vector1.push_back(3);
    vector1.push_back(2);
    vector1.push_back(1);
    vector1.push_back(0);
    cout << "vector inside: " << endl;
    for(int i = 0; i < vector1.size(); i++)
    {
        cout << vector1.get(i) << "  ";
    }
    cout << endl;
    cout << "size: " << vector1.size() << endl;
    cout << "space: " << vector1.capacity() << endl;
    return 0;
}

