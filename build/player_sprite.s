
@{{BLOCK(player_sprite)

@=======================================================================
@
@	player_sprite, 8x32@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-11-03, 10:22:35
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global player_spriteTiles		@ 128 unsigned chars
	.hidden player_spriteTiles
player_spriteTiles:
	.word 0x11111111,0x11111111,0x11111111,0x44411444,0x22411224,0x22411224,0x11111111,0x11111111
	.word 0x12222221,0x12222221,0x11222211,0x11122111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x22411224,0x22411224,0x44411444,0x11111111,0x11111111
	.word 0x12222221,0x12222221,0x11222211,0x11122111,0x11111111,0x11111111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global player_spritePal		@ 32 unsigned chars
	.hidden player_spritePal
player_spritePal:
	.hword 0x0000,0x00BF,0x7FFF,0x0000,0x294A,0x0000,0x0000,0x0000
	.hword 0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421

@}}BLOCK(player_sprite)
