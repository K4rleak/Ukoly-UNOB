#ifndef MOST_HPP
#define MOST_HPP

#include <SFML/Graphics.hpp>

class Most {
public:
    Most(const sf::Vector2f& startPoint);
    void rize(sf::RenderWindow& window,bool* stav);
    void update(bool isRotating, bool increaseLength);
    void draw(sf::RenderWindow& window);
    void rotate(bool* rotate);
    void reset();
private:
    sf::RectangleShape most;
};

#endif // MOST_HPP