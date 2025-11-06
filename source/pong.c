#include <tonc.h>
#include "printdebug.h"
#include "point.h"
#include "player.h"
#include "ball.h"
#include "player_sprite.h"
#include "ai_sprite.h"
#include "vector.h"
#include "ball_sprite.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

OBJ_ATTR obj_buffer[128];


/* I CAN'T MIX MODES FOR NOW :(
// I GUESS ITS NOT POSSIBLE??

void draw_mid_line(){
	for(int y=2; y<=SCREEN_HEIGHT;y+=10)
    {
		// Line is 1 pixels wide, 5 pixels tall
        m3_line(120, y, SCREEN_WIDTH/2, y+5, CLR_WHITE);	
    }
}
*/

void init_sprites(){
	memcpy32(&tile_mem[4][0], player_spriteTiles, player_spriteTilesLen/ sizeof(u32));
	memcpy16(&pal_obj_mem[0], player_spritePal, player_spritePalLen/ sizeof(u16));


	memcpy32(&tile_mem[4][4], ai_spriteTiles, ai_spriteTilesLen/ sizeof(u32));
	memcpy16(&pal_obj_mem[16 * 1], ai_spritePal, ai_spritePalLen);

	
	memcpy32(&tile_mem[4][6], ball_spriteTiles, ball_spriteTilesLen/ sizeof(u32));
	memcpy16(&pal_obj_mem[16 * 2], ball_spritePal, ball_spritePalLen/ sizeof(u16));
}

void move_human(player *p){
	
	if(key_held(KEY_UP)){
		p->speed += p->acc;
		if(p->speed > p->cap){
			p->speed = p->cap;
		}
		p->coordinate->y -= p->speed;
		u16 new_attr2_value = ATTR2_ID(2);
		p->sprite->attr2 = (p->sprite->attr2 & ~ATTR2_ID_MASK) | new_attr2_value;
		
	}
	else if(key_held(KEY_DOWN)){
		p->speed += p->acc;
		if(p->speed > p->cap){
			p->speed = p->cap;
		}
		p->coordinate->y += p->speed;
		
		u16 new_attr2_value = ATTR2_ID(0);
		p->sprite->attr2 = (p->sprite->attr2 & ~ATTR2_ID_MASK) | new_attr2_value;
		
	}
	else if(p->speed>0){
		p->speed -= p->dec;
	}
	
	
	//CHECKING OUT OF BOUNDS
	// 16 is sprite size
	if(p->coordinate->y<0){
		p->coordinate->y=0;
	}
	else if((p->coordinate->y+16)>160){
		p->coordinate->y=144;
	}
	
	
	
	obj_set_pos(p->sprite, p->coordinate->x, p->coordinate->y);
	
	
	
}
void move_ai(player *p, ball *b){
	
	if(b->corners[BOTTOM_RIGHT].y <= p->corners[TOP_LEFT].y){
		p->speed += p->acc;
		if(p->speed > p->cap){
			p->speed = p->cap;
		}
		p->coordinate->y -= p->speed;
		
	}
	else if(b->corners[TOP_RIGHT].y >= p->corners[BOTTOM_LEFT].y){
		p->speed += p->acc;
		if(p->speed > p->cap){
			p->speed = p->cap;
		}
		
		p->coordinate->y += p->speed;
		
	}
	else if(b->corners[TOP_RIGHT].y >= p->corners[TOP_RIGHT].y && b->corners[BOTTOM_RIGHT].y <= p->corners[BOTTOM_RIGHT].y ){
		p->speed -= p->dec;
	}
	
	
	//CHECKING OUT OF BOUNDS
	// 16 is sprite size
	if(p->coordinate->y<0){
		p->coordinate->y=0;
	}
	else if((p->coordinate->y+16)>160){
		p->coordinate->y=144;
	}
	
	
	
	obj_set_pos(p->sprite, p->coordinate->x, p->coordinate->y);
	
	
	
}

void move_ball(ball *b, vector *v){
	//TOP BORDER CHECK
	if(b->coordinate->y < 0){
		v->y *= -1;
	}
	//BOTTOM BORDER CHECK
	else if((b->coordinate->y+8	) > SCREEN_HEIGHT){
		v->y *= -1;
	}
	b->coordinate->x += v->x;
	b->coordinate->y += v->y;

	obj_set_pos(b->sprite, b->coordinate->x, b->coordinate->y);
	
}

