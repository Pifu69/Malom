#include "player.h"
#include "piece.h"

Player::Player(Name name) : Player_Name(name), Num_Of_Pieces_On_Field(0){
    for (size_t i = 0; i < 9; i++){
        Player_Pieces[i] = Piece();
    }
}

Name Player::get_Name() const {
    return Player_Name;
}

int Player::get_num() const {
    return Num_Of_Pieces_On_Field;
}

size_t Player::search_piece(const Position &position) const {
    for (size_t i = 0; i < 9; i++) {
        if (Player_Pieces[i].get_position() == position) return i;
    }
    throw "No Piece there";
}

