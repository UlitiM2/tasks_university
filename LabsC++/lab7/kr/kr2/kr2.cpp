#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;
typedef tuple<double, double, bool> Solution;

Solution solve(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        return make_tuple(x1, x2, true );
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        return make_tuple(root, root, true );
    }
    else {
        return make_tuple( NAN, NAN, false );
    }
}
void printTupleOfThree(Solution t) {
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ", "
        << (get<2>(t) ? "true" : "false") << ")" << endl;
}
int main() {
    system("chcp 1251");
    double a, b, c;
    cout << "Введите коэффициенты a, b, c" << endl;
    cin >> a >> b >> c;
    auto solution = solve(a, b, c);
    printTupleOfThree(solution);
    return 0;
}