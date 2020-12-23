#pragma once
#include <iostream>
#include <string>
#include "Point.h"

class Shape
{
public:

	Point* _point_arr;		
	char _Id_type;			

	virtual ~Shape() {}

	
	virtual std::string info() = 0;
	//virtual void info() = 0;

	virtual double getArea()
	{
		return 0;
	}

	
	virtual void Rotate(double rotation_angle) {};

	
	virtual void Move(double move_x, double move_y) {};

	
	static Shape* createShape(char c, Point* pt);
};

