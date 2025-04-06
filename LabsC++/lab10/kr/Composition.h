#pragma once
#include "../1/kr.h"

class TriangleComposition {
private:
    Dot a, b, c;

public:
    TriangleComposition(Dot a, Dot b, Dot c);
    void printSides();
    double perimeter();
    double area();
};
