#include "vector.h"
#include "printdebug.h"
#include <stdlib.h>
void multiply_vector(vector *v, float val){
	v->x *= val;
	v->y *= val;
};

void flip_vector_x(vector *v){
	v->x *= -1;
};

void flip_vector_y(vector *v){
	v->y *= -1;
};

vector *create_vector(float x, float y){
	vector *retval = malloc(sizeof(vector));
	if(retval == NULL){
		print("ERROR in create_vector()");
		return NULL;
	}
	retval->x = x;
	retval->y = y;
	
	return retval;
};
