#include "Button.hpp"

//Constructor of button(loads texture)
Button::Button(float x, float y, std::string textureFile) {
    
    Texture.loadFromFile(textureFile);
    sprite.setTexture(Texture);
    sprite.setPosition(x,y);

    sf::FloatRect bounds = sprite.getGlobalBounds();
    width = bounds.width;
    height=bounds.height;
}
// Function definition to check if the mouse is over the button
bool Button::isMouseOver(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();

    return buttonBounds.contains(static_cast<sf::Vector2f>(mousePos));
}
// Function definition to draw the button on the window
void Button::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
