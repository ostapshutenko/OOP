#pragma once
class Date
{

public:
	int Day;
	int Month;
	int Year;
	bool operator==(Date& r)
	{
		long long sum1, sum2;
			sum1 = Day + Month * 31 + Year * 366;
			sum2 = r.Day + r.Month * 31 + r.Year * 366;
			return sum1 == sum2;
	}
};