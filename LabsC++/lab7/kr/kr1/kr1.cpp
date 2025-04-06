#include <iostream>
#include <cmath>
using namespace std;
struct Roots {
    double x1;
    double x2;
};

Roots solve(double a, double b, double c) {
    Roots roots;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        roots.x1 = (-b + sqrt(discriminant)) / (2 * a);
        roots.x2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    else if (discriminant == 0) {
        roots.x1 = roots.x2 = -b / (2 * a);
    }
    else {
        roots.x1 = NAN;
        roots.x2 = NAN;
    }

    return roots;
}

int main() {
    system("chcp 1251");
    double a, b, c;
    cout << "Введите коэффициенты a, b, c" << endl;
    cin >> a >> b >> c;
    Roots roots = solve(a, b, c);
    if (isnan(roots.x1)) {
        cout << "Дискриминант меньше 0." << endl;
    }
    else if (roots.x1 == roots.x2) {
        cout << "Один корень: " << roots.x1 << endl;
    }
    else {
        cout << "Два корня: " << roots.x1 << ", " << roots.x2 << endl;
    }
    return 0;
}