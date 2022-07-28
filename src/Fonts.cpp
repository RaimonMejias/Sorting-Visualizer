/*!
 * @file Fonts.cpp
 * @brief Implementación de los metodos de la clase Fonts
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#include "Fonts.h"

/***************************************************************  Constructores y Destructor  ***************************************************************/
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

/***************************************************************  Getters y Setters  ***************************************************************/
bool Fonts::is_loaded() const {
  return loaded_;
}

std::string Fonts::font() const {
  if (loaded_) {
    return getInfo().family;
  }
  return "Not loaded";
}

/***************************************************************  Prefabs  ***************************************************************/
const sf::Font Fonts::Calibri = Fonts("CALIBRIL.TTF");
const sf::Font Fonts::Arial =   Fonts("ARIAL.TTF");

