#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int a, b, c;
    int k = 0;

    const int n = 10;
    int mas[n];

    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0;i < n;i++)
    {
        // инициализация операндов случайными числами от 1 до 101
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;


        cout << a << " * " << b << " = ";
        cin >> c;
        mas[i] = c;
        if (a * b != c)
        {
            vec1.push_back(c);
            k++; // операция «инкремент», аналогично: k = k + 1
            cout << "Error! ";
            cout << a << " * " << b << " = " << a * b << endl;
        }
        else
        {
            vec2.push_back(c);
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;

    cout << "Good: ";
    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i] << " ";
    }
    cout << endl;
    cout << "Bad: ";
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
    cout << "Count error: " << k << endl;

}
