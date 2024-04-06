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
player.draw(window);
sloup1.draw(window);
sloup2.draw(window);
most.draw(window);

}

void Game::kresleni(sf::RenderWindow& window,bool* stav){
    most.rize(window,stav);
}

void Game::beh(bool* stav){
    most.mereni(sloup1.surface.getSize().x,sloup2.surface.getPosition().x);
    float posx=sloup2.surface.getPosition().x+sloup2.surface.getSize().x/2;
    player.beh(stav,posx);
}

void Game::rotate(bool* rotate){
    most.rotate(rotate);
}

void Game::posun(bool* move,sf::RenderWindow& window){
    sloup1.posun();
    sloup2.posun();
    player.posun();
    most.reset();
    if (sloup2.surface.getPosition().x<=0){
        *move=false;
        sloup2.surface.setPosition(0,window.getSize().y - 150);
        
    }
}

void Game::spawn(sf::RenderWindow& window){
    sloup1=sloup2;
    sloup2.reset(window);
    sf::Vector2f startPoint(sloup1.surface.getSize().x, window.getSize().y - 149);
    most.setpos(startPoint);

}

void Game::prijezd(bool* stav){
    sloup2.prijezd(stav);
}