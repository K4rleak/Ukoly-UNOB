#include "Sloup.hpp"

Sloup::Sloup() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int width = std::rand() % 41 + 50; 
    surface.setSize(sf::Vector2f(width, 150));
    ctverecek.setSize(sf::Vector2f(10,10));
    // Fill the surface with black color
    surface.setFillColor(sf::Color::Black);
    ctverecek.setFillColor(sf::Color::Red);


    // Draw a red square at the center of the surface
    // sf::RectangleShape fillRect(sf::Vector2f(10, 10));
    // fillRect.setFillColor(sf::Color::Red);
    // fillRect.setPosition(surface.getSize().x / 2 - 5, 0);
    // surface.draw(fillRect);

    // Set initial position off the right side of the screen
    position = sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height - surface.getSize().y);

    // Set final position off the left side of the screen
    final = sf::Vector2f(0, sf::VideoMode::getDesktopMode().height - surface.getSize().y);
}

void Sloup::draw(sf::RenderWindow& window){
    ctverecek.setPosition(surface.getPosition().x + surface.getSize().x/2 - 5, window.getSize().y - 150);
    window.draw(surface);
    window.draw(ctverecek);
    }

sf::RectangleShape Sloup::getSurface() const {
    return surface;
}

sf::Vector2f Sloup::getPosition() const {
    return position;
}

sf::Vector2f Sloup::getFinal() const {
    return final;
}

void Sloup::posun(){
    sf::Vector2f currentPosition = surface.getPosition();
    currentPosition.x -= 5;
    surface.setPosition(currentPosition);
    ctverecek.setPosition(position.x + surface.getSize().x/2 - 5, 390);
}

void Sloup::reset(sf::RenderWindow& window){
    sf::Vector2f currentPosition = surface.getPosition();
    currentPosition.x = window.getSize().x;
    surface.setPosition(currentPosition);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int width = std::rand() % 41 + 50; 
    surface.setSize(sf::Vector2f(width, 150));

    final.x=90 + std::rand() % 150 + 200;
}

void Sloup::prijezd(bool* stav){
    sf::Vector2f currentPosition = surface.getPosition();
    currentPosition.x -=5;
    surface.setPosition(currentPosition);
    if (currentPosition.x<=final.x){
        currentPosition.x=final.x;
        surface.setPosition(currentPosition);
        *stav=false;
    }
}