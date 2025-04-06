#include <iostream>
#include <string>
using namespace std;

void show(const int a[], const int n);
bool from_min(const int a, const int b);
bool from_max(const int a, const int b);

void bubble_sort(int a[], const int n, bool (*compare)(int a, int b));
int main() {
    system("chcp 1251");

    int n;
    cout << "Количество элементов в массиве: ";
    cin >> n;

    int* a = new int[n];

    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int flag = 0;

    cout << "1. Сортировка по возрастанию\n";
    cout << "2. Сортировка по убыванию\n";

    cout << "Ваш выбор: ";
    cin >> flag;
    cout << "Исходный массив: " << endl;

    show(a, n);

    switch (flag)
    {
    case 1:
        bubble_sort(a, n, from_min);
        break;

    case 2:
        bubble_sort(a, n, from_max);
        break;

    default:
        cout << "\rТакого варианта нет ";
    }


    cout << "Отсортированный массив: " << endl;
    show(a, n);


    delete[] a;
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