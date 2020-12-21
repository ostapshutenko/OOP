#include "Figure.h"

// Метод сравнения площадей
void Operations::Compare(Shape* p1, Shape* p2)
{
	// Сравнение площади первой и второй фигуры
	if (p1->getArea() > p2->getArea())
		cout << "Площадь первой фигуры больше площади второй фигуры" << endl;
	else if (p1->getArea() < p2->getArea())
		cout << "Площадь второй фигуры больше площали первой фигуры" << endl;
	else
		cout << "Площади фигур равны" << endl;
}

// Метод проверки пересечения площадей
void Operations::IsIntersect(Shape* p1, Shape* p2)
{
	if (!rec_in_tre(p1, p2) && flag == 1)
		cout << "Фигуры пересекаются" << endl;

	else if ((!tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[0]) || !tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[0]) || !tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[0])) && flag == 1)
		if ((!tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[1]) || !tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[1]) || !tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[1])) && flag == 1)
			if ((!tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[2]) || !tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[2]) || !tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[2])) && flag == 1)
				cout << "Фигуры пересекаются" << endl;

			else cout << "Фигуры не пересекаются" << endl;
		else cout << "Фигуры не пересекаются" << endl;

	else cout << "Фигуры не пересекаются" << endl;

	flag = 0;
}

// Метод проверки включения фигур друг в друга
void Operations::IsInclude(Shape* p1, Shape* p2)
{
	// Если площадь треугольника больше площади прямоугольника
	if (p1->getArea() >= p2->getArea())
	{
		// Если функция rec_in_tre вернула 1, то прямоугольник заключён в треугольник, иначе фигуры не заключены
		if (rec_in_tre(p1, p2))
			cout << "Прямоугольник заключён в треугольник" << endl;

		else cout << "Фигуры не заключены" << endl;
	}

	// Если площадь треугольника меньше площади прямоугольника
	else if (p1->getArea() < p2->getArea())
	{
		// Если функция tre_in_rec вернула во всех проверках 1, то треугольник заключён в прямоугольник, иначе фигуры не заключены
		if (tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[0]) || tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[0]) || tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[0]))
			if (tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[1]) || tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[1]) || tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[1]))
				if (tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[2]) || tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[2]) || tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[2]))
					cout << "Треугольник заключён в прямоугольник" << endl;

				else cout << "Фигуры не заключены" << endl;
			else cout << "Фигуры не заключены" << endl;
		else cout << "Фигуры не заключены" << endl;
	}

	else
		cout << "Фигуры не заключены" << endl;

	flag = 0;
}

// Метод проверки включения прямоугольника в треугольник
bool Operations::rec_in_tre(Shape* p1, Shape* p2)
{
	double a, b, c;
	int fl = 1;

	// Цикл проходит по каждой точке прямоугольника и проверяет её на заключённость в треугольник
	for (int i = 0; i < 4; i++)
	{
		a = (p1->point[0].x - p2->point[i].x) * (p1->point[1].y - p1->point[0].y) - (p1->point[1].x - p1->point[0].x) * (p1->point[0].y - p2->point[i].y);
		b = (p1->point[1].x - p2->point[i].x) * (p1->point[2].y - p1->point[1].y) - (p1->point[2].x - p1->point[1].x) * (p1->point[1].y - p2->point[i].y);
		c = (p1->point[2].x - p2->point[i].x) * (p1->point[0].y - p1->point[2].y) - (p1->point[0].x - p1->point[2].x) * (p1->point[2].y - p2->point[i].y);

		if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
			flag = 1;
		else
			fl = 0;
	}

	if (flag && fl)
		return 1;
	else
		return 0;
}

// Метод проверки включения треугольника в прямоугольник
bool Operations::tre_in_rec(Point A, Point B, Point C, Point P)
{
	double a, b, c;
	int fl = 1;

	// Цикл проходит по каждой точке треугольника и проверяет её на заключённость в прямоугольник
	for (int i = 0; i < 3; i++)
	{
		a = (A.x - P.x) * (B.y - A.y) - (B.x - A.x) * (A.y - P.y);
		b = (B.x - P.x) * (C.y - B.y) - (C.x - B.x) * (B.y - P.y);
		c = (C.x - P.x) * (A.y - C.y) - (A.x - C.x) * (C.y - P.y);

		if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
			flag = 1;
		else
			fl = 0;
	}

	if (flag && fl)
		return 1;
	else
		return 0;
}
