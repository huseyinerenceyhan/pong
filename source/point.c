#include <tonc.h>
#include <stdlib.h>
#include "point.h"
#include "printdebug.h"




point *create_point(float x, float y){
	point *retval =malloc(sizeof(point));
	retval->x = x;
	retval->y = y;
	
	return retval;
	
	
}
void destroy_point(point **point){
	
	if(*point==NULL){
		return;
	}
	
	free(*point);
	*point = NULL;
	
	
	
}
