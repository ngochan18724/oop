#ifndef VIRTUALPIANOAPP_H
#define VIRTUALPIANOAPP_H

#include "Piano.h"
#include <SFML/Graphics.hpp>

class VirtualPianoApp {
public:
    VirtualPianoApp();
    void run();

private:
    sf::RenderWindow window;
    Piano piano;

    void processEvents();
    void render();
    void handleKeyPress(sf::Keyboard::Key key);
};

#endif
