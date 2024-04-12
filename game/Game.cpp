#include "Game.hpp"

//Constructor and initialization of the game(sets the default values and positions)
Game::Game(sf::RenderWindow& window):
    most(sloup1.surface.getPosition() + sf::Vector2f(sloup1.surface.getSize().x, window.getSize().y - 149 ))
{
    music.openFromFile("music.mp3");
    music.play();
    music.setLoop(true);

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

 // Draw background and game elements
void Game::draw(sf::RenderWindow& window) {
window.draw(backgroundSprite);
player.draw(window);
sloup1.draw(window);
sloup2.draw(window);
most.draw(window);
counter.draw(window);
}
//Makes the bridge rize
void Game::kresleni(sf::RenderWindow& window,bool* stav){
    most.rize(window,stav);
}
//Makes the player run to the next pillar
void Game::beh(bool* stav){
    float posx=1;
    if(presnost==1 || presnost==2)
    posx=sloup2.surface.getPosition().x+sloup2.surface.getSize().x/2;
    else
    posx=sloup1.surface.getSize().x+most.getwidth();
    player.beh(stav,posx,presnost);
}
//measures if the bridge reaches the next pillar
void Game::mereni(bool* stav){
    most.mereni(sloup1.surface.getSize().x,sloup2.surface,&presnost);
    *stav=false;
    switch(presnost)
    {
        case 1:
            counter.increaseScore();
            break;
        case 2:
        counter.increaseScore();
        counter.increaseScore();
        break;

    }
}
//Rotates the bridge
void Game::rotate(bool* rotate){
    most.rotate(rotate);
}
//Moves the whole screen to left(except the background)
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
//Creates new pillar
void Game::spawn(sf::RenderWindow& window){
    sloup1=sloup2;
    sloup2.reset(window);
    sf::Vector2f startPoint(sloup1.surface.getSize().x, window.getSize().y - 149);
    most.setpos(startPoint);

}
//Makes the new pillar come
void Game::prijezd(bool* stav){
    sloup2.prijezd(stav);
}

//Handles the death and restarting of the game
void Game::smrt(sf::RenderWindow& window){
    Button restart(200, 50, "Restart.png");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check if the mouse button is pressed
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the mouse is over the button
                    if (restart.isMouseOver(window)) {
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
                        most.reset();
                        sf::Vector2f startPoint(sloup1.surface.getSize().x, window.getSize().y - 149);
                        most.setpos(startPoint);
                        counter.reset();
                        return;
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        restart.draw(window);
        window.display();
    }
}
