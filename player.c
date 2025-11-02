#include <tonc.h>
#include <stdlib.h>
#include "player.h"
#include "printdebug.h"



player *create_player(float x, float y, float speed, float speed_acc, float speed_dec, float speed_cap, OBJ_ATTR **sprite){
	player *retval = malloc(sizeof(player));
	
	if(retval == NULL){
		print("ERROR in create_player()");
		return NULL;
	}
	
	retval->x = x;
	retval->y = y;
	retval->speed = speed;
	retval->acc = speed_acc;
	retval->dec = speed_dec;
	retval->cap = speed_cap;
	retval->sprite = *sprite;
	retval->score = 0;
	
	return retval;
};

void destroy_player(player **player){
	if(*player == NULL){
		return;
	}
	
	free(*player);
	*player = NULL;
	
};