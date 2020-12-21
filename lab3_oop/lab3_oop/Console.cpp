#include "Console.h"

Point* Console::enter_Point(char c) {
	if (c == 'T')
	{
		Point* ptr = new Point[3];
		cout << "enter 1 vertex\n";
		cin >> ptr[0].x >> ptr[0].y;
		cout << "enter 2 vertex\n";
		cin >> ptr[1].x >> ptr[1].y;
		cout << "enter 3 vertex\n";
		cin >> ptr[2].x >> ptr[2].y;
		return ptr;
	}
	else if (c == 'R')
	{
		Point* ptr = new Point[4];
		cout << "enter 1 vertex\n";
		cin >> ptr[0].x >> ptr[0].y;
		cout << "enter 2 vertex\n";
		cin >> ptr[1].x >> ptr[1].y;
		cout << "enter 3 vertex\n";
		cin >> ptr[2].x >> ptr[2].y;
		cout << "enter 4 vertex\n";
		cin >> ptr[3].x >> ptr[3].y;
		return ptr;
	}
	return nullptr;
}
int Console::init()
{
	

	// ������� �������� ������ � ������ Operations, symbol - ������ ������
	Shape* ptr1 = 0, * ptr2 = 0;
	Point* pt;
	Operations op;
	char symbol;

	// ���� ���� ������
	cout << "�������� ��� ������: ";
	cin >> symbol;
	// ����� ���������� � ������
	ptr1 = Shape::createShape(symbol, enter_Point(symbol));
	cout << ptr1->info();

	// ���� ���� ������
	cout << "�������� ��� ������: ";
	cin >> symbol;

	// ����� ���������� � ������
	ptr2 = Shape::createShape(symbol, enter_Point(symbol));
	cout << ptr2->info();

	// ����� �������� ���������, ��������� � ����������� ���� �����
	op.Compare(ptr1, ptr2);
	op.IsIntersect(ptr1, ptr2);
	op.IsInclude(ptr1, ptr2);
	double angle;
	cout << "������� 1 ���� ��������: ";
	cin >> angle;
	ptr1->Rotate(angle);
	cout << ptr1->info();
	cout << "������� 2 ���� ��������: ";
	cin >> angle;
	ptr2->Rotate(angle);
	cout << ptr2->info();
	cout << "������� 1 ��������: ";
	double x, y;
	cin >> x >> y;
	ptr1->Move(x, y);
	cout << ptr1->info();
	cout << "������� 2 ��������: ";
	cin >> x >> y;
	ptr1->Move(x, y);
	cout << ptr2->info();
	// �������� ������
	delete ptr1;
	delete ptr2;
	return 0;
}