#include <tonc.h>
#include <stdlib.h>
#include "ball.h"
#include "point.h"
#include "vector.h"
#include "printdebug.h"

ball *create_ball(float x, float y, OBJ_ATTR **sprite){
	ball *retval = malloc(sizeof(ball));
	if(retval == NULL){
		print("ERROR in create_ball()");
		return NULL;
	}
	retval->coordinate = create_point(x,y);
	
	retval->corners[0] = *create_point(x,y);//top left
	retval->corners[1] = *create_point(x,y+8);//bottom left
	retval->corners[2] = *create_point(x+8,y);//top right
	retval->corners[3] = *create_point(x+8,y+8);//bottom left	
	

	retval->sprite = *sprite;
	return retval;
};


void update_corners_ball(ball *b){
	b->corners[TOP_LEFT].y = b->coordinate->y;
	b->corners[TOP_LEFT].x = b->coordinate->x;
	
	b->corners[BOTTOM_LEFT].y = b->coordinate->y+8;
	b->corners[BOTTOM_LEFT].x = b->coordinate->x;
	
	b->corners[TOP_RIGHT].y = b->coordinate->y;
	b->corners[TOP_RIGHT].x = b->coordinate->x+8;
	
	b->corners[BOTTOM_RIGHT].y = b->coordinate->y+8;
	b->corners[BOTTOM_RIGHT].x = b->coordinate->x+8;
	

	
	
	
	
	
}



void destroy_ball(ball **ball){
	if(ball==NULL){
		return;
	}
	destroy_point(&((*ball)->coordinate));
	free(*ball);
	*ball = NULL;
	
	
};
