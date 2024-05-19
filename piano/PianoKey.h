#ifndef PIANOKEY_H
#define PIANOKEY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class PianoKey {
public:
    PianoKey(char key, const std::string& soundFilePath, const sf::Vector2f& position);

    void playSound();
    void draw(sf::RenderWindow& window);
    void highlight();
    void resetColor();
    char getKey() const;
    bool isPressed(const sf::Vector2i& mousePosition) const;

private:
    char key;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    sf::RectangleShape shape;
    sf::Color originalColor;
    sf::Color highlightColor;
};

#endif
