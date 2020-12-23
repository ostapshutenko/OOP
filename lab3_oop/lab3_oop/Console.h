#pragma once
#include <iostream>
#include <cmath>
//#include <vld.h>
using namespace std;
#include "Operations.h"
// в библиотеке нет константы
#define M_PI 3.14159265358979323846

class Console{
public:
	Point* enter_Point(char c);
	int init();
};
