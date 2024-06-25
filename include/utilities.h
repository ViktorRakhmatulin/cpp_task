#ifndef UTILITIES_H
#define UTILITIES_H

#include "point.h"
#include <vector>

double calculate_travel_time(const Point& a, const Point& b, double speed = 2.0);
double dynamic_programming(const std::vector<Point>& points);
double dijkstra(const std::vector<Point>& points);
std::vector<Point> generate_random_points(int n);

#endif // UTILITIES_H
