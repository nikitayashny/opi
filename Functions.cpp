#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "������� ���������� ������: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ���: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.name;
		cin >> d[i]._initial.patronymic;

		cout << "������� ���� (����, �����, ���): ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "______________________" << endl;

	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//������ ����� ��� ������
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
		cout << "������ �������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;
	reading.close();
}

