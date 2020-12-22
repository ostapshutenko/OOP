#pragma once
#include "Fraction.h"
#include <iostream>
class ConsoleFraction
{
public:
	ConsoleFraction();
	~ConsoleFraction();
	int command();
	void init();
	void pprint(Fraction buf);
};