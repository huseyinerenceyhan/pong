#include <tonc.h>
#include <stdlib.h>
#include "player.h"
#include "point.h"
#include "printdebug.h"



player *create_player(float x, float y, float speed, float speed_acc, float speed_dec, float speed_cap, OBJ_ATTR **sprite){
	player *retval = malloc(sizeof(player));
	
	if(retval == NULL){
		print("ERROR in create_player()");
		return NULL;
	}
	retval->coordinate = create_point(x,y);
	retval->speed = speed;
	retval->acc = speed_acc;
	retval->dec = speed_dec;
	retval->cap = speed_cap;
	retval->sprite = *sprite;

	retval->corners[TOP_LEFT] = *create_point(x,y);//top left
	retval->corners[BOTTOM_LEFT] = *create_point(x,y+16);//bottom left
	retval->corners[TOP_RIGHT] = *create_point(x+8,y);//top right
	retval->corners[BOTTOM_RIGHT] = *create_point(x+8,y+16);//bottom right
	

	retval->score = 0;
	
	return retval;
};

void update_corners_player(player *p){
	p->corners[TOP_LEFT].y = p->coordinate->y;
	p->corners[BOTTOM_LEFT].y = p->coordinate->y+16;
	p->corners[TOP_RIGHT].y = p->coordinate->y;
	p->corners[BOTTOM_RIGHT].y = p->coordinate->y+16;
	

	
}

void destroy_player(player **player){
	if(*player == NULL){
		return;
	}
	destroy_point(&((*player)->coordinate));
	free(*player);
	*player = NULL;
	
};
