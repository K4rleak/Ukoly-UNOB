#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Sloup.hpp"
#include "iostream"

class Game {
public:
Game(sf::RenderWindow& window);
// void update(sf::RenderWindow& window);
void draw(sf::RenderWindow& window);
void kresleni(sf::RenderWindow& window);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Player player;
    Sloup sloup1;
    Sloup sloup2;
    unsigned int pata;
    sf::RectangleShape kostka;
//     // Declare member variables, such as game objects, resources, etc.
};

#endif // GAME_HPP
