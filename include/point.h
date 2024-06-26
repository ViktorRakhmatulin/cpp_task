#ifndef POINT_H
#define POINT_H

struct Point {
    double x;
    double y;
    int penalty;

    Point(double x, double y, int penalty) : x(x), y(y), penalty(penalty) {}
};

#endif 
