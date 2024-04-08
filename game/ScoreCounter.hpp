#ifndef SCORECOUNTER_HPP
#define SCORECOUNTER_HPP

#include <SFML/Graphics.hpp>

class ScoreCounter {
public:
    ScoreCounter();

    void increaseScore();
    int getScore() const;
    void draw(sf::RenderWindow& window);
    void reset();

private:
    int score;
    sf::Font font;
    sf::Text scoreText;
};

#endif // SCORECOUNTER_HPP
