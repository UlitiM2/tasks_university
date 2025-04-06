#include "Student.h"
#include <iostream>

Student::Student(std::string name, std::string lastName, int id)
    : name(name), lastName(lastName), id(id) {}

void Student::display() const {
    std::cout << name << " " << lastName << " " << id << std::endl;
}

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.lastName == rhs.lastName && lhs.name == rhs.name;
}

bool operator<(const Student& lhs, const Student& rhs) {
    if (lhs.lastName == rhs.lastName) {
        return lhs.name < rhs.name;
    }
    return lhs.lastName < rhs.lastName;
}

bool operator!=(const Student& lhs, const Student& rhs) {
    return !(lhs == rhs);
}

bool operator>(const Student& lhs, const Student& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}