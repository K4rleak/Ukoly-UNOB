#include "Most.hpp"
// Constructor - sets the default values
Most::Most(const sf::Vector2f& startPoint) {
    most.setSize(sf::Vector2f(0, 2));
    most.setFillColor(sf::Color::Black);
    //most.setOrigin(2 / 2, 0);
    most.setPosition(startPoint);
    most.setRotation(90);
}

//Makes the bridge rise up(desreases the Y)
void Most::rize(sf::RenderWindow& window,bool* stav){
    sf::Vector2f size = most.getSize();
    most.setSize(sf::Vector2f(size.x - 2.0f, size.y));
    //here
}
//Rotates the bridge
void Most::rotate(bool* rotate){
    most.rotate(2.0f);
    if (most.getRotation() == 0.0f || most.getRotation() == 180.0f) {
            *rotate = false; 
        }
}

//Draws the bridge
void Most::draw(sf::RenderWindow& window) {
    window.draw(most);
}
//Resets the size and makes the bridge vertical
void Most::reset(){
    most.setSize(sf::Vector2f(0, 2));
    most.setRotation(90);
}
//Sets the hel of the bridge to the edge of the pillar
void Most::setpos(sf::Vector2f startPoint){
    most.setPosition(startPoint);
}
//Returns the width
int Most::getwidth()
{return abs(most.getSize().x);}

//Measures if the bridge reaches the next pillar
void Most::mereni(float sirka,sf::RectangleShape s2surface,int* presnost){
    int delka = abs(most.getSize().x);
if (delka < s2surface.getPosition().x - sirka || delka > s2surface.getPosition().x + s2surface.getSize().x - sirka)
    *presnost=0;
else if (delka >= s2surface.getPosition().x + s2surface.getSize().x / 2 - 5 - sirka && delka <= s2surface.getPosition().x + s2surface.getSize().x / 2 + 5 - sirka)
{
    *presnost=2;
}
else
    *presnost=1;

}