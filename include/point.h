#ifndef POINT_H
#define POINT_H

struct Point {
    double x;
    double y;
    int penalty;

    Point(double x, double y, int penalty);
};

#endif // POINT_H
