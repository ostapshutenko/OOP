#pragma once
#include "Figure.h"
#include "Pentagon.h"
#include "Rectangle.h"
class Console {
public:
	void init();
	int viewPentagon();
	int viewRectangle();
	int viewFigure();
	void pprint(Point buf);
private:
};
