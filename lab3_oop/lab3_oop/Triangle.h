#pragma once
#include <math.h>
#include "Shape.h"
using namespace std;
class Triangle : public Shape
{
private:

	double x, y;

	double getArea() ;

	double getPerimetr() ;

	void center_of_gravity() ;

public:

	Triangle(Point *pt);

	void Rotate(double rotation_angle);

	void Move(double move_x, double move_y);

	std::string info() ;

	~Triangle();
};