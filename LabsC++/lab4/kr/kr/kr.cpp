#include <iostream>
#include <string>
using namespace std;

int Myroot(double, double, double, double&, double&);

int main()
{
    system("chcp 1251");
    double a, b, c, x1, x2;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    int res = Myroot(a, b, c, x1, x2);
    if (res == 0) {
        cout << "Корень уравнения один и он равен: " << x1 << endl;
    }
    else if (res == -1) {
        cout << "Корней уравнения нет" << endl;
    }
    else if (res == 1) {
        cout << "Корни уравнения: " << x1 << " и " << x2 << endl;
    }
    return 0;
}


int Myroot(double a, double b, double c, double& x1, double& x2) {
    double d = b * b - 4 * a * c;
    if (d < 0) return -1;
    if (d == 0) {
        x1 = x2 = -b / (2 * a);
        return 0;
    }
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    return 1;
}