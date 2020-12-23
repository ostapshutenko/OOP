#include "Console.h"

Point* Console::enter_Point(char c) {
	if (c == 'T')
	{
		Point* ptr = new Point[3];
		cout << "enter 1 vertex\n";
		cin >> ptr[0].X >> ptr[0].Y;
		cout << "enter 2 vertex\n";
		cin >> ptr[1].X >> ptr[1].Y;
		cout << "enter 3 vertex\n";
		cin >> ptr[2].X >> ptr[2].Y;
		return ptr;
	}
	else if (c == 'R')
	{
		Point* ptr = new Point[4];
		cout << "enter 1 vertex\n";
		cin >> ptr[0].X >> ptr[0].Y;
		cout << "enter 2 vertex\n";
		cin >> ptr[1].X >> ptr[1].Y;
		cout << "enter 3 vertex\n";
		cin >> ptr[2].X >> ptr[2].Y;
		cout << "enter 4 vertex\n";
		cin >> ptr[3].X >> ptr[3].Y;
		return ptr;
	}
	return nullptr;
}
int Console::init()
{
	

	// Объекты базового класса и класса Operations, symbol - символ фигуры
	Shape* ptr1 = 0, * ptr2 = 0;
	Point* pt;
	Operations op;
	char symbol;

	// Ввод типа фигуры
	cout << "Выберете тип фигуры: ";
	cin >> symbol;
	// Вывод информации о фигуре
	ptr1 = Shape::createShape(symbol, enter_Point(symbol));
	cout << ptr1->info();

	// Ввод типа фигуры
	cout << "\nВыберете тип фигуры: ";
	cin >> symbol;

	// Вывод информации о фигуре
	ptr2 = Shape::createShape(symbol, enter_Point(symbol));
	cout << ptr2->info();

	// Вызов операций сравнения, включения и пересечения двух фигур
	if ((ptr1->_Id_type == 'T' || ptr1->_Id_type == 'R') && (ptr2->_Id_type == 'T' || ptr2->_Id_type == 'R'))
	{
		op.Compare(ptr1, ptr2);
		op.IsIntersect(ptr1, ptr2);
		op.IsInclude(ptr1, ptr2);
	}
	double angle;
	cout << "\nвведите 1 угол поворота: ";
	cin >> angle;
	ptr1->Rotate(angle*M_PI/180);
	cout << ptr1->info();
	cout << "\nвведите 2 угол поворота: ";
	cin >> angle;
	ptr2->Rotate(angle * M_PI / 180);
	cout << ptr2->info();
	cout << "\nвведите 1 смещение: ";
	double x, y;
	cin >> x >> y;
	ptr1->Move(x, y);
	cout << ptr1->info();
	cout << "\nвведите 2 смещение: ";
	cin >> x >> y;
	ptr2->Move(x, y);
	cout << ptr2->info();
	// Очищение памяти
	delete ptr1;
	delete ptr2;
	return 0;
}