#include "Debug.h"

Debug::Debug() {
  if (!font_.loadFromFile("C:\\WINDOWS\\FONTS\\CALIBRIL.TTF")) {
    //Cosa de Error
  }
  text_.setFont(font_);
  update();
}

Debug::~Debug() {
}

void Debug::string(std::string buff) {
  text_.setString(buff);
}

void Debug::render(sf::RenderWindow& window) {
  window.draw(text_);
}

void Debug::update() {
  text_.setFillColor(sf::Color::White);
  text_.setStyle(sf::Text::Bold);
  text_.setCharacterSize(15);
}
