#include <iostream>
#include <fstream>
using namespace std;


int main() {
    string line;
    ofstream file("massiv.txt");

    if (!file) {
        cerr << "Ошибка\n";
        return 1;
    }
    file << "Исходный массив\n";
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    for (int i = 0; i < N; i++) {
        file << a[i] << "\t";
    }
    file << "\n";

    int min = 0;// для записи минимального значения
    int buf = 0;// для обмена значениями
    for (int i = 0; i < N; i++) {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++) {
            min = (a[j] < a[min]) ? j : min;
        }
        // перестановка этого элемента, поменяв его местами с текущи
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    file << "Отсортированный массив:\n";
    for (int i = 0; i < N; i++){
        file << a[i] << "\t";
    }
    file.close();
    return 0;
}