#include "shell.h"

Shell::Shell(size_t index) : Num_Of_Points(8), Shell_Index(index) {
        for (size_t i = 0; i < Num_Of_Points; i+=2){
            Shell_Points[i] = new Corner_Point(Shell_Index, i);
            Shell_Points[i + 1] = new Edge_Point(Shell_Index, i + 1);
        }
}

const Point& Shell::operator[](int point) const {
    if (point < 0) point = Num_Of_Points + point;
    if (point > Num_Of_Points) point = point - Num_Of_Points;
    return *Shell_Points[point];
}

Point& Shell::operator[](int point){
    if (point < 0) point = Num_Of_Points + point;
    return *Shell_Points[point];
}