#include <libgeom/areanperim.h>
#include <libgeom/checknput.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "/home/maxim/geometry-lilomox/src/geom/geommi.txt"

int main()
{
    FILE* file;

    if (!(file = fopen(PATH, "r"))) {
        printf("can't open a file for reading\n");
        return -1;
    }

    char mass[100], darr[100], dd[100];

    fgets(mass, sizeof(mass), file);
    fgets(darr, sizeof(darr), file);
    fgets(dd, sizeof(dd), file);

    double out1[3], out2[3], out3[3];

    printf("%s", mass);
    check_and_put(mass, out1, 1);
    printf("area of 1st circle = %lf;    perimeter = %lf\n\n",
           garea(out1[2]),
           gperim(out1[2]));

    printf("%s", darr);
    check_and_put(darr, out2, 2);
    printf("area of 2nd circle = %lf;    perimeter = %lf\n\n",
           garea(out2[2]),
           gperim(out2[2]));

    printf("%s", dd);
    check_and_put(dd, out3, 3);
    printf("area of 3d circle = %lf;    perimeter = %lf\n\n",
           garea(out3[2]),
           gperim(out3[2]));

    fclose(file);
    return 0;
}
