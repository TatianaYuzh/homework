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

	void DataEntry(Data* (&d), int& n); //���� ������ ������� 
	void ReadingData(Data* (&d), int& n, string fileName); //������ ������ ��  �����
	void Print(Data* d, int n); //������ ������
	void DataChange(Data* (&d), int n); //��������� ������
	void DeleteData(Data* (&d), int& n); //�������� ������
	void Copy(Data* (&d_n), Data* (&d_o), int n); //����� ������
	void Copy(Data& d_n, Data& d_o); //����� ������ �������� 
	void AddDate(Data* (&d), int& n); //�������� ������
	void DataSorting(Data* d, int n); //���������� �������
	void SavingData(Data* d, int n, string fileName); //���������� ������
}