#pragma once
#include <stdexcept>
#include "Point.h"
#include <math.h>
class Figure {
public:
	Figure() { _n = 0; _ptr = new Point[_n]; };
	~Figure() { delete [] _ptr; };
	void add(double x, double y);
	void add(Point buf_add);
	/*
	void insert(int n, double x, double y);
	void insert(int n, Point buf_add);
	*/
	double getPerimetr();
	double getArea();
	bool del(int n);
	Point getCentrMass();
	Point getPoint(int n)const;
	int len()const;
protected:
	int _n = 0;
	Point *_ptr;
};