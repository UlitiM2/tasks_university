#include <iostream>
#include <string>
using namespace std;

void swap(int*, int*);
void swap(int&, int&);

int main()
{
    int x = 10, y = 20;
    cout << "x = " << x << "; y = " << y << endl;
    swap(&x, &y);
    cout << "x = " << x << "; y = " << y << endl;
    swap(x, y);
    cout << "x = " << x << "; y = " << y << endl;
    return 0;
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}