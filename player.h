#ifndef NAGYHAZI_MALOM_PLAYER_H
#define NAGYHAZI_MALOM_PLAYER_H
#include <iostream>
#include "piece.h"
#include "colour.h"
#include <array>
#include "position.h"
#include "map.h"

class Player{
    bool Trap;
    Colour Team_Color;
    int Num_Of_Pieces_On_Field;
    std::array<Piece, 9> Player_Pieces;
public:
    Player(Colour colour);

    int get_num() const;
    std::array<Piece, 9>& get_pieces();
    bool has_trap() const;
    bool is_there_selected() const;
    bool is_all_in_trap(const Map&) const;

    std::optional<size_t> search_piece(const Position &position);
    std::optional<size_t> search_selected() const;

    void set_all_piece_unselected();
    void set_piece_selected(size_t);
    void set_trap_true();
    void set_trap_false();
    void increase_num();
    void decrease_num();
    void set_piece_on_field(const Position&);
    void set_piece_off_field(size_t);

};
#endif //NAGYHAZI_MALOM_PLAYER_H

