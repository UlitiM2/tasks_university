#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string checkSnils(string in) {
    string k, s;
    int perm;

    // Удаление пробелов и дефисов
    in.erase(remove(in.begin(), in.end(), ' '), in.end());
    in.erase(remove(in.begin(), in.end(), '-'), in.end());

    // Проверка, что входная строка содержит только цифры
    bool allDigits = in.find_first_not_of("0123456789") == string::npos;

    if (!allDigits) {
        cout << "Not correct" << endl;
        return "False";
    }

    if (in.length() != 11)
    {
        cout << "Not 11" << endl;
        return "False";
    }
    else {
        k = in.substr(9, 2);
        in = in.substr(0, 9);
        perm = atoi(in.c_str());
    }

    int x = 0;
    for (int i = 1; i < 10; i++) {
        int temp = perm % 10 * i;
        x += temp;
        perm = perm / 10;
    }

    if (x < 100) {
        s = to_string(x);
    }
    else if (x == 100 || x == 101) {
        s = "00";
    }
    else if (x > 101) {
        if (x % 101 < 100) {
            s = to_string(x % 101);
        }
        else {
            s = "00";
        }
    }

    if (s == k) {
        return "True";
    }
    else {
        return "False";
    }
}

int main() {
    string in;

    cout << "Input: ";

    getline(cin, in); // Используем getline вместо cin

    cout << checkSnils(in) << endl;

}