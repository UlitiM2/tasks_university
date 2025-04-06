#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    system ("chcp 1251");
    double x, y;

    cout << "Введите два числа: ";
    cin >> x >> y;

    if (x * x + y * y < 9 && y > 0) {
        cout << "Внутри" << endl;
    }
    else if (x * x + y * y > 9 || y < 0) {
        cout << "Вне" << endl;
    }
    else {
        cout << "На границе" << endl;
    }
}