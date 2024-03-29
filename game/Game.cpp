#include "Game.hpp"

Game::Game(sf::RenderWindow& window) {
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
    //backgroundSprite.setTexture(backgroundTexture);

    // Initialize member variables, load resources, etc.
}

// void Game::update(sf::RenderWindow& window) {
//     // Update game logic, handle input, etc.
// }

void Game::draw(sf::RenderWindow& window) {
//     // Clear the window
window.draw(backgroundSprite);

//     window.clear(sf::Color::Black);

//     // Draw game objects, UI, etc.
sloup1.draw(window);
sloup2.draw(window);
window.draw(kostka);
// window.display();

//     // Example:
//     // window.draw(player);
//     // window.draw(enemy);

//     // End drawing
//     window.display();
}

void Game::kresleni(sf::RenderWindow& window){
    window.draw(kostka);
    kostka.move(0,-2);
    // window.display();
}
