// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// Структура "Полёт"
struct Flight
{
	string departureDate;		// Дата отправления
	string departureTime;		// Время отправления
	string destinationPoint;	// Пункт назначения
	string arrivalTime;			// Время прибытия
	string flightNumber;		// Номер рейса
};

// Класс FlightSchedule
class FlightSchedule
{
public:
	FlightSchedule() {};
	~FlightSchedule() {};
public:
	// Функция выбора работы контейнера, если вводим 0, то работаем с вектором, если 1 то со словарём
	void choice(int nmode)
	{
		mode = nmode;
	}
public:
	// Функция проверяет корректность файла throw-try-catch
	void readingfile(string& namefile)		// exception
	{
		// Проверка файл на существование
		ifstream fin(namefile);
		if (!fin.is_open())
			throw new exception("Ошибка открытия файла"); //exception

		// Временные строки для считывания строк из файла
		string depDate, depTime, dstPoint, arrTime, flightNo;
		

		// Пока не конец файла, мы будем считывать строки
		while (!fin.eof())
		{
			// Считываем строку
			fin >> depDate >> depTime >> dstPoint >> arrTime >> flightNo;
			//cout << depDate << depTime << dstPoint << arrTime << flightNo;
			// Если был выбран вектор, то заносим в вектор строку
			if (mode == WORK_MODE_VECTOR)
				vector.push_back({ depDate, depTime, dstPoint, arrTime, flightNo });

			// Если был выбран словарь, то вставляем в словарь пару в виде строки (дата) и структура (вся строка рейса)
			else if (mode == WORK_MODE_MAP)
			{
				mmap.insert(pair<string, Flight>(depDate, { depDate, depTime, dstPoint, arrTime, flightNo }));
			}
		}

		// Закрытие файла
		fin.close();
	}

private:
	// Структура SearchData
	struct SearchData
	{
		// Строка с искомыми датами и городом
		string searchDate;
		string searchDst;

		// Конструктор структуры
		SearchData(string searchDate, string searchDst) : searchDate(searchDate), searchDst(searchDst) {}

		// Перегруженный оператор
		bool operator()(Flight temp)
		{
			return temp.departureDate == searchDate && temp.destinationPoint == searchDst;
		}
	};

public:
	// Функция вывода на экран рейсов
	void printinfo(string& depDate, string& dstPoint)
	{
		// Если выбрали вектор
		if (mode == WORK_MODE_VECTOR)
		{
			// Создаем итератор на первый элемент
			auto it = vector.begin();

			// Пока не последний элемент
			while (it != vector.end())
			{
				// ищем вхождение от начала до конца структуры такой же даты и места
				it = find_if(it, vector.end(), SearchData(depDate, dstPoint));
				// если итератор не конец то есть что то нашли мы выводим на экран данный рейс
				if (it != vector.end())
				{
					//cout << it->flightNo << " " << it->departureTime << " " << it->arrivalTime << endl;
					cout << it->departureDate << " " << it->departureTime << " " << it->destinationPoint << " "
						<< it->arrivalTime << " " << it->flightNumber << endl;
					it++;
				}
			}
		}

		// если был выбран словар
		else if (mode == WORK_MODE_MAP)
		{
			// создаем итератор на начало
			auto it = mmap.begin();
			// в счетчик = количество введенных дат в мапе
			int counter = mmap.count(depDate);
			// в итератор находит элемент с ключом даты
			it = mmap.find(depDate);

			// цикл от 0 до количества дат
			for (int i = 0; i < counter; ++i, ++it)
			{
				// если найденный ключ равен введеной точки назначения то выводим на экран инфу о рейсе
				if (it->second.destinationPoint == dstPoint)
					cout << it->second.departureDate << " " << it->second.departureTime << " " << it->second.destinationPoint
					<< " " << it->second.arrivalTime << " " << it->second.flightNumber << endl;
			}
		}
	}

private:
	// Переменная для выбора контейнера
	int mode = 0;

	// Флаги для выбора действий
	const int WORK_MODE_VECTOR = 0;
	const int WORK_MODE_MAP = 1;

	// Вектор и словарь типа структуры "Полёт"
	vector<Flight> vector;
	multimap<string, Flight> mmap;
};

int main()
{
	// Переменная для результата исключения
	bool error = false;
	setlocale(LC_ALL, "RUS");
	FlightSchedule objFS;

	// Выбор работы с вектором и словарём
	cout << "0 - работа с вектором \n1 - работа со словарём" << endl;
	cout << "Выберете режим работы: ";
	int answMode;
	cin >> answMode;

	// Проверка на корректность выбора контейнера
	if (answMode > 1)
	{
		cout << "Нет такого режима работы!" << endl;
		system("pause>nul");
		exit(1);
	}

	// Передать номер контейнера, с которым будем работать
	objFS.choice(answMode);

	// Проверка открытия файла через throw-try-catch
	string namefile = "input.txt";
	try
	{
		objFS.readingfile(namefile);
	}
	catch (exception * e)
	{
		cout << e << endl;
		system("pause>nul");
		error = true;
	}
	if (error)
		return 0;

	// Ввод даты и пукнта назначения
	string data, destonation;
	cout << "Введите дату отправления и пункт назначения рейса через пробел: ";
	cin >> data >> destonation;
	objFS.printinfo(data, destonation);

	system("pause>nul");
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
