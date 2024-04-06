#include "Most.hpp"

Most::Most(const sf::Vector2f& startPoint) {
    most.setSize(sf::Vector2f(0, 2));
    most.setFillColor(sf::Color::Black);
    //most.setOrigin(2 / 2, 0);
    most.setPosition(startPoint);
    most.setRotation(90);
}


void Most::rize(sf::RenderWindow& window,bool* stav){
    sf::Vector2f size = most.getSize();
    most.setSize(sf::Vector2f(size.x - 2.0f, size.y));
    //here
}

void Most::rotate(bool* rotate){
    most.rotate(2.0f);
    if (most.getRotation() == 0.0f || most.getRotation() == 180.0f) {
            *rotate = false; 
        }
}


void Most::draw(sf::RenderWindow& window) {
    window.draw(most);
}

void Most::reset(){
    most.setSize(sf::Vector2f(0, 2));
    most.setRotation(90);
}

void Most::setpos(sf::Vector2f startPoint){
    most.setPosition(startPoint);
}

void Most::mereni(float sirka,float vzdalenost){
    if (most.getSize().x)
}