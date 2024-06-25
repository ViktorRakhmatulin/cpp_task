#ifndef UTILITIES_H
#define UTILITIES_H

#include "point.h"
#include <vector>

double calculate_travel_time(const Point& a, const Point& b, double speed = 2.0);
bool read_point(double& x, double& y, int& penalty);
std::vector<Point> read_points(int N);

std::vector<Point> generate_random_points(int n);

#endif 