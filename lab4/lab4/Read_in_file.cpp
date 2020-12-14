#include "Read_in_file.h"
void readingfile(string& namefile, FlightSchedule& buffer)		// exception
{
	ifstream fin(namefile);
	if (!fin.is_open())
		throw new exception("Ошибка открытия файла"); //exception

	Date depDate;
	Time depTime;
	string dstPoint;
	Time arrTime;
	int flightNo;
	char c;

	while (!fin.eof())
	{
		fin >> depDate.Day >> c >> depDate.Month >> c >> depDate.Year;
		fin >> depTime.Second >> c >> depTime.Minute >> c >> depTime.Hour;
		fin >> dstPoint;
		fin >> arrTime.Second >> c >> arrTime.Minute >> c >> arrTime.Hour;
		fin >> flightNo;
		Flight buf(depDate, depTime, dstPoint, arrTime, flightNo);

		buffer.set(buf);
	}

	fin.close();
};