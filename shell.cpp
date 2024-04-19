#include "shell.h"

Shell::Shell(size_t index) : Num_Of_Points(8), Shell_Index(index), Shell_Points({Point(index, 0),
                                                                                 Point(index, 1),
                                                                                 Point(index, 2),
                                                                                 Point(index, 3),
                                                                                 Point(index, 4),
                                                                                 Point(index, 5),
                                                                                 Point(index, 6),
                                                                                 Point(index, 7)}) {}

const Point& Shell::operator[](int point) const {
    if (point < 0) point = Num_Of_Points + point;
    if (point >= Num_Of_Points) point = point - Num_Of_Points;
    return Shell_Points[point];
}

Point& Shell::operator[](int point){
    if (point < 0) point = Num_Of_Points + point;
    if (point >= Num_Of_Points) point = point - Num_Of_Points;
    return Shell_Points[point];
}
