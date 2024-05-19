#include "Piano.h"

Piano::Piano() {
    std::vector<std::pair<char, std::string>> keyData = {
        {'A', "sounds/C.wav"},
        {'S', "sounds/D.wav"},
        {'D', "sounds/E.wav"},
        {'F', "sounds/F.wav"},
        {'G', "sounds/G.wav"},
        {'H', "sounds/A.wav"},
        {'J', "sounds/B.wav"},
        {'K', "sounds/C_high.wav"}
    };

    float x = 50;
    for (const auto& data : keyData) {
        keys.emplace_back(data.first, data.second, sf::Vector2f(x, 100));
        x += 60;
    }
}

void Piano::draw(sf::RenderWindow& window) {
    for (auto& key : keys) {
        key.draw(window);
    }
}

void Piano::playKey(char key) {
    for (auto& pianoKey : keys) {
        if (pianoKey.getKey() == key) {
            pianoKey.playSound();
            pianoKey.highlight();
            break;
        }
    }
}

void Piano::highlightKey(char key) {
    for (auto& pianoKey : keys) {
        if (pianoKey.getKey() == key) {
            pianoKey.highlight();
            break;
        }
    }
}

void Piano::resetAllKeys() {
    for (auto& pianoKey : keys) {
        pianoKey.resetColor();
    }
}

void Piano::playMouseKey(const sf::Vector2i& mousePosition) {
    for (auto& pianoKey : keys) {
        if (pianoKey.isPressed(mousePosition)) {
            pianoKey.playSound();
            pianoKey.highlight();
            break;
        }
    }
}
