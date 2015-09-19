#include <math.h>
#ifndef _geometry_
#define _geometry_
//geometry

class point2d
{
protected:
	float x,y;
public:
	point2d(float _x = 0, float _y = 0) {x=_x;y=_y;};
	~point2d() {};

	point2d shift_radial(float radius,float angle) {return point2d(x+cos(angle)*radius,y+sin(angle)*radius);};
	point2d shift_linear(float _x,float _y)        {return point2d(x+_x,y+_y);};
	float get_x() {return x;};
	void  set_x(float _x = 0) {x=_x;};
	float get_y() {return y;};
	void  set_y(float _y = 0) {y=_y;};
};

class point3d : public point2d
{
protected:
	float z;
public:
	point3d(float _x = 0, float _y = 0, float _z = 0) {x=_x;y=_y;z=_z;};
	~point3d() {};

	point3d shift_radial_h(float radius,float angle)        {return point3d(x+cos(angle)*radius,y+sin(angle)*radius,z);};
	point3d shift_radial_v(float radius,float angle)        {return point3d(x+cos(angle)*radius,y,z+sin(angle)*radius);};
	point3d shift_sphere(float radius,float angle_h,float angle_v)
															{return point3d(x+cos(angle_h)*sin(angle_v)*radius,y+sin(angle_h)*sin(angle_v)*radius,z+cos(angle_v));};
	point3d shift_linear(float _x,float _y,float _z)        {return point3d(x+_x,y+_y,z+_z);};
	float get_z() {return z;};
	void  set_z(float _z = 0) {z=_z;};
};

#endif
