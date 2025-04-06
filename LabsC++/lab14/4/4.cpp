#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

template<class T, class T1>
class Array {
public:
    // Конструктор
    Array(int size) {
        data = new T[size];
        if (data == nullptr) {
            cerr << "Ошибка выделения памяти!" << endl;
            exit(EXIT_FAILURE);
        }
        this->size = size;
        index = 0;
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Метод для добавления элемента в массив
    int addValue(const T& value) {
        if (index == size) {
            return -1;   // Массив заполнен
        }
        data[index++] = value;
        return 0;
    }

    // Метод для вычисления суммы элементов массива
    T1 sum() const {
        T1 total = 0;
        for (int i = 0; i < index; ++i) {
            total += data[i];
        }
        return total;
    }

    // Метод для вычисления среднего значения элементов массива
    double averageValue() const {
        if (index == 0) {
            return 0.0;  // Если массив пуст, возвращаем 0
        }
        return static_cast<double>(sum()) / index;
    }

    // Метод для вывода содержимого массива
    void showArray() const {
        for (int i = 0; i < index; ++i) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }

private:
    T* data;       // Указатель на данные
    int size;      // Размер массива
    int index;     // Индекс текущего элемента
};

int main() {
    system("chcp 1251");
    Array<int, long> numbers(100);
    Array<float, float> values(200);

    for (int i = 0; i < 50; ++i) {
        numbers.addValue(i);
    }
    numbers.showArray();
    cout << "Сумма: " << numbers.sum() << endl;
    cout << "Среднее значение: " << numbers.averageValue() << endl;

    for (int i = 0; i < 100; ++i) {
        values.addValue(i * 100.0f);
    }
    values.showArray();
    cout << "Сумма: " << values.sum() << endl;
    cout << "Среднее значение: " << values.averageValue() << endl;

    return 0;
}
