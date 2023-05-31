#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace  std;

namespace table2 {

	struct Idg {
		int number;
	};

	struct Group {
		string number;
	};

	struct Cource {
		int number;
	};

	struct Direction {
		string number;
	};

	struct Idd {
		int number;
	};


	//структура данных
	struct Data {
		Idg _idg;
		Group _group;
		Cource _cource;
		Direction _direction;
		Idd _idd;
	};

	//прототипы функций
	void DataEntry(Data* (&d), int& n); //ввод 
	void ReadingData(Data* (&d), int& n, string fileName); //чтение из файла
	void Print(Data* d, int n); //вывод
	void DataChange(Data* (&d), int n); //изменение
	void DeleteData(Data* (&d), int& n); //удаление
	void Copy(Data* (&d_n), Data* (&d_o), int n); //копия данных
	void Copy(Data& d_n, Data& d_o); //копия данных элемента
	void AddDate(Data* (&d), int& n); //добавить данные
	void SavingData(Data* d, int n, string fileName); //сохранение данных


}



