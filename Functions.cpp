#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "Введите количество данных: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.name;
		cin >> d[i]._initial.patronymic;

		cout << "Введите дату (день, месяц, год): ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "______________________" << endl;

	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//создаём поток для чтения
	ifstream reading(fileName);

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._initial.surname;
			reading >> d[i]._initial.name;
			reading >> d[i]._initial.patronymic;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные №" << i + 1 << endl;
		cout << "ФИО: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "Дата: ";
		if (d[i]._date.day <= 9)
			cout << "0" << d[i]._date.day << " ";
		else
			cout << d[i]._date.day << " ";
		if (d[i]._date.month <= 9)
			cout << "0" << d[i]._date.month << " ";
		else
			cout << d[i]._date.month << " ";
		cout << d[i]._date.year << endl;
		cout << "_____________________" << endl;
	}
}

void DataChange(Data* (&d), int n)

{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	// проверка, что ввели правильное значение
	if (_n >= 0 && _n < n) {
		cout << "Введите ФИО: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.name;
		cin >> d[_n]._initial.patronymic;

		cout << "Введите дату: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		system("cls");

		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введён неверно!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		// временный массив
		Data* buf = new Data[n];

		Copy(buf, d, n);

		// выделяем новую память
		--n;
		d = new Data[n];
		int q = 0;

		// заполняем неудаленные данные
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;
		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введён неверно!" << endl;
}

