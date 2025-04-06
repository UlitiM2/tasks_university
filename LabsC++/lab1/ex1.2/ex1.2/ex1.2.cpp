#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	string name;
	cout << "Введите свое имя\n";
	double a, b;
	cout << "Введите a и b:\n";
	cin >> a; // ввод с клавиатуры значения a
	cin >> name;
	cin >> b; // ввод с клавиатуры значения b
	double x = a / b; // вычисление значения x
	cout.precision(3);
	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << "\n память a/b = " << sizeof(a / b) << ends << "\n память x= " << sizeof(x) << endl;
	cout << "Привет, " << name << "!\n";
	return 0;
}