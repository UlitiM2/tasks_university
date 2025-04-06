#include <iostream>
#include <string>
using namespace std;
class DivideByZeroError
{
public:
	DivideByZeroError() : message("Деление на нуль") { }
	void printMessage() const { cout << message << endl; }
private:
	string message;
};


float quotient(int numl, int num2)
{
	if (num2 == 0)
		throw DivideByZeroError();
	return (float)numl / num2;
}

int main()
{
	system("chcp 1251");
	cout << "Введите одно число для расчета частного:\n";
	int number1;
	cin >> number1;
	for (int i = -10; i < 10; i++)
	{
		try
		{
			float result = quotient(number1, i);
			cout << "Частное равно " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "ОШИБКА: ";
			error.printMessage();
		}
	}
	return 0; // нормальное завершение программы
}


