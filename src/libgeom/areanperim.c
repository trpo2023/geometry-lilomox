#include <libgeom/areanperim.h>
#include <math.h>

double garea(double x)
{
    return M_PI * x * x;
}

double gperim(double x)
{
    return M_PI * (double)2 * x;
}

