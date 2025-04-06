#include <iostream>
#include <string>
using namespace std;

int sumR(int n) {
    if (n == 1) return 5;
    else return (5 * n + sumR(n - 1));
}

int main() {
    system("chcp 1251");
    int n;
    cout << "Input n" << endl;
    cin >> n;
    cout << sumR(n) << endl;
    return 0;
}