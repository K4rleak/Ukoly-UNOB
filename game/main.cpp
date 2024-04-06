#include <SFML/Graphics.hpp>
#include "Game.hpp"

bool kresleni = false;
bool rotate=false;
bool move=false;
bool beh=false;
bool iscoming=false;
bool isdone=true;

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
                if(isdone==true){
                kresleni = true;
                }
                
            }
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
                
                kresleni = false;
                if(isdone==true){
                    rotate =true;
                    isdone=false;
                    }
            }
        }


    if (kresleni)
        game.kresleni(window,&kresleni);
    
    if (rotate){
        game.rotate(&rotate);
        if (!rotate)
        beh=true;
    }
    if (beh){
        game.beh(&beh);
        if (!beh)
        move=true;
    }

    if (move){
        game.posun(&move,window);
        if (!move){
        iscoming=true;
        game.spawn(window);
        }
    }

    if (iscoming){
        game.prijezd(&iscoming);
        if(!iscoming){
            isdone=true;
        }
    }

    //     // Update the game state
    //     game.update(window);

    game.draw(window);

    //     // Display the window
    window.display();
    }

    return 0;
}
