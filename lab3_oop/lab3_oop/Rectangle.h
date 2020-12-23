#pragma once
#include <math.h>
#include "Shape.h"

using std::to_string; 

class Rectangle : public Shape
{
private:
	//Центр Масс
	double x, y;

	double getArea();

	double getPerimetr();

	void center_of_gravity();

public:

	Rectangle(Point* pt);

	void Rotate(double rotation_angle);

	void Move(double move_x, double move_y);

	;
	std::string info();
	;
	~Rectangle();
};