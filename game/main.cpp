#include <SFML/Graphics.hpp>
#include "Game.hpp"

bool kresleni = false;
bool rotate=false;
bool move=false;

sf::Vector2f size;


int main() {
    sf::RenderWindow window(sf::VideoMode(800,540), "Ninja runer");
    Game game(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
                kresleni = true;
            }
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
                kresleni = false; 
                rotate =true;
            }
        }


    if (kresleni)
        game.kresleni();
    
    if (rotate){
        game.rotate(&rotate);
        if (!rotate)
        move=true;
    }

    if (move){
        game.posun();
    }

    //     // Update the game state
    //     game.update(window);

    game.draw(window);

    //     // Display the window
    window.display();
    }

    return 0;
}
