#pragma once
#include "../1/kr.h"

class Aggregation {
private:
    Dot& a;
    Dot& b;
    Dot& c;

public:
    Aggregation(Dot& a, Dot& b, Dot& c);
    void printSides();
    double perimeter();
    double area();
};
