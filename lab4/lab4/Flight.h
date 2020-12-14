#pragma once
#include <string>
#include "Date.h"
#include "Time.h"
struct Flight
{
	Date _departureDate;	// Дата отправления
	Time _departureTime;	// Время отправления
	Time _arrivalTime;	// Время прибытия
	int _flightNumber;	// Номер рейса
	std::string _destPoint;	// Пункт назначения
	Flight(Date departureDate, Time departureTime, std::string destPoint, Time arrivalTime, int flightNumber) : _departureDate(departureDate), _departureTime(departureTime), _arrivalTime(arrivalTime), _flightNumber(flightNumber), _destPoint(destPoint) {}
};