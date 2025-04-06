#include <iostream>
#include "../1/kr.h"
#include "Composition.h"
#include "aggregation.h"
using namespace std;
int main() {
    system("chcp 1251");
    // ����������
    Dot a1(0, 0);
    Dot b1(4, 0);
    Dot c1(0, 3);
    TriangleComposition triangleComp(a1, b1, c1);
    cout << "����������:" << endl;
    triangleComp.printSides();
    cout << "��������: " << triangleComp.perimeter() << endl;
    cout << "�������: " << triangleComp.area() << endl;

    // ���������
    Dot a2(1, 1);
    Dot b2(5, 1);
    Dot c2(1, 4);
    Aggregation triangleAgre(a2, b2, c2);
    cout << "���������:" << endl;
    triangleAgre.printSides();
    cout << "��������: " << triangleAgre.perimeter() << endl;
    cout << "�������: " << triangleAgre.area() << endl;
}