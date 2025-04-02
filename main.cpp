#include <iostream>
#include <vector>
#include "Coord.h"
using namespace std;

int main()
{
    Triangle t = {};
    vector<Point> p;
    inputTriangle(t);
    inputPoints(p);

    int cont = 1;

    do
    {
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
                    cout << "\nТочка №" << i + 1 << " належить трикутнику (методом площ)" << endl;
                else
                 cout << "\nТочка №" << i + 1 << " не належить трикутнику (методом площ)" << endl;

                if (t.containsVector(p[i]))
                    cout << "\nТочка №" << i + 1 << " належить трикутнику (методом векторного добутку)" << endl;
                else
                    cout << "\nТочка №" << i + 1 << " не належить трикутнику (методом векторного добутку)" << endl;

                if (t.containsDegenerate(p[i]))
                    cout << "\nТочка №" << i + 1 << " лежить на межі трикутника" << endl;
                else
                    cout << "\nТочка №" << i + 1 << " не лежить на межі трикутника" << endl;
            }
        }

        cout << endl << "Що далі?" << endl;
        cout << "1. Задати нові точки." << endl;
        cout << "2. Задати новий трикутник і нові точки." << endl;
        cout << "3. Вийти з програми." << endl;
        
        int op = 0;
        while (!(cin >> op) || op < 1 || op > 3 || getchar() != '\n')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nНекоректний ввід. Спробуйте знову: ";
        }

        switch (op)
        {
            case 1:
                p.clear();
                inputPoints(p);
                break;
            case 2:
                p.clear();
                inputPoints(p);
                inputTriangle(t);
                break;
            case 3:
                cont = 0;
                break;
        }
    } while(cont == 1);

    return 0;
}