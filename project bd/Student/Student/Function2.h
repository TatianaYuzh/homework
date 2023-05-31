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


	//��������� ������
	struct Data {
		Idg _idg;
		Group _group;
		Cource _cource;
		Direction _direction;
		Idd _idd;
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
	void SavingData(Data* d, int n, string fileName); //���������� ������


}



