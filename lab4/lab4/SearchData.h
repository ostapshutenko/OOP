#pragma once
#include"Date.h"
#include "Flight.h"
#include <string>
struct SearchData
{

	Date searchDate;
	std::string searchDst;
	SearchData(Date searchDate, std::string searchDst) : searchDate(searchDate), searchDst(searchDst) {}

	bool operator()(Flight temp)
	{
		return temp._departureDate == searchDate && temp._destPoint == searchDst;
	}
};