#include "shell.h"


Point* Shell::operator[](int point){
    if (point < 0) point = Num_Of_Points + point;
    return Shell_Points[point].get();
}