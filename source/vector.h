#ifndef VECTOR_H
#define VECTOR_H
#include <tonc.h>

typedef struct{
	float x;
	float y;
}ALIGN(4) vector;

void multiply_vector(vector *v, float val);

void flip_vector_x(vector *v);

void flip_vector_y(vector *v);

vector *create_vector(float x, float y);



#endif //VECTOR_H
