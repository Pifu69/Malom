#include "player.h"
#include "piece.h"

Player::Player(Colour colour) : /*Player_Name(name),*/Team_Color(colour), Num_Of_Pieces_On_Field(0){
    for (size_t i = 0; i < 9; i++){
        Player_Pieces[i] = Piece(Team_Color);
    }
}

/*Name Player::get_Name() const {
    return Player_Name;
}*/

int Player::get_num() const {
    return Num_Of_Pieces_On_Field;
}

std::array<Piece, 9> Player::get_pieces() const {
    return Player_Pieces;
}

size_t Player::search_selected_piece(const Position &position) const {
    for (size_t i = 0; i < 9; i++) {
        if (Player_Pieces[i].get_position() == position) return i;
    }
    throw "No Piece there";
}


