#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hpp"
#include "Sloup.hpp"
#include "iostream"
#include "Most.hpp"
#include "ScoreCounter.hpp"
#include "Button.hpp"

class Game {
public:
int presnost;
Game(sf::RenderWindow& window);
void draw(sf::RenderWindow& window);
void kresleni(sf::RenderWindow& window,bool* stav);
void rotate(bool* rotate);
void posun(bool* move,sf::RenderWindow& window);
void beh(bool* stav);
void prijezd(bool* stav);
void spawn(sf::RenderWindow& window);
void mereni(bool* stav);
void smrt(sf::RenderWindow& window);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Player player;
    Sloup sloup1;
    Sloup sloup2;
    unsigned int pata;
    sf::RectangleShape kostka;
    //sf::Vector2f startPoint{200.f, 200.f};
    Most most;
    ScoreCounter counter;
    sf::Music music;
    

};

#endif // GAME_HPP
