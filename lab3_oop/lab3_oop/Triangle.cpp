#include "Triangle.h"
using namespace std;

	
	double Triangle::getArea()
	{
		// S = 1/2 * a * b
		return 0.5 * abs(((_point_arr[0].X - _point_arr[2].X) * (_point_arr[1].Y - _point_arr[2].Y)) - ((_point_arr[1].X - _point_arr[2].X) * (_point_arr[0].Y - _point_arr[2].Y)));
	}

	double Triangle::getPerimetr()
	{
		 
		double line1 = sqrt(pow((_point_arr[1].X - _point_arr[0].X), 2) + pow((_point_arr[1].Y - _point_arr[0].Y), 2)); // Между 1 и 2 точкой
		double line2 = sqrt(pow((_point_arr[2].X - _point_arr[0].X), 2) + pow((_point_arr[2].Y - _point_arr[0].Y), 2)); // Между 1 и 3 точкой
		double line3 = sqrt(pow((_point_arr[2].X - _point_arr[1].X), 2) + pow((_point_arr[2].Y - _point_arr[1].Y), 2)); // Между 2 и 3 точкой

		 
		return line1 + line2 + line3;
	}
 
	void Triangle::center_of_gravity()
	{
		 
		double gravity_x = abs((_point_arr[0].X + _point_arr[1].X + _point_arr[2].X) / 3);
		double gravity_y = abs((_point_arr[0].Y + _point_arr[1].Y + _point_arr[2].Y) / 3);

		 
		x = gravity_x;
		y = gravity_y;
	}

	/*
	Triangle::Triangle(Point *pt)
	{
		// Id треугольника - T
		Id = 'T';

		point = new Point[3];
		point[0] = pt[0];
		point[1] = pt[1];
		point[2] = pt[2];

	}
	*/

	Triangle::Triangle(Point* pt)
	{
		_Id_type = 'T';

		_point_arr = new Point[3];
		_point_arr[0] = pt[0];
		_point_arr[1] = pt[1];
		_point_arr[2] = pt[2];
	}

	void Triangle::Rotate(double rotation_angle)
	{
		//double rotation_angle;
		double rotate_x, rotate_y;

	

		rotate_x = (cos(rotation_angle) * _point_arr[0].X) - (sin(rotation_angle) * _point_arr[0].Y);
		rotate_y = (sin(rotation_angle) * _point_arr[0].X) + (cos(rotation_angle) * _point_arr[0].Y);
		 
		_point_arr[0].X = rotate_x;
		_point_arr[0].Y = rotate_y;

		rotate_x = (cos(rotation_angle) * _point_arr[1].X) - (sin(rotation_angle) * _point_arr[1].Y);
		rotate_y = (sin(rotation_angle) * _point_arr[1].X) + (cos(rotation_angle) * _point_arr[1].Y);
	 
		_point_arr[1].X = rotate_x;
		_point_arr[1].Y = rotate_y;

		rotate_x = (cos(rotation_angle) * _point_arr[2].X) - (sin(rotation_angle) * _point_arr[2].Y);
		rotate_y = (sin(rotation_angle) * _point_arr[2].X) + (cos(rotation_angle) * _point_arr[2].Y);
		 
		_point_arr[2].X = rotate_x;
		_point_arr[2].Y = rotate_y;
	}

	void Triangle::Move(double move_x, double move_y) {	 

			_point_arr[0].X = _point_arr[0].X + move_x;
			_point_arr[1].X = _point_arr[1].X + move_x;
			_point_arr[2].X = _point_arr[2].X + move_x;
		


			_point_arr[0].Y = _point_arr[0].Y + move_y;
			_point_arr[1].Y = _point_arr[1].Y + move_y;
			_point_arr[2].Y = _point_arr[2].Y + move_y;
		
	};

	string Triangle::info()
	{
		string s = "";
		s += "Треугольник\n";
		s += "Координаты точек треугольника: \n";

		s += "x1 = "; s += to_string(_point_arr[0].X); s += "; y1 = "; s += to_string(_point_arr[0].Y); s += "\n";
		s += "x2 = "; s += to_string(_point_arr[1].X); s += "; y2 = "; s += to_string(_point_arr[1].Y); s += "\n";
		s += "x3 = "; s += to_string(_point_arr[2].X); s += "; y3 = "; s += to_string(_point_arr[2].Y); s += "\n";

		s += "Площадь треугольника : "; s += to_string(getArea()); s += "\n";
		s += "Периметр треугольника : "; s += to_string(getPerimetr()); s += "\n";
		center_of_gravity();
		s += "Центр тяжести : x = "; s += to_string(x); s += ", y = "; s += to_string(y); s += "\n";
		return s;
	}

	Triangle::~Triangle()
	{
		delete[] _point_arr;
	}