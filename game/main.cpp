#include <SFML/Graphics.hpp>
#include "Game.hpp"

// Flags for various game states
bool kresleni = false; // Flag for drawing
bool rotate = false; // Flag for rotation
bool move = false; // Flag for movement
bool beh = false; // Flag for movement of the player
bool iscoming = false; // Flag for movement of the pillars
bool isdone = true; // Flag for completion
bool ismeasuring = false; // Flag for measuring

sf::Vector2f size; // Vector for size

int main() {
    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(800, 540), "Ninja runner");
    // Create Game instance
    Game game(window);

    // Main game loop
    while (window.isOpen()) {
        sf::Event event; // SFML event object
        // Event loop
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close window on close event
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
                if(isdone==true){
                    kresleni = true; // Start drawing when Up key is pressed
                }   
            }
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
                kresleni = false; // Stop drawing when Up key is released
                if(isdone==true){
                    rotate = true; // Start rotation when Up key is released
                    isdone=false; // Reset flag to indicate rotation started
                }
            }
        }

        // Drawing phase
        if (kresleni)
            game.kresleni(window,&kresleni); // Draw

        // Rotation phase
        if (rotate){
            game.rotate(&rotate); // Rotate
            if (!rotate)
                ismeasuring=true; // Start measuring when rotation is done
        }

        // Measuring phase
        if (ismeasuring){
            game.mereni(&ismeasuring); // Measure
            if(!ismeasuring)
                beh=true; // Start behavior when measuring is done
        }

        // Behavior phase
        if (beh){
            game.beh(&beh); // Perform behavior
            if (!beh)
                move=true; // Start movement when behavior is done
        }

        // Movement phase
        if (move){
            if(game.presnost ==0){
                move=false;
                game.smrt(window); // Handle death
                isdone=true; // Reset flag to indicate movement is done
            }
            else{
                game.posun(&move,window); // Move
                if (!move){
                    iscoming=true; // Start incoming when movement is done
                    game.spawn(window); // Spawn obstacles
                }
            }
        }

        // Incoming phase
        if (iscoming){
            game.prijezd(&iscoming); // Handle arrival
            if(!iscoming){
                isdone=true; // Reset flag to indicate the loop is done
            }
        }

        // Draw the game
        game.draw(window);
        // Display the window
        window.display();
    }

    return 0; // Return success
}
