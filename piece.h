#ifndef NAGYHAZI_MALOM_PIECE_H
#define NAGYHAZI_MALOM_PIECE_H
#include <iostream>
#include <string>
#include "position.h"
#include "colour.h"
#include <SFML/Graphics.hpp>
#include <optional>

class Piece{
    Colour Team_Colour;
    std::optional<Position> Piece_Position;
    bool Is_Selected;
public:
    ///@brief Piece osztály konstruktora
    ///@param colour A bábú színe, hogy melyik játékoshoz tartozik
    Piece(Colour = None);

    ///@brief megmondja, hogy a bábú fent van-e a táblán
    ///@return TRUE, ha a Piece_Position-nek van értéke, FALSE, ha nincs
    bool is_on_field() const;

    ///@brief megmondja, hogy a bábú ki van-e választva
    ///@return TRUE, ha az Is_Selected tagváltozó is az, FALSE ellenkezőleg
    bool is_selected() const;

    Colour get_colour() const;
    Position get_position() const;

    ///@brief Az optional Piece_Position-nek állít be egy értéket
    ///@param position ezt az értéket állítjuk be a bábú pozíciójának
    void set_position(const Position&);

    ///@brief Levesszük a bábút a pályáról, vagyis töröljük, az optional változó értéket
    void set_off_field();

    ///@brief a bábút kiválasztottnak minősítjük
    void set_selection_true();
    ///@brief a bábút nem kiválasztottnak minősítjük
    void set_selection_false();

    ///@brief A bábú pozíciója alapján megmondja, hogy hová kell rajzolni az ablakban a bábút ábrázoló kört
    ///@param r A bábú rajzának sugara
    ///@return A bábú körének "bal felső" sarka, ahová a kör pozícióját kell állítani
    sf::Vector2f where_to_draw(float) const;

};
#endif //NAGYHAZI_MALOM_PIECE_H

