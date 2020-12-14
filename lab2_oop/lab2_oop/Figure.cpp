#include "Figure.h"

void Figure::add(double x, double y)
{
	Point* buf = new Point[_n + 1];
	buf[_n].X = x;
	buf[_n].Y = y;
	for (int i = 0; i < _n; i++)
		buf[i] = _ptr[i];
	_n++;
	delete[] _ptr;
	_ptr = buf;

};
void Figure::add(Point buf_add)
{
	Point* buf = new Point[_n + 1];
	buf[_n] = buf_add;
	for (int i = 0; i < _n; i++)
		buf[i] = _ptr[i];
	_n++;
	delete[] _ptr;
	_ptr = buf;
};
/*
void Figure::insert(int n, double x, double y)
{

	if (n > _n)
		n = _n-1;
	if (n < 0)
		n = 0;
	Point* buf = new Point[_n + 1];
	buf[n].X = x;
	buf[n].Y = y;
	for (int i = 0; i < n; i++)
		buf[i] = _ptr[i];
	for (int i = n + 1; i < _n + 1; i++)
		buf[i] = _ptr[i - 1];
	_n++;
	delete[] _ptr;
	_ptr = buf;
};
void Figure::insert(int n, Point buf_add)
{
	if (n > _n)
		n = _n-1;
	if (n < 0)
		n = 0;
	Point* buf = new Point[_n + 1];
	buf[n] = buf_add;
	for (int i = 0; i < n; i++)
		buf[i] = _ptr[i];
	for (int i = n + 1; i < _n + 1; i++)
		buf[i] = _ptr[i - 1];
	_n++;
	delete[] _ptr;
	_ptr = buf;
};
*/
double Figure::getPerimetr()
{
	double sum = 0;
	if(_n>0)
	{
		if (_n > 0)
		{
			for (int i = 0; i < _n - 1; i++)
			{
				sum += sqrt((_ptr[i + 1].X - _ptr[i].X) * (_ptr[i + 1].X - _ptr[i].X) + (_ptr[i + 1].Y - _ptr[i].Y) * (_ptr[i + 1].Y - _ptr[i].Y));

			}
			sum += sqrt((_ptr[0].X - _ptr[_n - 1].X) * (_ptr[0].X - _ptr[_n - 1].X) + (_ptr[0].Y - _ptr[_n - 1].Y) * (_ptr[0].Y - _ptr[_n - 1].Y));
		}
	}
	return sum;
};
double Figure::getArea()
{
	double sum1 = 0, sum2 = 0;
	if(_n > 0)
	{
		sum1 += _ptr[_n - 1].X * _ptr[0].Y;
		sum2 += _ptr[_n - 1].Y * _ptr[0].X;

		for (int i = 0; i < _n - 1; i++)
		{
			sum1 += _ptr[i].X * _ptr[i + 1].Y;
			sum2 += _ptr[i].Y * _ptr[i + 1].X;
		}
		sum1 -= sum2;
		if (sum1 < 0)
			sum1 *= -1;
	}
	return sum1/2;
};
Point Figure::getCentrMass()
{
	double sum1 = 0, sum2 = 0;

	Point f;
	for (int i = 0; i < _n; i++)
	{
		sum1 += _ptr[i].X;
		sum2 += _ptr[i].Y;
	}
	sum1 /= _n;
	sum2 /= _n;

	f.X = sum1;
	f.Y = sum2;

	return f;
};
bool Figure::del(int n)
{
	if (n < 0)
		n += _n;
	if (n >= 0 && n < _n) 
	{
		int i = n;
		for (i = n; i < _n-1 ; i++)
		{
			_ptr[i] = _ptr[i + 1];
		}
		_n--;
		
		Point* buf = new Point[_n];
		for (int i = 0; i < _n; i++)
		{
			buf[i] = _ptr[i];
		}
		delete[] _ptr;
		_ptr = buf;
		
		return true;
	}
	return false;
};
int Figure::len()const
{
	return _n;
}
Point Figure::getPoint(int n)const
{
	if (n < 0)
	{
		n = _n + n;
	}
	try {
		if (n >= _n || n < 0)
		{
			throw std::out_of_range("out of array");
		}
	}
	catch (std::out_of_range & e)
	{
		while (n < 0)
			n += _n;
		while (n >= _n)
			n -= _n;
	}
	if (n < _n)
		return _ptr[n];
};