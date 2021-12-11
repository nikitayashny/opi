﻿#include "Functions.h"

int _stateMenu;

void Menu() {
	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Выборочное удаление" << endl
		<< "(5) Удаление всех файлов" << endl
		<< "(6) Добавление" << endl
		<< "(7) Сортировка по фамилии" << endl
		<< "(8) Поиск по фамилии" << endl
		<< "(9) Сохранение в файле" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

int main() {
	// руссификация консоли ввода и вывода 
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // утсановка кодов страницы win-cp 1251 в поток вывода

	Menu();

	// инициализация данных
	int _actions,
		amountOfData = 0;
	string fileName, surname;

	// массив данных
	Data* d = new Data[amountOfData];
	while (_stateMenu != 0) {

		switch (_stateMenu)
		{
		case 1:
			system("cls"); // очистка консоли
			cout << "Ввод вручную, из Input.txt или из другого файла(1 - вручную, 2 - из Input.txt, 3 - другой файл): ";
			cin >> _actions;
			system("cls");

			if (_actions == 1) {
				//ввод вручную
				DataEntry(d, amountOfData);
			}

			if (_actions == 2){
				//ввод из файла
				ReadingData(d, amountOfData, "Input.txt");
			}

			if (_actions == 3) {
				//ввод из собственного файла
				cout << "Введите название файла: ";
				cin >> fileName;
				ReadingData(d, amountOfData, fileName);
			}

			if (_actions != 1 && _actions != 2 && _actions != 3) {
				cout << "Неверно введен номер действия!" << endl;
			}

			system("pause"); // задержка консоли
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		default:
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}