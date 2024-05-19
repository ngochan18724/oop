#include "VirtualPianoApp.h"

VirtualPianoApp::VirtualPianoApp()
    : window(sf::VideoMode(800, 600), "Virtual Piano") {
}

void VirtualPianoApp::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

void VirtualPianoApp::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            handleKeyPress(event.key.code);
        } else if (event.type == sf::Event::KeyReleased) {
            piano.resetAllKeys();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            piano.playMouseKey(sf::Mouse::getPosition(window));
        } else if (event.type == sf::Event::MouseButtonReleased) {
            piano.resetAllKeys();
        }
    }
}

void VirtualPianoApp::render() {
    window.clear();
    piano.draw(window);
    window.display();
}

void VirtualPianoApp::handleKeyPress(sf::Keyboard::Key key) {
    char pianoKey = static_cast<char>(key);
    piano.playKey(pianoKey);
}
