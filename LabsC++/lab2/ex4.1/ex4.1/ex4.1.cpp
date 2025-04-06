#include <iostream>
using namespace std;

int main() {
    system("chcp 1251");
    int k, m, s;

    cout << "k = "; cin >> k;
    cout << "m = "; cin >> m;


    s = 0;
    for (int i = 1; i <= 100; i++) {
        if ((i > k) && (i < m)) {
            continue;
        }
        s += i;
    }

    cout << "s = " << s << endl;
}