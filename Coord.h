#pragma once
#include <cmath>
#include <vector>

struct Point
{
    double x, y;
};

struct Vector
{
    double x, y;
};

double distance(const Point &p1, const Point &p2);

struct Triangle
{
    Point A, B, C;

    double area() const;
    double areaVector() const;

    bool contains(const Point &P) const
    {
        Triangle T1 = {A, B, P};
        Triangle T2 = {B, C, P};
        Triangle T3 = {C, A, P};

        double S_main = area();
        double S_sum = T1.area() + T2.area() + T3.area();

        return fabs(S_main - S_sum) < 1e-9;
    }

    bool containsVector(const Point &P) const
    {
        Triangle T1 = {A, B, P};
        Triangle T2 = {B, C, P};
        Triangle T3 = {C, A, P};

        double S_main = areaVector();
        double S_sum = T1.areaVector() + T2.areaVector() + T3.areaVector();

        return fabs(S_main - S_sum) < 1e-9;
    }

    bool degenerate() const;

    bool containsDegenerate(const Point &P) const
    {
        if(distance(A, P) + distance(P, B) == distance(A, B))
            return 1;
        else if(distance(A, P) + distance(P, C) == distance(A, C))
            return 1;
        else if(distance(C, P) + distance(P, B) == distance(C, B))
            return 1;
        else
            return 0;
    }
};

double heronArea(const Triangle &t);
double vectorArea(const Triangle &t);

void inputTriangle(Triangle &t);
void inputPoints(std::vector<Point> &p);