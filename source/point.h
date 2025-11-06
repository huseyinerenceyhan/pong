#ifndef POINT_H
#define POINT_H
enum corners{
	TOP_LEFT,
	BOTTOM_LEFT,
	TOP_RIGHT,
	BOTTOM_RIGHT,
};


typedef struct{
	float x;
	float y;
}ALIGN(4) point;

point *create_point(float x, float y);
void destroy_point(point **point);



#endif //POINT_H
