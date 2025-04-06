#include <iostream>
#include <set>
using namespace std;


int main() {
    system("chcp 1251");
    int n;
    cout << "Введите число: "; cin >> n;
    std::set<int> primes;
    primes.insert(2);

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
            if (j == i - 1) {
                primes.insert(i);
            }
        }
        if (n % i == 0) {
            cout << "Не является суперпростым" << endl;
            break;
        }
        if (i == n - 1) {
            if (std::find(primes.begin(), primes.end(), primes.size() + 1) != primes.end()) {
                cout << "Суперпростое" << endl;
            }
            else {
                cout << "Не является суперпростым" << endl;
            }
        }
    }
}