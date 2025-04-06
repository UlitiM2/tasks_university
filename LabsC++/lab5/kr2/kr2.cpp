#include <iostream>

using namespace std;

int Transposition(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (i > 0) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
            return i;
        }
    }
    return -1;
}

int main() {
    system("chcp 1251");
    int arr[10];

    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    int n = 10;
    int key = 1;

    for (int i = 0; i < 9; i++) {
        int result = Transposition(arr, n, key);
        if (result != -1) {
            cout << "Элемент найден на позиции " << result + 1 << endl;
        }
        else {
            cout << "Элемент не найден" << endl;
        }
    }
    return 0;
}