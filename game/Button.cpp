#include "Button.hpp"

Button::Button(float x, float y, std::string textureFile) {
    
    Texture.loadFromFile(textureFile);
    sprite.setTexture(Texture);
    // if (!texture.loadFromFile(textureFile)) {
    //     std::cerr << "Failed to load texture: " << textureFile << std::endl;
    // }

    // sprite.setTexture(texture);
    sprite.setPosition(x,y);

    sf::FloatRect bounds = sprite.getGlobalBounds();
    width = bounds.width;
    height=bounds.height;
}

bool Button::isMouseOver(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();

    return buttonBounds.contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
