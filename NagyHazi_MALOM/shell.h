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
    std::array<Point*, 8> Shell_Points;
public:
    Shell(size_t index);
    const Point& operator[](int) const;
    Point& operator[](int);
};

#endif //NAGYHAZI_MALOM_SHELL_H
