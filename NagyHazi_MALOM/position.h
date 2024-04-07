#ifndef NAGYHAZI_MALOM_POSITION_H
#define NAGYHAZI_MALOM_POSITION_H

class Position {
    int Position_Shell;
    int Position_Point;
public:
    Position(int shell = -1, int point = -1) : Position_Shell(shell), Position_Point(point) {}

    void set_position(int shell, int point);
    int get_shell() const;
    int get_point() const;

    Position& operator=(const Position&);
    bool operator==(const Position&);
};

#endif //NAGYHAZI_MALOM_POSITION_H
