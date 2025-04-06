#include <iostream>
#include <string>
using namespace std;

void decimalToBinary(int num) {
    if (num > 0) {
        decimalToBinary(num / 2); // рекурсивный вызов
        cout << num % 2; // вывод остатка
    }
}

int main() {
    system("chcp 1251");
    int num;
    cout << "Input num" << endl;
    cin >> num;
    decimalToBinary(num);
    return 0;
}