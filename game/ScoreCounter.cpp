#include "ScoreCounter.hpp"

ScoreCounter::ScoreCounter() : score(0) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(sf::Color::Red);
}
//Resets the score
void ScoreCounter::reset(){
    score=0;
}
//Adds 1 point to the score
void ScoreCounter::increaseScore() {
    score++;
}
//Returns the score
int ScoreCounter::getScore() const {
    return score;
}

void ScoreCounter::draw(sf::RenderWindow& window) {
    scoreText.setString(std::to_string(score));

    // Set position to render text in the middle at the top
    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setPosition(0,0);

    window.draw(scoreText);
}
