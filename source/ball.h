#ifndef BALL_H
#define BALL_H
#include "point.h"
#include "vector.h"

typedef struct{
	
point *coordinate;
point corners[4];
OBJ_ATTR *sprite;

}ALIGN(4)ball;


ball *create_ball(float x, float y, OBJ_ATTR **sprite);

void move_ball(ball *b, vector *v);
void update_corners_ball(ball *b);

void destroy_ball(ball **ball);




#endif //BALL_H
