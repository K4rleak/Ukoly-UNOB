#include "Player.hpp"
//Constructor
Player::Player() {

    playerTexture.loadFromFile("Player.png");
    playerSprite.setTexture(playerTexture);
    sf::FloatRect bounds = playerSprite.getGlobalBounds();
    width = bounds.width;
    height=bounds.height;

}

//Draws the player on the screen
void Player::draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
}
//Makes the player run to the next pillar
void Player::beh(bool* stav,float posx,int presnost) {
    sf::Vector2f currentPosition = playerSprite.getPosition();
    currentPosition.x += 3;
    playerSprite.setPosition(currentPosition);
    if (presnost==1 || presnost==2){
        if (playerSprite.getPosition().x>=posx-width/2){
            currentPosition.x =posx-width/2;
            playerSprite.setPosition(currentPosition);
            *stav=false;
        }
    }
    else {
        if (playerSprite.getPosition().x>=posx-width/2){
            currentPosition.x =posx-width/2;
            playerSprite.setPosition(currentPosition);
            *stav=false;
        }
    }
}
//Moves the player to the left
void Player::posun() {
    sf::Vector2f currentPosition = playerSprite.getPosition();
    currentPosition.x -= 5;
    playerSprite.setPosition(currentPosition);
}

