#include <iostream>
#include <string>

using namespace std;

struct Distance
{
    int feet;
    double inches;

    void ShowDist()
    {
        cout << feet << "\'-" << inches << "\"\n";
    }

};


Distance AddDist(const Distance& d1, const Distance& d2) {
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;
    if (d.inches >= 12.0)
    {
        d.inches -= 12.0;
        d.feet++;
    }
    return d;
}

Distance InputDist() {
    Distance d;
    cout << "\nВВедите число футов: ";
    cin >> d.feet;
    cout << "Введите число дюймов: ";
    cin >> d.inches;
    return d;
}


int main() {
    system("chcp 1251");
    int n;
    cout << "Введите размер массива расстояний ";
    cin >> n;

    Distance* masDist = new Distance[n];

    for (int i = 0; i < n; i++) {
        masDist[i] = InputDist();
    }

    Distance sum = { 0, 0.0 };

    for (int i = 0; i < n; i++) {
        masDist[i].ShowDist();
        sum = AddDist(sum, masDist[i]);
    }

    sum.ShowDist();

    delete[] masDist;
}
