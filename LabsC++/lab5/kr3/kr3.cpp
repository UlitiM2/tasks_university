#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    system("chcp 1251");
    if (argc < 4) {
        cerr << "Ошибка." << endl;
        return 1;
    }
    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0) {
        cerr << "Ошибка." << endl;
        return 1;
    }
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    if (num1 == 0 || num2 == 0) {
        cerr << "Ошибка." << endl;
        return 1;
    }
    if (strncmp(argv[1], "-a", 2) == 0) {
        cout << "Сумма: " << num1 + num2 << endl;
    }
    else if (strncmp(argv[1], "-m", 2) == 0) {
        cout << "Произведение: " << num1 * num2 << endl;
    }
    return 0;
}