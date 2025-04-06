#include <iostream>
#include <string>
using namespace std;

long double firBinSearch(double a, int n)
{
    if (a < 1 || a > 1000) {
        throw invalid_argument("a должно быть в промежутке от 1 до 1000");
    }

    if (n <= 0 || n > 10) {
        throw invalid_argument("n должно быть в промежутке от 1 до 10");
    }

    double L = 0;
    double R = a;
    while (R - L > 1e-10)
    {
        double M = (L + R) / 2;
        if (pow(M, n) < a)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return R;
}


int main()
{
    double a;
    int n;
    cout << "Input a and n" << endl;
    cin >> a >> n;


    try {
        double out = firBinSearch(a, n);
        cout << out << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}