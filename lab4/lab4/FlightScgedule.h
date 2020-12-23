#pragma once
#include <vector>
#include <map>
#include "SearchData.h"
#include "Flight.h"
using namespace std;

// Класс FlightSchedule
class FlightSchedule
{
public:
	FlightSchedule() {};
	~FlightSchedule() {};
	const int WORK_MODE_VECTOR = 0;
	const int WORK_MODE_MAP = 1;
public:
	void choice(int nmode);
	int mode()const;
public:
	
	/*
	void readingfile(string& namefile);		// exception
	*/
	void set(Flight buf);

private:
	


public:

	string printinfo(Date& depDate, string& dstPoint);

private:
	
	int _mode = 0;

	vector<Flight> _vector;
	multimap<string, Flight> _mmap;
};