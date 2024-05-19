#ifndef PIANO_H
#define PIANO_H

#include "PianoKey.h"
#include <vector>

class Piano {
public:
    Piano();
    void draw(sf::RenderWindow& window);
    void playKey(char key);
    void highlightKey(char key);
    void resetAllKeys();
    void playMouseKey(const sf::Vector2i& mousePosition);

private:
    std::vector<PianoKey> keys;
};

#endif
