#ifndef BALL_H
#define BALL_H
//#include <tonc.lib>

typedef struct{
	
float x;
float y;
float center;
int radius;
OBJ_ATTR *sprite;


	
} ball;


ball create_ball(float x, float y,int radius,OBJ_ATTR **sprite){
	ball *retval = malloc(sizeof(retval));
	retval->x = x;
	retval->y = y;
	retval->radius = radius;
	retval->center = (float)((x+y)/2)
	retval->sprite = *sprite;
	return retval;
}

void destroy_ball(ball **b){
	if(ball==NULL){
		return NULL;
	}
	
	free(*player);
	*player = NULL;
	
	
}




#endif //BALL_H