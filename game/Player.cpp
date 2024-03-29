#include "Player.hpp"

Player::Player() {

    playerTexture.loadFromFile("Player.png");
    playerSprite.setTexture(playerTexture);
    sf::FloatRect bounds = playerSprite.getGlobalBounds();
    width = bounds.width;
    height=bounds.height;

    // backgroundTexture.loadFromFile("background.jpg");
    // backgroundSprite.setTexture(backgroundTexture);
    // // sf::Sprite backgroundSprite(backgroundTexture);
    // window.draw(backgroundSprite);
    // window.display();
    // sf::Vector2u textureSize = backgroundTexture.getSize();
    // std::cout << "Background Height: " << textureSize.y << std::endl;
    //backgroundSprite.setTexture(backgroundTexture);

    // Initialize member variables, load resources, etc.
}

// void Enemy::update(sf::RenderWindow& window) {
//     // Update Enemy logic, handle input, etc.
// }

void Player::draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
//     // Clear the window

//     window.clear(sf::Color::Black);

//     // Draw Enemy objects, UI, etc.
//     // Example:
//     // window.draw(player);
//     // window.draw(enemy);

//     // End drawing
//     window.display();
}
