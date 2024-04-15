#include <iostream>
#include "game.h"

int main(void){
    Game game;
    game.get_white_player().get_pieces()[0].set_position(Position(2,3));
    game.get_white_player().get_pieces()[4].set_position(Position(0, 7));
    game.get_black_player().get_pieces()[3].set_position(Position(1, 0));
    while(game.get_window().isOpen()) {
        sf::Event Event;
        while (game.get_window().pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                game.get_window().close();
        }
    game.show();
    }
    return 0;
}