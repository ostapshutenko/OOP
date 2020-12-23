#pragma once
class Date
{

public:
	int Day;
	int Month;
	int Year;
	bool operator==(Date& r)
	{
			if(Day == r.Day && Month == r.Month && Year == r.Year)
			return true;
			return false;
	}
};