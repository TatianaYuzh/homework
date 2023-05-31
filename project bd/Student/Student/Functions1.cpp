#include "Function1.h"

void table1::DataEntry(Data* (&d), int& n) {
	std::cout << "������� ���������� ������: ";
	std::cin >> n;

	d = new Data[n];


	for (int i = 0; i < n; i++) {

		std::cout << "������� ���: ";
		std::cin >> d[i]._initial.sutname;
		std::cin >> d[i]._initial.patronymic;
		std::cin >> d[i]._initial.name;

		std::cout << "������� Id ��������: ";
		std::cin >> d[i]._ids.number;

		std::cout << "������� ����: ";
		std::cin >> d[i]._date.day;
		std::cin >> d[i]._date.month;
		std::cin >> d[i]._date.year;

		std::cout << "������� ������: ";
		std::cin >> d[i]._group.number;

		std::cout << "������� Id ������: ";
		std::cin >> d[i]._idg.number;

		std::cout << "_________________________________" << endl;
	};

}
void table1::ReadingData(Data* (&d), int& n, string fileName) {
	ifstream reading(fileName);
	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
	
			reading >> d[i]._initial.sutname;
			reading >> d[i]._initial.patronymic;
			reading >> d[i]._initial.name;

			reading >> d[i]._ids.number;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;

			reading >> d[i]._group.number;

			reading >> d[i]._idg.number;

		}
		std::cout << "������ �������!" << endl;
	}
	else
		std::cout << "������ �������� �����!" << endl;
	reading.close();
}
void table1::Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "������ �" << i + 1 << ":" << endl;

		std::cout << "Id ��������: " << d[i]._ids.number/*abs(d[i]._ids.number + rand())*/ << endl;
		std::cout << "���: " << d[i]._initial.sutname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		std::cout << "����: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		std::cout << "������: " << d[i]._group.number << endl;
		std::cout << "Id ������: " << d[i]._idg.number/*abs(d[i]._idg.number + rand())*/ << endl;

		std::cout << "______________________________" << endl;
	}
}
void table1::DataChange(Data* (&d), int n) {

	int _n;
	std::cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	std::cin >> _n;
	_n--;

	std::system("cls");

	//��������, ��� ����� �������� ���������
	if (_n >= 0 && _n < n) {
		std::cout << "������� ���: ";
		std::cin >> d[_n]._initial.sutname;
		std::cin >> d[_n]._initial.patronymic;
		std::cin >> d[_n]._initial.name;

		std::cout << "������� ����: ";
		std::cin >> d[_n]._date.day;
		std::cin >> d[_n]._date.month;
		std::cin >> d[_n]._date.year;

		std::cout << "������� ������: ";
		std::cin >> d[_n]._group.number;

		std::system("cls");

		std::cout << "������ ��������!" << endl;
	}
	else
		cout << "����� ������ �� �����!" << endl;
}
void table1::DeleteData(Data* (&d), int& n) {

	int _n;
	std::cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	std::cin >> _n;
	_n--;

	std::system("cls");

	//��������, ��� ����� �������� ���������
	if (_n >= 0 && _n < n) {

		//��������� ������
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//������� ����� ������
		--n;
		d = new Data[n];

		int q = 0;

		//���������� ������ �� ����������� ���������
		for (int i = 0; i <= n;i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		std::system("cls");
		delete[]buf;

		std::cout << "������ �������!" << endl;
	}
	else
		std::cout << "����� ������ �� �����!" << endl;

}
void table1::Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0;i < n;i++) {
		d_n[i] = d_o[i];
	}
}
void table1::Copy(Data& d_n, Data& d_o) {
	
	d_n._initial.sutname = d_o._initial.sutname;
	d_n._initial.patronymic = d_o._initial.patronymic;
	d_n._initial.name = d_o._initial.name;
	
	d_n._ids.number = d_o._ids.number;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;

	d_n._group.number = d_o._group.number;

	d_n._idg.number = d_o._idg.number;

}
void table1::AddDate(Data* (&d), int& n) {
	//��������� ������ ������
	Data* buf;
	buf = new Data[n];

	//��������� ������ � ��������� ������
	Copy(buf, d, n);

	//�������� ����� ������
	n++;
	d = new Data[n];

	//����������� ������
	Copy(d, buf, --n);

	cout << "������� ���: ";
	cin >> d[n]._initial.sutname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "������� Id ��������: ";
	cin >> d[n]._ids.number;

	cout << "������� ����: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	cout << "������� ������: ";
	cin >> d[n]._group.number;

	cout << "������� Id ������: ";
	cin >> d[n]._idg.number;

	system("cls");

	cout << "������ ���������!" << endl;

	delete[]buf;
}
void table1::DataSorting(Data* d, int n) {
	//��������� ���������� 
	Data buf;

	//���������� ���������
	for (int i = 0; i < n; i++) {
		for (int j = i + 1;j < n;j++) {
			if (d[i]._initial.sutname > d[j]._initial.sutname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "������ �������������!" << endl;

}
void table1::SavingData(Data* d, int n, string fileName) {
	//��������� ����� ��� ������
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			
			record << d[i]._initial.sutname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._ids.number << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year << endl;

			record << d[i]._group.number << endl;

			record << d[i]._idg.number << endl;

		}
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
}



