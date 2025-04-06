#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    system("chcp 1251");
    string line;
    ofstream file("text.txt");
    if (!file) {
        cerr << "Ошибка\n";
        return 1;
    }
    cout << "Введите стихотворение:\n Введите 1 для выхода\n";
    while (getline(cin, line)) {
        if (line == "1") {
            break;
        }
        file << line << "\n";
    }
    file.close();
    return 0;
}