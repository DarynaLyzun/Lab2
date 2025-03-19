#include <iostream>
#include <vector>
#include "Coord.h"
using namespace std;

int main()
{
    Triangle t = {};
    vector<Point> p;
    input(t, p);

    if (t.degenerate())
    {
        cout << "\nТрикутник вироджений" << endl;

        for (int i = 0; i < p.size(); i++)
        {
            if (t.containsDegenerate(p[i]))
                cout << "\nТочка №" << i + 1 << " належить трикутнику і лежить на його межі" << endl;
            else
                cout << "\nТочка №" << i + 1 << " не належить трикутнику" << endl;
        }
    }  
    else
    {
        cout << "\nТрикутник не вироджений" << endl;

        for (int i = 0; i < p.size(); i++)
        {
            if (t.contains(p[i]))
                cout << "\nТочка №" << i + 1 << " належить трикутнику" << endl;
            else
             cout << "\nТочка №" << i + 1 << " не належить трикутнику" << endl;

            if (t.containsVector(p[i]))
                cout << "\nТочка №" << i + 1 << " належить трикутнику" << endl;
            else
                cout << "\nТочка №" << i + 1 << " не належить трикутнику" << endl;

            if (t.containsDegenerate(p[i]))
                cout << "\nТочка №" << i + 1 << " лежить на межі трикутника" << endl;
            else
                cout << "\nТочка №" << i + 1 << " не лежить на межі трикутника" << endl;
        }
    }

    return 0;
}