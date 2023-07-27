#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeom/areanperim.h>
#include <libgeom/checknput.h>
#include <libgeom/intersection_of_circles.h>

int main()
{
    FILE* file;

    if (!(file = fopen("geommi.txt", "r"))) {
        printf("can't open a file for reading\n");
        return -1;
    }

    char arr1[100], arr2[100], arr3[100];

    fgets(arr1, sizeof(arr1), file);
    fgets(arr2, sizeof(arr2), file);
    fgets(arr3, sizeof(arr3), file);

    double out1[3], out2[3], out3[3];
    Circle circle1, circle2, circle3;

    int tmp1 = check_and_put(arr1, out1, 1, strlen(arr1));
    circle1.x = out1[0];
    circle1.y = out1[1];
    circle1.radius = out1[2];
    int tmp2 = check_and_put(arr2, out2, 2, strlen(arr2));
    circle2.x = out2[0];
    circle2.y = out2[1];
    circle2.radius = out2[2];
    int tmp3 = check_and_put(arr3, out3, 3, strlen(arr3));
    circle3.x = out3[0];
    circle3.y = out3[1];
    circle3.radius = out3[2];

    if (tmp1 + tmp2 + tmp3 == 3) {
        printf("%s", arr1);
        printf("area of 1 circle = %lf   perimeter = %lf\n\n",
               get_area(out1[2]),
               get_perim(out1[2]));
        printf("%s", arr2);
        printf("area of 2 circle = %lf   perimeter = %lf\n\n",
               get_area(out2[2]),
               get_perim(out2[2]));
        printf("%s", arr3);
        printf("area of 3 circle = %lf   perimeter = %lf\n\n",
               get_area(out3[2]),
               get_perim(out3[2]));
    }

    if (intersection_of_circles(&circle1, &circle2) == 1) {
        printf("Circles 1 and 2 intersect\n");
    } else {
        printf("Circles 1 and 2 DON'T intersect\n");
    }

    if (intersection_of_circles(&circle1, &circle3) == 1) {
        printf("Circles 1 and 3 intersect\n");
    } else {
        printf("Circles 1 and 3 DON'T intersect\n");
    }

    if (intersection_of_circles(&circle2, &circle3) == 1) {
        printf("Circles 2 and 3 intersect\n");
    } else {
        printf("Circles 2 and 3 DON'T intersect\n");
    }

    fclose(file);
    return 0;
}
