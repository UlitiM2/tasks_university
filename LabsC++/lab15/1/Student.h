#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
class compareStudent
{
public:
    bool operator() (const Student* ptrSt1, const Student*
        ptrSt2) const
    {
        return *ptrSt1 < *ptrSt2;
    }
};

class Student {
public:
    Student(std::string name, std::string lastName, int id);
    void display() const;

    friend bool operator<(const Student& lhs, const Student& rhs);
    friend bool operator==(const Student& lhs, const Student& rhs);
    friend bool operator!=(const Student& lhs, const Student& rhs);
    friend bool operator>(const Student& lhs, const Student& rhs);

private:
    std::string name;
    std::string lastName;
    int id;
};

#endif // STUDENT_H