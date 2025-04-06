#include <iostream>
#include <string>
using namespace std;

void privet(string);

void privet(string, int);

int main()
{
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    int k;
    cout << "Input number" << endl;
    cin >> k;
    privet(name);
    privet(name, k);
    return 0;
}


void privet(string name)
{
    cout << name << ", " << "hello!" << endl;
}


void privet(string name, int k)
{
    cout << name << ", " << "hello! " << "you input " << k << endl;
}