#include "Group.h"
#include "Student.h"
#include <iostream>

int main() {
    system("chcp 1251");
    Student* student03 = new Student("Петр", "Петров", idc2);
    Student* student04 = new Student("Семен", "Смирнов", idc);
    Student* student05 = new Student("Саша", "Коен", idc2);
    Student* student06 = new Student("Дмитрий", "Ионов", idc);

    Group gr1957("K3355");

    gr1957.addStudent(student03);
    gr1957.addStudent(student04);
    gr1957.addStudent(student05);
    gr1957.addStudent(student06);
    //gr1957.delStudent(gr1957.findStudent("Семен", "Смирнов"));

    int k = gr1957.getSize();
    //gr1957.GroupSort();
    cout << "В группе " << gr1957.getName() << " " << k << " ст." << endl;
    gr1957.GroupOut();
}