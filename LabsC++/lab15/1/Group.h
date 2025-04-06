#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <algorithm>
#include <string>
#include <functional>

class Student;

struct CompareStudents {
    bool operator()(const Student* a, const Student* b) const {
        return (*a) < (*b);
    }
};

class Group {
public:
    Group(const std::string& groupName);
    std::string getName() const;
    int getSize();
    void addStudent(Student* newStudent);
    void delStudent(Student* oldStudent);
    Student* findStudent(const std::string& searchName, const std::string& searchLastName);
    void GroupSort();
    void GroupOut();

private:
    list<Student*> masSt;
    list<Student*>::iterator iter;
    string groupName;
    multiset<Student*, CompareStudents> setMasSt;
};

#endif // GROUP_H