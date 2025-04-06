#include <iostream>
#include <string>
using namespace std;

int main() {
    const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        s += mas[i];
    }

    cout << "s = " << s << endl;

    double average;

    average = s / n;
    cout << "average = " << average << endl;


    int sum1 = 0;
    int sum2 = 0;
    int sumChet = 0;
    int sumNechet = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sumChet += mas[i];
        }
        else {
            sumNechet += mas[i];
        }

        if (mas[i] >= 0) {
            sum1 += mas[i];
        }
        else {
            sum2 += mas[i];
        }
    }


    cout << "sum1 = " << sum1 << endl;
    cout << "sum2 = " << sum2 << endl;
    cout << "sumChet = " << sumChet << endl;
    cout << "sumNechet = " << sumNechet << endl;


    int indexMax = 0;
    int indexMin = 0;
    int maxNum = mas[0];
    int minNum = mas[0];

    for (int i = 0; i < n; i++) {
        if (mas[i] > maxNum) {
            maxNum = mas[i];
            indexMax = i;
        }
        if (mas[i] < minNum) {
            minNum = mas[i];
            indexMin = i;
        }
    }


    cout << "indexMax = " << indexMax << endl;
    cout << "indexMin = " << indexMin << endl;


    int mul = 1;
    if (indexMin > indexMax)
    {
        for (int i = indexMax; i < indexMin; i++) {
            mul *= mas[i];
        }
    }

    if (indexMin < indexMax)
    {
        for (int i = indexMin; i < indexMax; i++) {
            mul *= mas[i];
        }
    }

    cout << "mul = " << mul << endl;

    return 0;
}