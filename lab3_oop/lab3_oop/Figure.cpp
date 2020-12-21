#include "Figure.h"

// ����� ��������� ��������
void Operations::Compare(Shape* p1, Shape* p2)
{
	// ��������� ������� ������ � ������ ������
	if (p1->getArea() > p2->getArea())
		cout << "������� ������ ������ ������ ������� ������ ������" << endl;
	else if (p1->getArea() < p2->getArea())
		cout << "������� ������ ������ ������ ������� ������ ������" << endl;
	else
		cout << "������� ����� �����" << endl;
}

// ����� �������� ����������� ��������
void Operations::IsIntersect(Shape* p1, Shape* p2)
{
	if (!rec_in_tre(p1, p2) && flag == 1)
		cout << "������ ������������" << endl;

	else if ((!tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[0]) || !tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[0]) || !tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[0])) && flag == 1)
		if ((!tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[1]) || !tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[1]) || !tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[1])) && flag == 1)
			if ((!tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[2]) || !tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[2]) || !tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[2])) && flag == 1)
				cout << "������ ������������" << endl;

			else cout << "������ �� ������������" << endl;
		else cout << "������ �� ������������" << endl;

	else cout << "������ �� ������������" << endl;

	flag = 0;
}

// ����� �������� ��������� ����� ���� � �����
void Operations::IsInclude(Shape* p1, Shape* p2)
{
	// ���� ������� ������������ ������ ������� ��������������
	if (p1->getArea() >= p2->getArea())
	{
		// ���� ������� rec_in_tre ������� 1, �� ������������� �������� � �����������, ����� ������ �� ���������
		if (rec_in_tre(p1, p2))
			cout << "������������� �������� � �����������" << endl;

		else cout << "������ �� ���������" << endl;
	}

	// ���� ������� ������������ ������ ������� ��������������
	else if (p1->getArea() < p2->getArea())
	{
		// ���� ������� tre_in_rec ������� �� ���� ��������� 1, �� ����������� �������� � �������������, ����� ������ �� ���������
		if (tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[0]) || tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[0]) || tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[0]))
			if (tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[1]) || tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[1]) || tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[1]))
				if (tre_in_rec(p2->point[0], p2->point[1], p2->point[2], p1->point[2]) || tre_in_rec(p2->point[1], p2->point[2], p2->point[3], p1->point[2]) || tre_in_rec(p2->point[2], p2->point[3], p2->point[0], p1->point[2]))
					cout << "����������� �������� � �������������" << endl;

				else cout << "������ �� ���������" << endl;
			else cout << "������ �� ���������" << endl;
		else cout << "������ �� ���������" << endl;
	}

	else
		cout << "������ �� ���������" << endl;

	flag = 0;
}

// ����� �������� ��������� �������������� � �����������
bool Operations::rec_in_tre(Shape* p1, Shape* p2)
{
	double a, b, c;
	int fl = 1;

	// ���� �������� �� ������ ����� �������������� � ��������� � �� ������������� � �����������
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

// ����� �������� ��������� ������������ � �������������
bool Operations::tre_in_rec(Point A, Point B, Point C, Point P)
{
	double a, b, c;
	int fl = 1;

	// ���� �������� �� ������ ����� ������������ � ��������� � �� ������������� � �������������
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
