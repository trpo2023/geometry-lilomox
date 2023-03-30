#include <libgeom/areanperim.h>
#include <math.h>

double get_area(double x)
{
    return M_PI * x * x;
}

double get_perim(double x)
{
    return M_PI * 2 * x;
}
