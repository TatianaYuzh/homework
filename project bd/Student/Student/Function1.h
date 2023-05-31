#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace  std;

namespace table1 {

	struct Initial {
		string sutname,
			patronymic,
			name;
	};
	
	struct Ids {
		int number;
	};

	struct Date {
		int day,
			month,
			year;
	};

	struct Group {
		string number;
	};

	struct Idg {
		int number;
	};

	//��������� ������
	struct Data {
		Initial _initial;
		Ids _ids;
		Date _date;
		Group _group;
		Idg _idg;
	};

	//��������� �������
	void DataEntry(Data* (&d), int& n); //���� 
	void ReadingData(Data* (&d), int& n, string fileName); //������ �� �����
	void Print(Data* d, int n); //�����
	void DataChange(Data* (&d), int n); //���������
	void DeleteData(Data* (&d), int& n); //��������
	void Copy(Data* (&d_n), Data* (&d_o), int n); //����� ������
	void Copy(Data& d_n, Data& d_o); //����� ������ ��������
	void AddDate(Data* (&d), int& n); //�������� ������
	void DataSorting(Data* d, int n); //���������� ������
	void SavingData(Data* d, int n, string fileName); //���������� ������


}



