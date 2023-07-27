#include <math.h>
#include <stdlib.h>

#include <libgeom/intersection_of_circles.h>

int intersection_of_circles(Circle* circle1, Circle* circle2)
{
    double distance;
    double sum_of_radius = circle1->radius + circle2->radius;
    distance
            = pow(pow(fabs(circle1->x - circle2->x), 2)
                          + pow(fabs(circle1->y - circle2->y), 2),
                  0.5);
    if (distance < sum_of_radius) {
        return 1;
    } else {
        return 0;
    }
}