#include <math.h>

#include <libgeom/areanperim.h>

double get_area(double x)
{
    return M_PI * x * x;
}

double get_perim(double x)
{
    return M_PI * 2 * x;
}
