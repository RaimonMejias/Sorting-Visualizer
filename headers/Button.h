/*!
 * @file Button.h
 * @brief Clase utilizada para implementar la funcionalidad de un botón
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include "Fonts.h"

class Button {

public:

  //Constructores y Destructor
  Button();
  Button(sf::Vector2f pos, const std::string& text);

  //Getters y Setters
  bool is_over(sf::RenderWindow& window);

  //Renders y Updates
  void render(sf::RenderWindow& window);

private:

  sf::Text text_;
  sf::RectangleShape rect_;

};

#endif