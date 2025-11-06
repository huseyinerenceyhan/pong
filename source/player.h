#ifndef PLAYER_H
#define PLAYER_H
#include "point.h"

typedef struct{

point *coordinate;
point *collidable_top;

float speed;
float acc;
float dec;
float cap;
int score;

OBJ_ATTR *sprite;
point corners[4];
}ALIGN(4) player;

player *create_player(float x, float y, float speed, float speed_acc, float speed_dec, float speed_cap, OBJ_ATTR **sprite);

void update_collision_points(player *p);


void update_corners_player(player *b);

void destroy_player(player **player);




#endif //PLAYER_H 
