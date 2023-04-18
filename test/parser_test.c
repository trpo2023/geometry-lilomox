#include <ctest.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <libgeom/areanperim.h>
#include <libgeom/checknput.h>
#include <libgeom/intersection_of_circles.h>

CTEST(checknput, char_vector_new)
{
    CharVector* new1 = char_vector_new(12);
    CharVector* new2 = char_vector_new(12);
    CharVector* new3 = char_vector_new(12);
    CharVector* new4 = char_vector_new(12);
    CharVector* new5 = char_vector_new(12);

    ASSERT_NOT_NULL(new1);
    ASSERT_NOT_NULL(new2);
    ASSERT_NOT_NULL(new3);
    ASSERT_NOT_NULL(new4);
    ASSERT_NOT_NULL(new5);

    char_vector_free(new1);
    char_vector_free(new2);
    char_vector_free(new3);
    char_vector_free(new4);
    char_vector_free(new5);
}

CTEST(checknput, char_vector_push_back)
{
    CharVector* new1 = char_vector_new(12);
    CharVector* new2 = char_vector_new(12);
    CharVector* new3 = char_vector_new(12);
    CharVector* new4 = char_vector_new(12);
    CharVector* new5 = char_vector_new(12);

    const int expected = 0;

    ASSERT_NOT_NULL(new1);
    ASSERT_NOT_NULL(new2);
    ASSERT_NOT_NULL(new3);
    ASSERT_NOT_NULL(new4);
    ASSERT_NOT_NULL(new5);

    int vector1 = char_vector_push_back(new1, 45);
    int vector2 = char_vector_push_back(new2, 101);
    int vector3 = char_vector_push_back(new3, 77);
    int vector4 = char_vector_push_back(new4, 88);
    int vector5 = char_vector_push_back(new5, 89);

    ASSERT_EQUAL(vector1, expected);
    ASSERT_EQUAL(vector2, expected);
    ASSERT_EQUAL(vector3, expected);
    ASSERT_EQUAL(vector4, expected);
    ASSERT_EQUAL(vector5, expected);

    char_vector_free(new1);
    char_vector_free(new2);
    char_vector_free(new3);
    char_vector_free(new4);
    char_vector_free(new5);
}

CTEST(checknput, check_syntax)
{
    char string1[] = "circle(12 2,1)\n";
    char string2[] = "circle(123 -200,   23)\n";
    char string3[] = "circle(-33 24,53)\n";
    char string4[] = "circle(1 0,1000)\n";
    char string5[] = "circle(123  -88, 8)\n";
    const int expected = 1;

    int str1 = check_syntax(string1, strlen(string1));
    int str2 = check_syntax(string2, strlen(string2));
    int str3 = check_syntax(string3, strlen(string3));
    int str4 = check_syntax(string4, strlen(string4));
    int str5 = check_syntax(string5, strlen(string5));

    ASSERT_EQUAL(str1, expected);
    ASSERT_EQUAL(str2, expected);
    ASSERT_EQUAL(str3, expected);
    ASSERT_EQUAL(str4, expected);
    ASSERT_EQUAL(str5, expected);
}

CTEST(checknput, string_to_number)
{
    char string1[] = "circle(12342 22,  109)\n";
    char string2[] = "circle(673 -23430,2)\n";
    char string3[] = "circle(-683 2324, 13)\n";
    char string4[] = "circle(13 958, 1003254)\n";
    char string5[] = "circle(12332 -838,  18)\n";
    double buf1[3], buf2[3], buf3[3], buf4[3], buf5[3];
    const int expected = 1;

    int str1 = string_to_number(string1, buf1, strlen(string1));
    int str2 = string_to_number(string2, buf2, strlen(string2));
    int str3 = string_to_number(string3, buf3, strlen(string3));
    int str4 = string_to_number(string4, buf4, strlen(string4));
    int str5 = string_to_number(string5, buf5, strlen(string5));

    ASSERT_EQUAL(str1, expected);
    ASSERT_EQUAL(str2, expected);
    ASSERT_EQUAL(str3, expected);
    ASSERT_EQUAL(str4, expected);
    ASSERT_EQUAL(str5, expected);
}

CTEST(areanperim, get_area)
{
    double x1 = 123;
    double x2 = 1000;
    double x3 = 9;
    double x4 = 45;
    double x5 = 88;

    const double expected1 = x1 * x1 * M_PI;
    const double expected2 = x2 * x2 * M_PI;
    const double expected3 = x3 * x3 * M_PI;
    const double expected4 = x4 * x4 * M_PI;
    const double expected5 = x5 * x5 * M_PI;

    x1 = get_area(x1);
    x2 = get_area(x2);
    x3 = get_area(x3);
    x4 = get_area(x4);
    x5 = get_area(x5);

    ASSERT_EQUAL(x1, expected1);
    ASSERT_EQUAL(x2, expected2);
    ASSERT_EQUAL(x3, expected3);
    ASSERT_EQUAL(x4, expected4);
    ASSERT_EQUAL(x5, expected5);
}

CTEST(areanperim, get_perim)
{
    double x1 = 15463;
    double x2 = 104350;
    double x3 = 2356546;
    double x4 = 3;
    double x5 = 12343;

    const double expected1 = x1 * 2 * M_PI;
    const double expected2 = x2 * 2 * M_PI;
    const double expected3 = x3 * 2 * M_PI;
    const double expected4 = x4 * 2 * M_PI;
    const double expected5 = x5 * 2 * M_PI;

    x1 = get_perim(x1);
    x2 = get_perim(x2);
    x3 = get_perim(x3);
    x4 = get_perim(x4);
    x5 = get_perim(x5);

    ASSERT_EQUAL(x1, expected1);
    ASSERT_EQUAL(x2, expected2);
    ASSERT_EQUAL(x3, expected3);
    ASSERT_EQUAL(x4, expected4);
    ASSERT_EQUAL(x5, expected5);
}

CTEST(intersection_of_circles, intersection_of_circles)
{
    Circle circle1 = {12, -1, 100};
    Circle circle2 = {8, 12, 1};
    Circle circle3 = {23, -1, 50};
    Circle circle4 = {0, 0, 23};
    Circle circle5 = {-2, -12, 46};

    const int expected = 1;

    int circ1 = intersection_of_circles(&circle1, &circle2);
    int circ2 = intersection_of_circles(&circle1, &circle3);
    int circ3 = intersection_of_circles(&circle1, &circle4);
    int circ4 = intersection_of_circles(&circle1, &circle5);
    int circ5 = intersection_of_circles(&circle4, &circle5);

    ASSERT_EQUAL(circ1, expected);
    ASSERT_EQUAL(circ2, expected);
    ASSERT_EQUAL(circ3, expected);
    ASSERT_EQUAL(circ4, expected);
    ASSERT_EQUAL(circ5, expected);
}