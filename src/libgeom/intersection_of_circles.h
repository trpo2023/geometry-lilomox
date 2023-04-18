#pragma once

typedef struct Circle {
    double x;
    double y;
    double radius;
} Circle;

int intersection_of_circles(Circle* circle1, Circle* circle2);