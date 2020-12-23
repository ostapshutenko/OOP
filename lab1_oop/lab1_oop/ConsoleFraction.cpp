#include "ConsoleFraction.h"
ConsoleFraction::ConsoleFraction() {};
ConsoleFraction::~ConsoleFraction() {};
void ConsoleFraction::init()
{
	Fraction fa, fb, fc(5, 6), fd(fc);
	while (true)
	{
		std::cout << "type first Fraction\n";
		int a, b;
		std::cin >> a >> b;
		fa.setNumerals(a);
		fa.setDenominator(b);

		std::cout << "type last Fraction\n";
		std::cin >> a >> b;
		fb.setNumerals(a);
		fb.setDenominator(b);
		std::cout << "\n0 - test the assignment operator;\n1 - test operator +;\n2 - test operator-;\n3 - test operator *;\n4 - test operator /;\n5 - to check the function of the comparison.\n";
		a = Ñommand();
		switch (a)
		{			
		case 0:	
			fc = fb;
			std::cout << "b=a b=";
			pprint(fb);
			fc = fa;
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
			std::cout << "b/a =";
			pprint(fc);
			std::cout << "\n";
			break;
		case 5:
			std::cout <<"\n-1=exc, 0= a==b, 1= a>b, 2= a<b: "<< fb.Comparison(fa) << "\n";
			break;
		}
		if (a == -1)
			break;
	}
};

int ConsoleFraction::Ñommand()
{
	int a;
	while (true)
	{
		std::cin >> a;
		if (a > 5 || a < -1)
		{
			std::cout << "command error\n";
		}
		else break;
	}
	return a;
};

void ConsoleFraction::pprint(Fraction buf)
{
	std::cout << buf.getNumerals() << "/" << buf.getDenominator() << " exc:" << buf.getException();
};