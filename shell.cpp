#include "shell.h"

Shell::Shell(size_t index) : Num_Of_Points(8), Shell_Points({Point(index, 0),
                                                                                 Point(index, 1),
                                                                                 Point(index, 2),
                                                                                 Point(index, 3),
                                                                                 Point(index, 4),
                                                                                 Point(index, 5),
                                                                                 Point(index, 6),
                                                                                 Point(index, 7)}) {}

const Point& Shell::operator[](size_t point) const {
    return Shell_Points[point];
}

Point& Shell::operator[](size_t point){
    return Shell_Points[point];
}
