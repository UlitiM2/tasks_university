﻿#include <iostream>
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
    Distance d1 = InputDist();
    Distance d2 = { 1, 6.25 };
    Distance d3 = AddDist(d1, d2);

    d1.ShowDist();
    d2.ShowDist();
    d3.ShowDist();
}