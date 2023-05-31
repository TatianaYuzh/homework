#include "Function2.h"
#include "Function1.h"

void table2::DataEntry(Data* (&d), int& n) {
	std::cout << "Введите количество данных: ";
	std::cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {

		std::cout << "Введите курс: ";
		std::cin >> d[i]._cource.number;

		std::cout << "Введите направление: ";
		std::cin >> d[i]._direction.number;

		std::cout << "Введите Id направления: ";
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
		std::cout << "Данные считаны!" << endl;
	}
	else
		std::cout << "Ошибка открытия файла!" << endl;
	reading.close();
}

void table2::Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Данные №" << i + 1 << ":" << endl;

		std::cout << "Id группы: " << d[i]._idg.number << endl;
		std::cout << "Группа: " << d[i]._group.number << endl;
		std::cout << "Курс: " << d[i]._cource.number << endl;
		std::cout << "Направление: " << d[i]._direction.number << endl;
		std::cout << "Id направления: " << d[i]._idd.number << endl;

		std::cout << "______________________________" << endl;
	}
}
void table2::DataChange(Data* (&d), int n) {

	int _n;
	std::cout << "Введите номер элемента (от 1 до " << n << "): ";
	std::cin >> _n;
	_n--;

	std::system("cls");

	//проверка, что ввели значение правильно
	if (_n >= 0 && _n < n) {
		std::cout << "Введите курс: ";
		std::cin >> d[_n]._cource.number;

		std::cout << "Введите направление: ";
		std::cin >> d[_n]._direction.number;

		std::system("cls");

		std::cout << "Данные изменены!" << endl;
	}
	else
		std::cout << "Номер введен не верно!" << endl;
}
void table2::DeleteData(Data* (&d), int& n) {

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

	cout << "Введите курс: ";
	cin >> d[n]._cource.number;

	cout << "Введите направление: ";
	cin >> d[n]._direction.number;

	cout << "Введите Id направления: ";
	cin >> d[n]._idd.number;

	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[]buf;
}

void table2::SavingData(Data* d, int n, string fileName) {
	//создается поток для записи
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
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}

