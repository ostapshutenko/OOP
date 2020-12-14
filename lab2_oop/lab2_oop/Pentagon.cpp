#include "Pentagon.h"

Pentagon::Pentagon() {
	_n = 0;
	_ptr = new Point[_n];
};


Pentagon::~Pentagon() {
	Figure::~Figure();
	//delete[] _ptr;
};
bool Pentagon::isExist() {
	if (_n == 5)
	{
		for (int i = 0; i < _n; i++)
			for (int j = i + 1; j < _n; j++)
				if (_ptr[j].X == _ptr[i].X && _ptr[j].Y == _ptr[i].Y)
					return false;
		return true;
	}
	return false;
};