#include "ConsoleFraction.h"
ConsoleFraction::ConsoleFraction() {};
ConsoleFraction::~ConsoleFraction() {};
void ConsoleFraction::init()
{
	Fraction fa, fb;
	while (true)
	{
		std::cout << "type first Fraction\n";
		int a, b;
		std::cin >> a >> b;
		fa.set(a, b);
		std::cout << "type last Fraction\n";
		std::cin >> a >> b;
		fb.set(a, b);

		std::cin >> a;
		switch (a)
		{
		case 0:fb = fa; fb.set(5, 6); std::cout << "b=a b=" << fb.getChis() << "/" << fb.getZnam() << "\n" << "a =" << fa.getChis() << "/" << fa.getZnam() << "\n"; break;
		case 1:fb = fb + fa; std::cout << "b+a =" << fb.getChis() << "/" << fb.getZnam() << "\n"; break;
		case 2:fb = fb - fa; std::cout << "b-a =" << fb.getChis() << "/" << fb.getZnam() << "\n"; break;
		case 3:fb = fb * fa; std::cout << "b*a =" << fb.getChis() << "/" << fb.getZnam() << "\n"; break;
		case 4:fb = fb / fa; std::cout << "b/a =" << fb.getChis() << "/" << fb.getZnam() << "\n"; break;
		case 5:std::cout << fb.Comparison(fa) << "\n"; break;
		}
		if (a == -1)
			break;
	}
};