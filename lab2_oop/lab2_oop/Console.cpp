#include "Console.h"
#include <iostream>
void Console::init() {
	std::cout << "search: 1 - Figure 2 - Pentagon 3 - Rectangle\n";
	int search;
	std::cin >> search;
	switch (search)
	{
	case 1:viewFigure(); break;
	case 2:viewPentagon(); break;
	case 3:viewRectangle(); break;
	default:break;
	}

//	std::cout << "ok";
};
int Console::viewPentagon()
{
	Pentagon Fig;
	double x, y;
	int n = 5;

		for (int i = 0; i < n; i++)
		{
			std::cout << "enter vertex:";
			std::cin >> x >> y;
			Fig.add(x, y);
		}
		std::cout << " is Pentagon " << Fig.isExist() << " Area=" << Fig.getArea() << " Perimetr=" << Fig.getPerimetr() << " CentrMass=";
		pprint(Fig.getCentrMass());
		std::cout << "\nPrint figure\n";
		for (int i = 0; i < Fig.len(); i++)
			pprint(Fig.getPoint(i));
		std::cout << "\nenter vertex for delete\n";
		std::cin >> n;
		Fig.del(n);
		for (int i = 0; i < Fig.len(); i++)
			pprint(Fig.getPoint(i));
		return 0;
};
int Console::viewRectangle()
{
	Rectangle Fig;
	double x, y;
	int n = 4;

		for (int i = 0; i < n; i++)
		{
			std::cout << "enter vertex:";
			std::cin >> x >> y;
			Fig.add(x, y);
		}
		std::cout <<" is Rectangle "<< Fig.isExist() << " Area=" << Fig.getArea() << " Perimetr=" << Fig.getPerimetr() << " CentrMass=";
		pprint(Fig.getCentrMass());
		std::cout << "\nPrint figure\n";
		for (int i = 0; i < Fig.len(); i++)
			pprint(Fig.getPoint(i));
		std::cout << "\nenter vertex for delete\n";
		std::cin >> n;
		Fig.del(n);
		for (int i = 0; i < Fig.len(); i++)
			pprint(Fig.getPoint(i));

		return 0;
};
int Console::viewFigure()
{
	Figure Fig;
	double x, y;
	int n;
	std::cout << "enter the number of vertexes:";
	std::cin >> n;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "enter vertex:";
			std::cin >> x >> y;
			Fig.add(x, y);
		}
		std::cout << "Area=" << Fig.getArea() << " Perimetr=" << Fig.getPerimetr() << " CentrMass=";
		pprint(Fig.getCentrMass());
		std::cout << "\nPrint figure\n";
		for(int i = 0; i < Fig.len();i++)
			pprint(Fig.getPoint(i));
		std::cout << "\nenter vertex for delete\n";
		std::cin >> n;
		Fig.del(n);
		
		for (int i = 0; i < Fig.len(); i++)
			pprint(Fig.getPoint(i));
	
	}
	else
		std::cout << "there is no such figure";
	return 0;
};
void Console::pprint(Point buf)
{
	std::cout << buf.X << " " << buf.Y << "\n";
};


