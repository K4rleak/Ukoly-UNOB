#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "iostream"

class Player {
public:
Player();
void draw(sf::RenderWindow& window);
void beh(bool* stav,float posx);
void posun();

    
sf::Texture playerTexture;
sf::Sprite playerSprite;
float width;
float height;
//     // Declare member variables, such as game objects, resources, etc.
};

#endif // PLAYER_HPP
