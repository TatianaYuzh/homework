#include "Function2.h"
#include "Function1.h"

void table2::DataEntry(Data* (&d), int& n) {
	std::cout << "������� ���������� ������: ";
	std::cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {

		std::cout << "������� ����: ";
		std::cin >> d[i]._cource.number;

		std::cout << "������� �����������: ";
		std::cin >> d[i]._direction.number;

		std::cout << "������� Id �����������: ";
		std::cin >> d[i]._idd.number;

		std::cout << "_________________________________" << endl;
	}
}

void table2::ReadingData(Data* (&d), int& n, string fileName) {
	ifstream reading(fileName);
	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {

			reading >> d[i]._idg.number;

			reading >> d[i]._group.number;

			reading >> d[i]._cource.number;

			reading >> d[i]._direction.number;

			reading >> d[i]._idd.number;
		}
		std::cout << "������ �������!" << endl;
	}
	else
		std::cout << "������ �������� �����!" << endl;
	reading.close();
}

void table2::Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "������ �" << i + 1 << ":" << endl;

		std::cout << "Id ������: " << d[i]._idg.number << endl;
		std::cout << "������: " << d[i]._group.number << endl;
		std::cout << "����: " << d[i]._cource.number << endl;
		std::cout << "�����������: " << d[i]._direction.number << endl;
		std::cout << "Id �����������: " << d[i]._idd.number << endl;

		std::cout << "______________________________" << endl;
	}
}
void table2::DataChange(Data* (&d), int n) {

	int _n;
	std::cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	std::cin >> _n;
	_n--;

	std::system("cls");

	//��������, ��� ����� �������� ���������
	if (_n >= 0 && _n < n) {
		std::cout << "������� ����: ";
		std::cin >> d[_n]._cource.number;

		std::cout << "������� �����������: ";
		std::cin >> d[_n]._direction.number;

		std::system("cls");

		std::cout << "������ ��������!" << endl;
	}
	else
		std::cout << "����� ������ �� �����!" << endl;
}
void table2::DeleteData(Data* (&d), int& n) {

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
void table2::Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0;i < n;i++) {
		d_n[i] = d_o[i];
	}
}
void table2::Copy(Data& d_n, Data& d_o) {
	d_n._idg.number = d_o._idg.number;

	d_n._group.number = d_o._group.number;

	d_n._cource.number = d_o._cource.number;

	d_n._direction.number = d_o._direction.number;

	d_n._idd.number = d_o._idd.number;

}
void table2::AddDate(Data* (&d), int& n) {
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

	cout << "������� ����: ";
	cin >> d[n]._cource.number;

	cout << "������� �����������: ";
	cin >> d[n]._direction.number;

	cout << "������� Id �����������: ";
	cin >> d[n]._idd.number;

	system("cls");

	cout << "������ ���������!" << endl;

	delete[]buf;
}

void table2::SavingData(Data* d, int n, string fileName) {
	//��������� ����� ��� ������
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._cource.number << endl;

			record << d[i]._direction.number << endl;

			record << d[i]._idd.number << endl; 

		}
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
}

