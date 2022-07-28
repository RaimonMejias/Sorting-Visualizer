/*!
 * @file Debug.cpp
 * @brief Implementación de los metodos de la clase Debug
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#include "Debug.h"

/***************************************************************  Constructores y Destructor  ***************************************************************/
Debug::Debug() {
  font_ = Fonts{"CALIBRIL.TTF"};
  text_.setFont(font_);
}

Debug::~Debug() {

}

/***************************************************************  Metodos  ***************************************************************/
void Debug::print(int cmps, int access, const Info<int>& info, const std::unique_ptr<viewer_status>& status) {

  if (!font_.is_loaded()) { return; }

  std::stringstream ss;
  ss << "Algoritmo = " << info.name() << " | Comparaciones = " << cmps << " | Accesos = " << access << " | Estado = ";

  if      (status -> PAUSED)    { ss << "En Pausa | ";    }
  else if (status -> SHUFFLING) { ss << "Mezclando | ";   }
  else if (status -> SORTING)   { ss << "Ordenando | ";   }
  else if (status -> CHECKING)  { ss << "Comprobando | "; }
  else                          { ss << "Ordenado | ";    }

  for (int i{0}; i < info.size(); i++) {
    ss << info.value(i).first << " = " << info.value(i).second << ((i < info.size() - 1)? " | " : "");
  }
  text_.setString(ss.str());
}

/***************************************************************  Renders y Updates  ***************************************************************/
void Debug::render(sf::RenderWindow& window) {
  rect_.setPosition(1, 1);
  rect_.setSize(sf::Vector2f{1278, 20});
  rect_.setFillColor(sf::Color::Black);
  rect_.setOutlineThickness(1);
  text_.setPosition(5, 0);
  text_.setFillColor(sf::Color::White);
  text_.setStyle(sf::Text::Bold);
  text_.setCharacterSize(15);
  window.draw(rect_);
  window.draw(text_);
}