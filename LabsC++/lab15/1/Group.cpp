#include "Group.h"
#include "Student.h"
#include <iostream>

using namespace std;

Group::Group(const std::string& groupName) : groupName(groupName) {}

std::string Group::getName() const {
    return groupName;
}

int Group::getSize() {
    return masSt.size();
}

void Group::addStudent(Student* newStudent) {
    masSt.push_back(newStudent);
    setMasSt.insert(newStudent);
}

void Group::delStudent(Student* oldStudent) {
    masSt.remove(oldStudent);
    setMasSt.erase(oldStudent);
}
void Group::GroupOut()
{
    iter = masSt.begin();
    while (iter != masSt.end())
        (*iter++)->display();
}

Student* Group::findStudent(string searchName, string searchLastName) {
    Student temp(searchName, searchLastName, 0);
    auto it = setMasSt.find(&temp);
    if (it != setMasSt.end()) {
        return *it;
    }
    throw std::runtime_error("Студент не найден.");
}

void Group::GroupSort() {
    for (auto it = setMasSt.begin(); it != setMasSt.end(); /* no-op */) {
        Student* student = *it;
        setMasSt.erase(it);
        masSt.push_front(student);
    }
    setMasSt.clear();
    for (auto& student : masSt) {
        setMasSt.insert(student);
    }
}
