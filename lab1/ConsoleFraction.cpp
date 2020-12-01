#include "ConsoleFraction.h"
ConsoleFraction::ConsoleFraction() {};
ConsoleFraction::~ConsoleFraction() {};
void ConsoleFraction::init()
{
	Fraction fa, fb,fc;
	while (true)
	{
		std::cout << "type first Fraction\n";
		int a, b;
		std::cin >> a >> b;
		fa.set(a, b);
		std::cout << "type last Fraction\n";
		std::cin >> a >> b;
		fb.set(a, b);

		std::cout << "0 - test the assignment operator;\n1 - test operator +;\n2 - test operator-;\n3 - test operator *;\n4 - test operator /;\n5 - to check the function of the comparison.\n";
		while (true) 
		{
			std::cin >> a;
			if (a > 5 || a < -1)
			{
				std::cout << "command error\n";
			}
			else break;
		}
		switch (a)
		{
			
		case 0:fb = fa; fb.set(5, 6); 
			std::cout << "b=a b=";
			pprint(fb);
			std::cout << " a=";
			pprint(fa);
			std::cout << "\n";
			break;
		case 1:
			fc = (fb + fa); 
			std::cout << "b+a = ";
			pprint(fc);
			std::cout << "\n";
			break;
		case 2:
			fc = (fb - fa); 
			std::cout << "b-a =";
			pprint(fc);
			std::cout << "\n";
			break;
		case 3:
			fc = (fb * fa); 
			std::cout << "b*a =";
			pprint(fc);
			std::cout << "\n";
			break;
		case 4:
			fc = (fb / fa); 
			pprint(fc);
			std::cout << "\n";
			break;
		case 5:
			std::cout <<"-1=exc, 0= a==b, 1= a>b, 2= a<b:"<< fb.Comparison(fa) << "\n";
			break;
		}
		if (a == -1)
			break;
	}
};
void ConsoleFraction::pprint(Fraction buf)
{
	std::cout << buf.getNumerals() << "/" << buf.getDenominator() << " exc:" << buf.getException();
};