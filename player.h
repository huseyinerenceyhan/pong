#ifndef PLAYER_H
#define PLAYER_H
#include <tonc.h>



typedef struct{

float x;
float y;
float speed;
float acc;
float dec;
float cap;
int score;

OBJ_ATTR *sprite; 


}player;

player *create_player(float x, float y, float speed, float speed_acc, float speed_dec, float speed_cap, OBJ_ATTR **sprite);

void destroy_player(player **player);




#endif //PLAYER_H 