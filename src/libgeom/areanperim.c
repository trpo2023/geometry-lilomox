#include <libgeom/areanperim.h>
#include <math.h>
#include <stdlib.h>

double garea(double x)
{
    return M_PI * x * x;
}

double gperim(double x)
{
    return M_PI * 2 * x;
}

