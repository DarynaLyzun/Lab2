#include <iostream>
#include "Coord.h"
using namespace std;

double distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle &t)
{
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double vectorArea(const Triangle &t)
{
    Vector a = {t.B.x - t.A.x, t.B.y - t.A.y};
    Vector b = {t.C.x - t.A.x, t.C.y - t.A.y};
    return 0.5 * fabs(a.x * b.y - a.y * b.x);
}

double Triangle::area() const
{
    return heronArea(*this);
}

double Triangle::areaVector() const
{
    return vectorArea(*this);
}

bool Triangle::degenerate() const
{
    return area() == 0;
}

void input(Triangle &t, vector<Point> &p)
{
    cout << "Введіть координати вершин трикутника.\n" << "Перша вершина: ";
    while (!(cin >> t.A.x >> t.A.y) || getchar() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nНекоректний ввід. Спробуйте знову: ";
    }

    cout << "Друга вершина: ";
    while (!(cin >> t.B.x >> t.B.y) || getchar() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nНекоректний ввід. Спробуйте знову: ";
    }

    cout << "Третя вершина: ";
    while (!(cin >> t.C.x >> t.C.y) || getchar() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nНекоректний ввід. Спробуйте знову: ";
    }

    int n = 0;
    cout << "\nСкільки точок ви хочете перевірити? ";
    while (!(cin >> n) || getchar() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nНекоректний ввід. Спробуйте знову: ";
    }

    Point point = {};

    for (int i = 0; i < n; i++)
    {
        cout << "\nТепер введіть координати точки №" << i + 1 << ": ";
        while (!(cin >> point.x >> point.y) || getchar() != '\n')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nНекоректний ввід. Спробуйте знову: ";
        }
        p.push_back(point);
    }
}