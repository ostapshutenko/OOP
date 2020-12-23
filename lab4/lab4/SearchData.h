#pragma once
#include"Date.h"
#include "Flight.h"
#include <string>
struct SearchData
{

	Date _searchDate;
	std::string searchDst;
	SearchData(Date searchDate, std::string searchDst) : _searchDate(searchDate), searchDst(searchDst) {}

	bool operator()(Flight temp)
	{
		return temp._departureDate == _searchDate && temp._destPoint == searchDst;
	}
};