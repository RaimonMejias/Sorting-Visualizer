#include "Fonts.h"

Fonts::Fonts() {
  loaded_ = false;
}

Fonts::Fonts(const std::string& font) {
  loaded_ = true;
  if (!loadFromFile(DEFAULT_PATH + font)) {
    loaded_ = false;
  }
}

Fonts::Fonts(const Fonts& font) {
  loaded_ = true;
  if (!loadFromFile(DEFAULT_PATH + font.font())) {
    loaded_ = false;
  }
}

bool Fonts::is_loaded() const {
  return loaded_;
}

std::string Fonts::font() const {
  if (loaded_) {
    return getInfo().family;
  }
  return "Not loaded";
}

const sf::Font Fonts::Calibri = Fonts("CALIBRIL.TTF");
const sf::Font Fonts::Arial =   Fonts("ARIAL.TTF");

