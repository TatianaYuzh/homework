#include "Function1.h"

void table1::DataEntry(Data* (&d), int& n) {
	std::cout << "Введите количество данных: ";
	std::cin >> n;

	d = new Data[n];


	for (int i = 0; i < n; i++) {

		std::cout << "Введите ФИО: ";
		std::cin >> d[i]._initial.sutname;
		std::cin >> d[i]._initial.patronymic;
		std::cin >> d[i]._initial.name;

		std::cout << "Введите Id студента: ";
		std::cin >> d[i]._ids.number;

		std::cout << "Введите дату: ";
		std::cin >> d[i]._date.day;
		std::cin >> d[i]._date.month;
		std::cin >> d[i]._date.year;

		std::cout << "Введите группу: ";
		std::cin >> d[i]._group.number;

		std::cout << "Введите Id группы: ";
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
		std::cout << "Данные считаны!" << endl;
	}
	else
		std::cout << "Ошибка открытия файла!" << endl;
	reading.close();
}
void table1::Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Данные №" << i + 1 << ":" << endl;

		std::cout << "Id студента: " << d[i]._ids.number/*abs(d[i]._ids.number + rand())*/ << endl;
		std::cout << "ФИО: " << d[i]._initial.sutname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		std::cout << "Дата: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		std::cout << "Группа: " << d[i]._group.number << endl;
		std::cout << "Id группы: " << d[i]._idg.number/*abs(d[i]._idg.number + rand())*/ << endl;

		std::cout << "______________________________" << endl;
	}
}
void table1::DataChange(Data* (&d), int n) {

	int _n;
	std::cout << "Введите номер элемента (от 1 до " << n << "): ";
	std::cin >> _n;
	_n--;

	std::system("cls");

	//проверка, что ввели значение правильно
	if (_n >= 0 && _n < n) {
		std::cout << "Введите ФИО: ";
		std::cin >> d[_n]._initial.sutname;
		std::cin >> d[_n]._initial.patronymic;
		std::cin >> d[_n]._initial.name;

		std::cout << "Введите дату: ";
		std::cin >> d[_n]._date.day;
		std::cin >> d[_n]._date.month;
		std::cin >> d[_n]._date.year;

		std::cout << "Введите группу: ";
		std::cin >> d[_n]._group.number;

		std::system("cls");

		std::cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;
}
void table1::DeleteData(Data* (&d), int& n) {

	int _n;
	std::cout << "Введите номер элемента (от 1 до " << n << "): ";
	std::cin >> _n;
	_n--;

	std::system("cls");

	//проверка, что ввели значение правильно
	if (_n >= 0 && _n < n) {

		//временный массив
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//выделим новую память
		--n;
		d = new Data[n];

		int q = 0;

		//заполнение данных за исключением ненужного
		for (int i = 0; i <= n;i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		std::system("cls");
		delete[]buf;

		std::cout << "Данные удалены!" << endl;
	}
	else
		std::cout << "Номер введен не верно!" << endl;

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
	//временный массив данных
	Data* buf;
	buf = new Data[n];

	//сохраняем данные в временный массив
	Copy(buf, d, n);

	//выделяем новую память
	n++;
	d = new Data[n];

	//воззвращяем данные
	Copy(d, buf, --n);

	cout << "Введите ФИО: ";
	cin >> d[n]._initial.sutname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "Введите Id студента: ";
	cin >> d[n]._ids.number;

	cout << "Введите дату: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	cout << "Введите группу: ";
	cin >> d[n]._group.number;

	cout << "Введите Id группы: ";
	cin >> d[n]._idg.number;

	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[]buf;
}
void table1::DataSorting(Data* d, int n) {
	//временная переменная 
	Data buf;

	//сортировка пузырьком
	for (int i = 0; i < n; i++) {
		for (int j = i + 1;j < n;j++) {
			if (d[i]._initial.sutname > d[j]._initial.sutname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "Данные отсортированы!" << endl;

}
void table1::SavingData(Data* d, int n, string fileName) {
	//создается поток для записи
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
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}