void check_collision_human(ball *b, player *p, vector *v){

		// SAME X CHECK
	if(p->corners[TOP_RIGHT].x == b->corners[TOP_LEFT].x){
		
	}
	else{
		return;
	}
	
	
	if(b->corners[TOP_LEFT].y <= p->corners[TOP_RIGHT].y && b->corners[BOTTOM_LEFT].y >= p->corners[TOP_RIGHT].y ){
		//partial top
	}
	else if(b->corners[TOP_LEFT].y >= p->corners[TOP_RIGHT].y && b->corners[BOTTOM_LEFT].y <= p->corners[BOTTOM_RIGHT].y){
		//middle
	}
	else if(b->corners[TOP_LEFT].y <= p->corners[BOTTOM_RIGHT].y && b->corners[BOTTOM_LEFT].y >= p->corners[BOTTOM_RIGHT].y){
		//partial down
	}
	else{
		return;
	}
	
	v->x *= -1; 



}


void check_collision_ai(ball *b, player *p, vector *v){

		// SAME X CHECK
	if(p->corners[TOP_LEFT].x == b->corners[TOP_RIGHT].x){
		
	}
	else{
		return;
	}
	
	
	if(b->corners[TOP_RIGHT].y <= p->corners[TOP_LEFT].y && b->corners[BOTTOM_RIGHT].y >= p->corners[TOP_LEFT].y ){
		//partial top
	}
	else if(b->corners[TOP_RIGHT].y >= p->corners[TOP_LEFT].y && b->corners[BOTTOM_RIGHT].y <= p->corners[BOTTOM_LEFT].y){
		//middle
	}
	else if(b->corners[TOP_RIGHT].y <= p->corners[BOTTOM_LEFT].y && b->corners[BOTTOM_RIGHT].y >= p->corners[BOTTOM_LEFT].y){
		//partial down
	}
	else{
		return;
	}
	
	v->x *= -1; 





}

void goal_check(ball *b, vector *v){
	
	float r = rand()>>30;

	if(b->coordinate->x > 240){
		
		b->coordinate->x =120;
		b->coordinate->y =(float)((rand()%100)+20);
	
		if(r==0){
			v->y = 1;
		}
		else{
			v->y = -1;
		}
		
		obj_set_pos(b->sprite,b->coordinate->x,b->coordinate->y);
		print("\nPLAYER SCORED\n");
		return;
	}
	
	if(b->coordinate->x < 0){
		
	
		b->coordinate->x =120;
		b->coordinate->y =(float)((rand()%80)+30);
	

		if(r==0){
			v->y = 1;
		}
		else{
			v->y = -1;
		}
			
		obj_set_pos(b->sprite,b->coordinate->x,b->coordinate->y);
		print("\nAI SCORED\n");
		return;
	}
	
}


void game(){
	// INIT PLAYER
	float x = 10, y = 80;
	float speed = 0, cap=2;
	float acc = (float) 4/16;
	float dec = (float) 1/16;
	u32 tid= 0, pb= 0;
	OBJ_ATTR *sprite= &obj_buffer[0];
	obj_set_attr(sprite,ATTR0_TALL,ATTR1_SIZE_8x16,ATTR2_PALBANK(pb) | tid);		
	player *p = create_player(x,y,speed,acc,dec,cap,&sprite);
	obj_set_pos(p->sprite,p->coordinate->x,p->coordinate->x);
	
	// INIT AI
	x = 222;
	y = 80;
	cap = 1;
	tid = 4;
	pb = 1;
	sprite = &obj_buffer[1];
	obj_set_attr(sprite,ATTR0_TALL,ATTR1_SIZE_8x16,ATTR2_PALBANK(pb) | tid);
	player *a = create_player(x,y,speed,acc,dec,cap,&sprite);
	obj_set_pos(a->sprite,a->coordinate->x,a->coordinate->y);
	
	// INIT BALL
	x= 120, y= 80;
	speed=0;
	tid= 6, pb= 2;
	sprite = &obj_buffer[2];
	obj_set_attr(sprite,ATTR0_SQUARE,ATTR1_SIZE_8,ATTR2_PALBANK(pb) | tid);		
	ball *b = create_ball(x,y,&sprite);
	obj_set_pos(b->sprite,b->coordinate->x,b->coordinate->y);
	
	vector *ball_speed = create_vector(-2,1);

	oam_copy(oam_mem, obj_buffer, 3);
	
	while(1){
		VBlankIntrWait();
		key_poll();
		move_human(p);
		update_corners_player(p);
		move_ball(b,ball_speed);
		update_corners_ball(b);
		move_ai(a,b);
		update_corners_player(a);
		check_collision_human(b,p,ball_speed);
		check_collision_ai(b,a,ball_speed);
		goal_check(b,ball_speed);
		
		
		oam_copy(oam_mem, obj_buffer, 3);
	}
}

int main(void){
	//	COPY-PASTE DON'T KNOW INTERRUPTS YET
	irq_init(NULL);
	irq_add(II_VBLANK, NULL);

	oam_init(obj_buffer, 128);

	REG_DISPCNT =  DCNT_OBJ | DCNT_OBJ_1D|DCNT_MODE2;// 0001000001000000

	init_sprites();
	srand(time(NULL));

	game();


	
	return 0;
}
