#include "Console.h"
int Console::init() {
	// Переменная для результата исключения
	bool error = false;

	FlightSchedule objFS;

	// Выбор работы с вектором и словарём
	cout << "0 - работа с вектором \n1 - работа со словарём" << endl;
	cout << "Выберете режим работы: ";
	int answMode;
	cin >> answMode;

	// Проверка на корректность выбора контейнера
	if (answMode != 1 && answMode != 0)
	{
		cout << "Нет такого режима работы!" << endl;
		return 0;
	}

	// Передать номер контейнера, с которым будем работать
	objFS.choice(answMode);

	// Проверка открытия файла через throw-try-catch
	string namefile = "input.txt";
	try
	{
		readingfile(namefile, objFS);
	}
	catch (exception * e)
	{
		cout << e << endl;
		error = true;
	}
	if (error)
		return 0;

	// Ввод даты и пукнта назначения
	string destonation;
	Date data;
	char c;
	cout << "Введите дату отправления и пункт назначения рейса через пробел: ";
	cin >> data.Day >> c >> data.Month >> c >> data.Year;
	cin >> destonation;
	cout << objFS.printinfo(data, destonation);
}