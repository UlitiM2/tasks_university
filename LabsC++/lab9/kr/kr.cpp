#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Triangle {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double a, double b, double c) {
        if (!isValid(a, b, c)) {
            throw invalid_argument("Недопустимая длина сторон треугольника");
        }
        sideA = a;
        sideB = b;
        sideC = c;
    }

    bool isValid(double a, double b, double c) {
        return (a < b + c && b < a + c && c < a + b);
    }

    double area() {
        double p = (sideA + sideB + sideC) / 2;  
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }
};

int main() {
    system("chcp 1251");
    try {
        Triangle triangle1(3, 4, 5);  
        //Triangle triangle2(1, 1, 50); 
        double s1, s2;
        s1 = triangle1.area();
        //s2 = triangle2.area();
        cout << "Площадь треугольника: " << s1 << endl;
       // cout << "Площадь треугольника: " << s2 << endl;
    }
    catch (const std::exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
