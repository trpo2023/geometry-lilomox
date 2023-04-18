#include <ctest.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <libgeom/areanperim.h>
#include <libgeom/checknput.h>
#include <libgeom/intersection_of_circles.h>

CTEST(checknput, char_vector_new) 
{
	CharVector *new1 = char_vector_new(12);
	CharVector *new2 = char_vector_new(12);
	CharVector *new3 = char_vector_new(12);
	CharVector *new4 = char_vector_new(12);
	CharVector *new5 = char_vector_new(12);

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

