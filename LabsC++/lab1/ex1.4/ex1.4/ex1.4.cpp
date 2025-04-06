#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	double x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
	double S1, S;
	cout << "Введите координаты первой точки: \n";
	cin >> x1;
	cin >> y1;
	cout << "Введите координаты второй точки: \n";
	cin >> x2;
	cin >> y2;
	cout << "Введите координаты третьей точки: \n";
	cin >> x3;
	cin >> y3;
	cout << "Введите координаты четвертой точки: \n";
	cin >> x4;
	cin >> y4;
	cout << "Введите координаты пятой точки: \n";
	cin >> x5;
	cin >> y5;
	S1 = x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5;
	S = abs(S1) / 2;
	cout << "Площадь " << S;
}