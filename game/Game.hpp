#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Sloup.hpp"
#include "iostream"
#include "Most.hpp"

class Game {
public:
Game(sf::RenderWindow& window);
// void update(sf::RenderWindow& window);
void draw(sf::RenderWindow& window);
void kresleni();
void rotate(bool* rotate);
void posun();

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Player player;
    Sloup sloup1;
    Sloup sloup2;
    unsigned int pata;
    sf::RectangleShape kostka;
    sf::Vector2f startPoint{200.f, 200.f};
    Most most;
    

};

#endif // GAME_HPP
