#ifndef MOST_HPP
#define MOST_HPP

#include <SFML/Graphics.hpp>

class Most {
public:
    Most(const sf::Vector2f& startPoint);
    void rize();
    void update(bool isRotating, bool increaseLength);
    void draw(sf::RenderWindow& window);
    void rotate(bool* rotate);
private:
    sf::RectangleShape most;
};

#endif // MOST_HPP