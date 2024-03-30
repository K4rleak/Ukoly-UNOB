#include "Game.hpp"

Game::Game(sf::RenderWindow& window):
    most(sloup1.surface.getPosition() + sf::Vector2f(sloup1.surface.getSize().x, window.getSize().y - 149 ))
{
    window.setFramerateLimit(60);
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    kostka.setSize(sf::Vector2f(2,2));
    kostka.setFillColor(sf::Color::White);
    window.draw(backgroundSprite);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sloup1.position=sf::Vector2f(0,window.getSize().y - 150);
    sloup2.position=sf::Vector2f(250,window.getSize().y - 150);
    sloup1.surface.setPosition(sloup1.position);
    sloup2.surface.setPosition(sloup2.position);
    kostka.setPosition(sloup1.surface.getSize().x-2,window.getSize().y - 150-2);
    sloup1.draw(window);
    sloup2.draw(window);
    player.playerSprite.setPosition(sloup1.surface.getSize().x / 2 - player.width/2,window.getSize().y - 150-player.height);
    window.draw(player.playerSprite);
    window.display();
}

// void Game::update(sf::RenderWindow& window) {
//     // Update game logic, handle input, etc.
// }

void Game::draw(sf::RenderWindow& window) {

window.draw(backgroundSprite);
sloup1.draw(window);
sloup2.draw(window);
most.draw(window);

}

void Game::kresleni(){
    most.rize();
}


void Game::rotate(bool* rotate){
    most.rotate(rotate);
    
}

void Game::posun(){
    sloup1.posun();
    sloup2.posun();
    most.most.setSize(sf::Vector2f(0, 2));
}