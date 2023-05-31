#include "Function.h"
#include <locale>

void table2::DataEntry(Data* (&d), int& n) {
	cout << "введите количество данных";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите id направления ";
		cin >> d[i]._id.id_direction;

		cout << "Введите Направление ";
		cin >> d[i]._initial.direction;

		cout << "Введите курс: ";
		cin >> d[i]._date.course;


		cout << "Введите номер группы ";
		cin >> d[i]._group.number;

		cout << "_________________________________" << endl;
	}
}
void ReadingData(Data* (&d), int& n, string fileName) {
	ifstream reading(fileName);
	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._id.id_direction;

			reading >> d[i]._initial.direction;

			reading >> d[i]._date.course;

			reading >> d[i]._group.number;
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "ошибка открытия файла!" << endl;
	reading.close();
}
void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "данные № ¹" << i + 1 << ":" << endl;

		cout << "номер: " << d[i]._id.id_direction << endl;
		cout << "Направление" << d[i]._initial.direction << endl;
		cout << "курс" << d[i]._date.course << endl;
		cout << "номер группы: " << d[i]._group.number << endl;

		cout << "______________________________" << endl;
	}
}
void DataChange(Data* (&d), int n) {

	int _n;
	cout << "введите номер (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		cout << "введите Направление: ";
		cin >> d[_n]._initial.direction;

		cout << "введите курс: ";
		cin >> d[_n]._date.course;

		cout << "введите номер группы: ";
		cin >> d[_n]._group.number;

		system("cls");

		cout << "данные изменены" << endl;
	}
	else
		cout << "номер введен не верно" << endl;
}
void DeleteData(Data* (&d), int& n) {

	int _n;
	cout << "введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//проверка на правильность введеных данных
	if (_n >= 0 && _n < n) {

		//временный массив 
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//выделяем новую память
		--n;
		d = new Data[n];

		int q = 0;

		//запоминаем данные кроме не нужного 
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "данные удалены!" << endl;
	}
	else
		cout << "номер введен не верно !" << endl;

}
void Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
void Copy(Data& d_n, Data& d_o) {
	d_n._id.id_direction = d_o._id.id_direction;

	d_n._initial.direction = d_o._initial.direction;

	d_n._date.course = d_o._date.course;


	d_n._group.number = d_o._group.number;

}
void AddDate(Data* (&d), int& n) {
	//временный массив данных
	Data* buf;
	buf = new Data[n];

	//сохраняем данные в временный масив
	Copy(buf, d, n);

	//выделяем новую память
	n++;
	d = new Data[n];

	//возвращаем данные
	Copy(d, buf, --n);

	cout << "введите номер";
	cin >> d[n]._id.id_direction;

	cout << "введите Направление: ";
	cin >> d[n]._initial.direction;

	cout << "введите дату: ";
	cin >> d[n]._date.course;

	cout << "введите номер группы: ";
	cin >> d[n]._group.number;

	system("cls");

	cout << "данные добавлены!" << endl;

	delete[]buf;
}
void DataSorting(Data* d, int n) {
	//временная переменная 
	Data buf;

	//сортировка пузырьком
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.direction > d[j]._initial.direction) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "данные отсортированны" << endl;

}
void SavingData(Data* d, int n, string fileName) {
	//создаем поток для записи
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._id.id_direction << endl;

			record << d[i]._initial.direction << endl;

			record << d[i]._date.course << endl;

			record << d[i]._group.number << endl;

		}
	}
	else
		cout << "ошибка открытия файла !" << endl;

	record.close();
}