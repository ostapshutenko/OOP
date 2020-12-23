#include "FlightScgedule.h"

using namespace std;

	void FlightSchedule::choice(int nmode)
	{
		_mode = nmode;
	}

	int FlightSchedule::mode()const
	{
		return _mode;
	};

	/*void readingfile(string& namefile)		// exception
	{
		// Проверка файл на существование
		ifstream fin(namefile);
		if (!fin.is_open())
			throw new exception("Ошибка открытия файла"); //exception

		// Временные строки для считывания строк из файла
		Date depDate;
		Time depTime;
		string dstPoint;
		Time arrTime;
		int flightNo;
		char c;

		// Пока не конец файла, мы будем считывать строки
		while (!fin.eof())
		{
			// Считываем строку
			fin >> depDate.Day >> c >> depDate.Month >> c >> depDate.Year;
			fin >> depTime.Second >> c >> depTime.Minute >> c >> depTime.Hour;
			fin >> dstPoint;
			fin >> arrTime.Second >> c >> arrTime.Minute >> c >> arrTime.Hour;
			fin >> flightNo;
			Flight buf(depDate, depTime, dstPoint, arrTime, flightNo);

			//cout << depDate << depTime << dstPoint << arrTime << flightNo;
			// Если был выбран вектор, то заносим в вектор строку
			if (mode == WORK_MODE_VECTOR)
				vector.push_back(buf);

			// Если был выбран словарь, то вставляем в словарь пару в виде строки (дата) и структура (вся строка рейса)
			else if (mode == WORK_MODE_MAP)
			{
				mmap.insert(pair<string, Flight>(buf._destPoint, buf));
			}
		}

		// Закрытие файла
		fin.close();
	}*/
	void FlightSchedule::set(Flight buf) {
		if (_mode == WORK_MODE_VECTOR)
			_vector.push_back(buf);
		else if (_mode == WORK_MODE_MAP)
		{
			_mmap.insert(pair<string, Flight>(buf._destPoint, buf));
		}
	};
	
	string FlightSchedule::printinfo(Date& depDate, string& dstPoint)
	{
		string s = "";// Если выбрали вектор
		if (_mode == WORK_MODE_VECTOR)
		{
			// Создаем итератор на первый элемент
			auto it = _vector.begin();

			// Пока не последний элемент
			while (it != _vector.end())
			{
				// ищем вхождение от начала до конца структуры такой же даты и места
				it = find_if(it, _vector.end(), SearchData(depDate, dstPoint));
				// если итератор не конец то есть что то нашли мы выводим на экран данный рейс
				if (it != _vector.end())
				{
					//cout << it->flightNo << " " << it->departureTime << " " << it->arrivalTime << endl;
					s += to_string(it->_departureDate.Day); s += ".";
					s += to_string(it->_departureDate.Month); s += ".";
					s += to_string(it->_departureDate.Year); s += " ";
					s += to_string(it->_departureTime.Hour); s += ":";
					s += to_string(it->_departureTime.Minute); s += ":";
					s += to_string(it->_departureTime.Second); s += " ";
					s += it->_destPoint; s += " ";
					s += to_string(it->_arrivalTime.Hour); s += ":";
					s += to_string(it->_arrivalTime.Minute); s += ":";
					s += to_string(it->_arrivalTime.Second); s += " ";
					s += to_string(it->_flightNumber); s += "\n";
					it++;
				}
			}
		}

		// если был выбран словар
		else if (_mode == WORK_MODE_MAP)
		{
			// создаем итератор на начало
			auto it = _mmap.begin();
			// в счетчик = количество введенных дат в мапе
			int counter = _mmap.count(dstPoint);
			// в итератор находит элемент с ключом даты
			it = _mmap.find(dstPoint);

			// цикл от 0 до количества дат
			for (int i = 0; i < counter; ++i, ++it)
			{
				// если найденный ключ равен введеной точки назначения то выводим на экран инфу о рейсе
				if (it->second._departureDate == depDate)
				{
					//cout << it->second.departureDate << " " << it->second.departureTime << " " << it->second.destinationPoint<< " " << it->second.arrivalTime << " " << it->second.flightNumber << endl;
					s += to_string(it->second._departureDate.Day); s += ".";
					s += to_string(it->second._departureDate.Month); s += ".";
					s += to_string(it->second._departureDate.Year); s += " ";
					s += to_string(it->second._departureTime.Hour); s += ":";
					s += to_string(it->second._departureTime.Minute); s += ":";
					s += to_string(it->second._departureTime.Second); s += " ";
					s += it->second._destPoint; s += " ";
					s += to_string(it->second._arrivalTime.Hour); s += ":";
					s += to_string(it->second._arrivalTime.Minute); s += ":";
					s += to_string(it->second._arrivalTime.Second); s += " ";
					s += to_string(it->second._flightNumber); s += "\n";
				}
			}
		}
		return s;
	}

