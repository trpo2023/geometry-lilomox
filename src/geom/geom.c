#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeom/areanperim.h>
#include <libgeom/checknput.h>

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

    int tmp1 = check_and_put(arr1, out1, 1, strlen(arr1));
    int tmp2 = check_and_put(arr2, out2, 2, strlen(arr2));
    int tmp3 = check_and_put(arr3, out3, 3, strlen(arr3));

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

    fclose(file);
    return 0;
}
