#include <iostream>
using namespace std;

int main() {
    system("chcp 1251");
    int s;

    cout << "Введите сумму = "; cin >> s;
    int out_10, out_5, out_2, out, out_1;
    out_10 = s / 10;
    out_5 = (s % 10) / 5;
    out_2 = ((s % 10) % 5) / 2;
    out_1 = ((s % 10) % 5) % 2;

    out = out_10 + out_5 + out_2 + out_1;
    cout << "Количество монет = " << out << endl;
    cout << "10:" << out_10 << endl;
    cout << "5:" << out_5 << endl;
    cout << "2:" << out_2 << endl;
    cout << "1:" << out_1 << endl;
}