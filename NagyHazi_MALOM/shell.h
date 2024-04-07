#ifndef NAGYHAZI_MALOM_SHELL_H
#define NAGYHAZI_MALOM_SHELL_H
#include <iostream>
#include "point.h"
#include "corner_point.h"
#include "edge_point.h"
#include <memory>
#include <array>


class Shell{
    int Num_Of_Points;
    size_t Shell_Index;
    std::array<std::unique_ptr<Point>, 8> Shell_Points;
public:
    Shell(size_t index) : Num_Of_Points(8), Shell_Index(index) {
        for (size_t i = 0; i < Num_Of_Points; i+=2){
            Shell_Points[i] = std::make_unique<Corner_Point>;
            Shell_Points[i + 1] = std::make_unique<Edge_Point>;
        }
    }
    Point* operator[](int);
};

#endif //NAGYHAZI_MALOM_SHELL_H
