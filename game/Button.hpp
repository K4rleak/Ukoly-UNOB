#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Button {
public:
    Button(float x, float y, std::string textureFile);

    bool isMouseOver(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    float width;
    float height;
    sf::Texture Texture;
    sf::Sprite sprite;
};

#endif // BUTTON_HPP
