#ifndef NAGYHAZI_MALOM_GAME_H
#define NAGYHAZI_MALOM_GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"

class Game {
    sf::RenderWindow Window;
    int Game_Round;
    Player White_Player;
    Player Black_Player;
public:
    Game();

    sf::RenderWindow& get_window();
    int get_game_round() const;
    Player get_white_player() const;
    Player get_black_player() const;

    void show();


};

#endif //NAGYHAZI_MALOM_GAME_H
