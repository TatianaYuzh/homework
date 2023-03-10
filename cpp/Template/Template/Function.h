#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace  std;

struct Initial {
	string sutname,
		patronymic,
		name;
};

struct Date {
	int day,
		month,
		year;
};

struct Address {
	string city;
	int home;
};

//структура данных
struct Data {
	Initial _initial;
	Date _date;
	Address _address;
};

//прототипы функций
void DataEntry(Data* (&d), int& n); //ввод 
void ReadingData(Data* (&d), int& n, string fileName); //чтение из файла
void Print(Data* d, int n); //вывод
void DataChange(Data* (&d), int n); //изменение
void DeleteData(Data* (&d), int& n); //удаление
void Copy(Data* (&d_n), Data* (&d_o), int n); //копия данных
void Copy(Data& d_n, Data& d_o); //копия данных элемента
void AddDate(Data* (&d), int &n); //добавить данные
void DataSorting(Data *d, int n); //сортировка данных
void SavingData(Data* d, int n, string fileName); //сохранение данных


