#include <iostream>
#include <string>
using namespace std;

int addNumbers(int n)
{
    if (n == 1) return 1;
    else return (n + addNumbers(n - 1));
}

int addNumbers(int a, int b)
{
    if (a == b) return a;
    else return (a + addNumbers(a + 1, b));
}

int gcd(int m, int k)
{
    if (k == 0) return m;
    return gcd(k, m % k);
}

int main()
{
    int n, a, b, m, k;
    cout << "Input n" << endl;
    cin >> n;
    cout << addNumbers(n) << endl;

    cout << "Input a and b" << endl;
    cin >> a >> b;
    cout << addNumbers(a, b) << endl;

    cout << "Input m and n" << endl;
    cin >> m >> k;
    cout << gcd(m, k) << endl;
    return 0;
}