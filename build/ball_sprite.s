
@{{BLOCK(ball_sprite)

@=======================================================================
@
@	ball_sprite, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2025-11-03, 10:22:35
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ball_spriteTiles		@ 32 unsigned chars
	.hidden ball_spriteTiles
ball_spriteTiles:
	.word 0x00111100,0x01111110,0x11111111,0x11111111,0x11111111,0x11111111,0x01111110,0x00111100

	.section .rodata
	.align	2
	.global ball_spritePal		@ 32 unsigned chars
	.hidden ball_spritePal
ball_spritePal:
	.hword 0x0000,0x13E0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421

@}}BLOCK(ball_sprite)
