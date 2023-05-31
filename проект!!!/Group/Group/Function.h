#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace  std;
namespace table2 {
	struct Id {
		int id_direction;
	};

	struct Initial {
		string direction;

	};

	struct Date {
		int course;
	};

	struct Group {
		string number;
	};

	struct Data {
		Id _id;
		Initial _initial;
		Date _date;
		Group _group;
	};

	void DataEntry(Data* (&d), int& n); //¬вод данных вручную 
	void ReadingData(Data* (&d), int& n, string fileName); //чтение данных из  файла
	void Print(Data* d, int n); //ввывод данных
	void DataChange(Data* (&d), int n); //изменение данных
	void DeleteData(Data* (&d), int& n); //удаление данных
	void Copy(Data* (&d_n), Data* (&d_o), int n); //копи€ данных
	void Copy(Data& d_n, Data& d_o); //копи€ данных элемента 
	void AddDate(Data* (&d), int& n); //добавить данные
	void DataSorting(Data* d, int n); //сортировка данныых
	void SavingData(Data* d, int n, string fileName); //сохранение данных
}