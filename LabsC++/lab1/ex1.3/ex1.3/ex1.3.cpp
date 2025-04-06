#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    system("chcp 1251");
    double P, S, p;
    cout << "Введите периметр:\n";
    cin >> P;
    p = P / 2;
    double a = P / 3;
    S = sqrt(p *(p-a)*(p-a)*(p-a));
    cout.precision(2);
    std::cout << "Сторона равностороннего треугольника: " << std::setw(40) << "Площадь равностороннего треугольника:" << std::endl;;
    std::cout << a << std::setw(42) << S;
}