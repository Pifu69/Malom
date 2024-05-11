#ifndef NAGYHAZI_MALOM_POSITION_H
#define NAGYHAZI_MALOM_POSITION_H

#include <SFML/Graphics.hpp>

class Position {
    size_t Position_Shell;
    size_t Position_Point;
public:
    ///@brief Position osztály konstruktora
    ///@param shell az adott pont első koordinátája, hogy hányadik héjon van
    ///@param point az adott pont második koordinátája, a héjon belül hányadik pont
    Position(size_t shell, size_t point);

    size_t get_shell() const;
    size_t get_point() const;

    ///@brief Egy két koordinátából álló Position objektumot átalakít Vector2f típusú koordinátává a pálya méretei alapján
    ///@return Az objektum által mutatott mező helye az ablakban Vector2f formában
    sf::Vector2f position_to_vector() const;

    ///@brief Position osztály értékadó operátora
    Position& operator=(const Position&);

    ///@brief Position osztály egyenlőség operátora
    ///@return TRUE, ha mindkét koordináta megegyezik
    bool operator==(const Position&) const;

    ///@brief Ellenőrzi, hogy az adott pozícióból léphetünk-e szabályosan a paraméterként kapott pozícióba
    ///@param position Az a pozíció, aahová lépni szeretnénk
    ///@return TRUE, ha a lépés szabályos, FALSE, ellenkezőleg
    bool is_move_valid(const Position&) const; //pos

};

///@brief Egy indexként használandó számot alakít úgy, hogy a megfelelő intervallumba essen
///@param idx használandó koordináta
///@param max az indexelendő intervallum hossza
///@return a megfelelő intervallumba eső, már megfelelően használható index
/// Például idx = 6 s max = 4 esetén a visszatérési érték 2
size_t make_index_valid(int, int);
#endif //NAGYHAZI_MALOM_POSITION_H
