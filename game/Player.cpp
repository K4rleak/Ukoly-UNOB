#include "Player.hpp"

Player::Player() {

    playerTexture.loadFromFile("Player.png");
    playerSprite.setTexture(playerTexture);
    sf::FloatRect bounds = playerSprite.getGlobalBounds();
    width = bounds.width;
    height=bounds.height;

}


void Player::draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
}

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
// void Player::smrt(){
//     for(int y=playerSprite.getPosition().y; y>-10;y--)
//     {
//         sf::Vector2f currentPosition = playerSprite.getPosition();
//         currentPosition.y = y;
//         playerSprite.setPosition(currentPosition);
//     }
// }
void Player::posun() {
    sf::Vector2f currentPosition = playerSprite.getPosition();
    currentPosition.x -= 5;
    playerSprite.setPosition(currentPosition);
}

