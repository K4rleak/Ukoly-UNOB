#ifndef SLOUP_HPP
#define SLOUP_HPP

#include <SFML/Graphics.hpp>
#include "iostream"
#include <cstdlib>
#include <ctime>  

class Sloup {
public:
    Sloup();
    sf::RectangleShape getSurface() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getFinal() const;

    void draw(sf::RenderWindow& window);
    void posun();

// private:
    sf::RectangleShape surface;
    sf::RectangleShape ctverecek;
    sf::Vector2f position;
    sf::Vector2f final;
//     // Declare member variables, such as game objects, resources, etc.
};

#endif // SLOUP_HPP
