#include <tonc.h>
#include "printdebug.h"
#include "player.h"
#include "player_sprite.h"
#include "ai_sprite.h"
#include "ball_sprite.h"
#include <string.h>
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


void move_player(player *p){
	
	if(key_held(KEY_UP)){
		p->speed += p->acc;
		if(p->speed > p->cap){
			p->speed = p->cap;
		}
		p->y -= p->speed;
		u16 new_attr2_value = ATTR2_ID(2);
		p->sprite->attr2 = (p->sprite->attr2 & ~ATTR2_ID_MASK) | new_attr2_value;
		
	}
	else if(key_held(KEY_DOWN)){
		p->speed += p->acc;
		if(p->speed > p->cap){
			p->speed = p->cap;
		}
		p->y += p->speed;
		
		u16 new_attr2_value = ATTR2_ID(0);
		p->sprite->attr2 = (p->sprite->attr2 & ~ATTR2_ID_MASK) | new_attr2_value;
		
	}
	else if(p->speed>0){
		p->speed -= p->dec;
	}
	
	
	//CHECKING OUT OF BOUNDS
	// 16 is sprite size
	if(p->y<0){
		p->y=0;
	}
	else if((p->y+16)>160){
		p->y=144;
	}
	
	
	
	obj_set_pos(p->sprite, p->x, p->y);
	
	
	
}

void game(){
	
	u32 p_tid= 0, p_pb= 0;
	OBJ_ATTR *sprite_p= &obj_buffer[0];
	obj_set_attr(sprite_p,
	ATTR0_TALL,				
	ATTR1_SIZE_8x16,					
	ATTR2_PALBANK(p_pb) | p_tid);		
	//player *p = create_player(p_x,p_y,p_speed,p_acc,p_dec,p_cap,&sprite_p);
	player *p = create_player(10,80,0,(float)1/4,(float)1/16,2,&sprite_p);
	obj_set_pos(p->sprite,p->x,p->y);
	
	int a_x= 222, a_y= 0;
	int b_x= 120, b_y= 80;
	
	int b_speed_x=-2;
	float b_speed=0;

	
			// tile id, pal-bank
	u32 a_tid= 4, a_pb= 1;
	u32 b_tid= 6, b_pb= 2;

	
	OBJ_ATTR *ai= &obj_buffer[1];
	OBJ_ATTR *ball= &obj_buffer[2];
	

		
		obj_set_attr(ai,
		ATTR0_TALL,				
		ATTR1_SIZE_8x16,					
		ATTR2_PALBANK(a_pb) | a_tid);		
		obj_set_pos(ai,a_x,a_y);
		
		obj_set_attr(ball,
		ATTR0_SQUARE,				
		ATTR1_SIZE_8,					
		ATTR2_PALBANK(b_pb) | b_tid);		
		obj_set_pos(ball,b_x,b_y);
		oam_copy(oam_mem, obj_buffer, 3);	
		
	while(1){
		VBlankIntrWait();
		key_poll();
		move_player(p);
		
		oam_copy(oam_mem, obj_buffer, 3);
	}
}

int main(void){
	//	COPY-PASTE DON'T KNOW INTERRUPTS YET
	irq_init(NULL);
	irq_add(II_VBLANK, NULL);

	oam_init(obj_buffer, 128);

	REG_DISPCNT =  DCNT_OBJ | DCNT_OBJ_1D;// 0001000001000000

	init_sprites();
	

	game();


	
	return 0;
}