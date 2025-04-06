#include <iostream>
#include <string>
using namespace std;

string privet(string);

int main()
{
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    string nameOut = privet(name);
    cout << nameOut;
    return 0;
}


string privet(string name)
{
    string str = name + ", " + "hello!\n";
    return str;
}