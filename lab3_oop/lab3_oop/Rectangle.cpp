#include "Rectangle.h"
double Rectangle::getArea()
{
	double line1 = abs(_point_arr[0].X - _point_arr[3].X);
	double line2 = abs(_point_arr[0].Y - _point_arr[1].Y);

	return (line1 * line2);
}

double Rectangle::getPerimetr()
{
	double line1 = abs(_point_arr[0].X - _point_arr[3].X);
	double line2 = abs(_point_arr[0].Y - _point_arr[1].Y);

	return 2 * (line1 + line2);
}

void Rectangle::center_of_gravity()
{
	double temp_x = (abs(_point_arr[0].X - _point_arr[3].X) / 2);
	double temp_y = (abs(_point_arr[0].Y - _point_arr[1].Y) / 2);
	double gravity_x = _point_arr[0].X + temp_x;
	double gravity_y = _point_arr[0].Y + temp_y;

	x = gravity_x;
	y = gravity_y;
}

Rectangle::Rectangle(Point* pt)
{
	_Id_type = 'R';
	_point_arr = new Point[4];
	_point_arr[0] = pt[0];
	_point_arr[1] = pt[1];
	_point_arr[2] = pt[2];
	_point_arr[3] = pt[3];
}

void Rectangle::Rotate(double rotation_angle)
{
	double rotate_x, rotate_y;

	/*cout << "Введите угол поворота : ";
	cin >> rotation_angle;*/

	rotate_x = (cos(rotation_angle) * _point_arr[0].X) - (sin(rotation_angle) * _point_arr[0].Y);
	rotate_y = (sin(rotation_angle) * _point_arr[0].X) + (cos(rotation_angle) * _point_arr[0].Y);
	// Новые координаты точки (х1, y1)
	_point_arr[0].X = rotate_x;
	_point_arr[0].Y = rotate_y;

	rotate_x = (cos(rotation_angle) * _point_arr[1].X) - (sin(rotation_angle) * _point_arr[1].Y);
	rotate_y = (sin(rotation_angle) * _point_arr[1].X) + (cos(rotation_angle) * _point_arr[1].Y);
	// Новые координаты точки (х2, y2)
	_point_arr[1].X = rotate_x;
	_point_arr[1].Y = rotate_y;

	rotate_x = (cos(rotation_angle) * _point_arr[2].X) - (sin(rotation_angle) * _point_arr[2].Y);
	rotate_y = (sin(rotation_angle) * _point_arr[2].X) + (cos(rotation_angle) * _point_arr[2].Y);
	// Новые координаты точки (х3, y3)
	_point_arr[2].X = rotate_x;
	_point_arr[2].Y = rotate_y;

	rotate_x = (cos(rotation_angle) * _point_arr[3].X) - (sin(rotation_angle) * _point_arr[3].Y);
	rotate_y = (sin(rotation_angle) * _point_arr[3].X) + (cos(rotation_angle) * _point_arr[3].Y);
	// Новые координаты точки (х4, y4)
	_point_arr[3].X = rotate_x;
	_point_arr[3].Y = rotate_y;
}

void Rectangle::Move(double move_x, double move_y)
{

		_point_arr[0].X = _point_arr[0].X + move_x;
		_point_arr[1].X = _point_arr[1].X + move_x;
		_point_arr[2].X = _point_arr[2].X + move_x;
		_point_arr[3].X = _point_arr[3].X + move_x;
	
		_point_arr[0].Y = _point_arr[0].Y + move_y;
		_point_arr[1].Y = _point_arr[1].Y + move_y;
		_point_arr[2].Y = _point_arr[2].Y + move_y;
		_point_arr[3].Y = _point_arr[3].Y + move_y;
	
}

;
std::string Rectangle::info() {
	std::string s = "";
	s += "Прямоугольник\n";
	s += "Координаты точек прямоугольника: \n";
	s += "x1 = "; s += to_string(_point_arr[0].X); s += ";"; s += " y1 = "; s += to_string(_point_arr[0].Y); s += "\n";
	s += "x2 = "; s += to_string(_point_arr[1].X); s += ";"; s += " y2 = "; s += to_string(_point_arr[1].Y); s += "\n";
	s += "x3 = "; s += to_string(_point_arr[2].X); s += ";"; s += " y3 = "; s += to_string(_point_arr[2].Y); s += "\n";
	s += "x4 = "; s += to_string(_point_arr[3].X); s += ";"; s += " y4 = "; s += to_string(_point_arr[3].Y); s += "\n";

	s += "Площадь прямоугольника : "; s += to_string(getArea()); s += "\n";
	s += "Периметр прямоугольника : "; s += to_string(getPerimetr()); s += "\n";

	center_of_gravity();
	s += "Центр тяжести : x = "; s += to_string(x); s += ", y = "; s += to_string(y); s += "\n";
	return s;
}
;
Rectangle::~Rectangle()
{
	delete[] _point_arr;
}