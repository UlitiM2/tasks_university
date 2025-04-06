#include <iostream>
#include <string>
using namespace std;

void show(const int a[], const int n);
bool from_min(const int a, const int b);
bool from_max(const int a, const int b);

void bubble_sort(int a[], const int n, bool (*compare)(int a, int b));
int main() {
    system("chcp 1251");
    bool (*from_f[2]) (int, int) = { from_min, from_max };
    int flag = 0;
    const int n = 10;

    int a[n] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    cout << "1. Сортировка по возрастанию\n";
    cout << "2. Сортировка по убыванию\n";

    cout << "Ваш выбор: ";
    cin >> flag;
    cout << "Исходный массив: " << endl;

    show(a, n);

    /*    switch (flag)
    {
    case 1:
        bubble_sort(a, n, from_min);
        break;

    case 2:
        bubble_sort(a, n, from_max);
        break;

    default:
        cout << "\rТакого варианта нет ";
    }*/

    bubble_sort(a, n, from_f[flag - 1]);

    cout << "Отсортированный массив: " << endl;
    show(a, n);

}


void show(const int a[], const int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool from_min(const int a, const int b) {

    return a > b;

}

bool from_max(const int a, const int b) {

    return a < b;

}

void bubble_sort(int a[], const int n, bool (*compare)(int a, int b)) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if ((*compare)(a[j], a[j + 1])) swap(a[j], a[j + 1]);
        }
    }
}