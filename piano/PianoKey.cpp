#include "PianoKey.h"
#include <iostream>

PianoKey::PianoKey(char key, const std::string& soundFilePath, const sf::Vector2f& position)
    : key(key), originalColor(sf::Color::White), highlightColor(sf::Color::Yellow)
{
    if (!soundBuffer.loadFromFile(soundFilePath)) {
        std::cerr << "Error loading sound file: " << soundFilePath << std::endl;
    }
    sound.setBuffer(soundBuffer);

    shape.setSize(sf::Vector2f(50, 200));
    shape.setPosition(position);
    shape.setFillColor(originalColor);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2);
}

void PianoKey::playSound() {
    sound.play();
}

void PianoKey::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void PianoKey::highlight() {
    shape.setFillColor(highlightColor);
}

void PianoKey::resetColor() {
    shape.setFillColor(originalColor);
}

char PianoKey::getKey() const {
    return key;
}

bool PianoKey::isPressed(const sf::Vector2i& mousePosition) const {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
