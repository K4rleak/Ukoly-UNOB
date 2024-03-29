#include <SFML/Graphics.hpp>
#include "Game.hpp"

bool isUpKeyPressed = false;


int main() {
    //Create a window
    sf::RenderWindow window(sf::VideoMode(800,540), "Ninja runer");

    // Create an instance of the Game class
    Game game(window);

    // Start the game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
                game.kresleni(window);
                isUpKeyPressed = true; // Set the flag to true when Up key is pressed
            }
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
                isUpKeyPressed = false; 
        }

    //     // Update the game state
    //     game.update(window);

    //     // Clear the window
    //     window.clear();

    //     // Draw the game objects
    game.draw(window);

    //     // Display the window
   window.display();
    }

    return 0;
}
