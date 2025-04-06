#include <iostream>
#include <string>
using namespace std;

bool Input(int& a, int& b)
{
    system("chcp 1251");
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    if (a == 0 || b == 0)
    {
        return false;
    }

    return true;
}
int main()
{
    int a, b;
    if (Input(a, b) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    cout << "s = " << s << endl;
    return 0;
}