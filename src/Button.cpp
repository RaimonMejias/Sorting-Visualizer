/*!
 * @file Button.cpp
 * @brief Implementación de los metodos de la clase Button
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#include "Button.h"

/***************************************************************  Constructores y Destructor  ***************************************************************/
Button::Button() {
  
}

Button::Button(sf::Vector2f pos, const std::string& text) {
  
  rect_.setPosition(pos);
  rect_.setFillColor(sf::Color::Black);
  rect_.setOutlineThickness(1);
  rect_.setSize(sf::Vector2f{85, 20});

  text_.setFont(Fonts::Calibri);
  text_.setString(text);
  text_.setCharacterSize(15);
  text_.setOutlineColor(sf::Color::Black);
  text_.setOutlineThickness(1);
  text_.setStyle(sf::Text::Bold);
  text_.setPosition(rect_.getPosition().x + 5, rect_.getPosition().y);
}

/***************************************************************  Getters y Setters  ***************************************************************/
bool Button::is_over(sf::RenderWindow& window) {
  float mousex = sf::Mouse::getPosition(window).x;
  float mousey = sf::Mouse::getPosition(window).y;

  float posx = rect_.getPosition().x;
  float posy = rect_.getPosition().y;

  float gposx = rect_.getPosition().x + rect_.getGlobalBounds().width;
  float gposy = rect_.getPosition().y + rect_.getGlobalBounds().height;

  if (mousex < gposx && mousex > posx && mousey < gposy && mousey > posy) {
    rect_.setFillColor(sf::Color{191, 184, 191});
    return true;
  }
  rect_.setFillColor(sf::Color::Black);
  return false;
}

/***************************************************************  Renders y Updates  ***************************************************************/
void Button::render(sf::RenderWindow& window) {
  window.draw(rect_);
  window.draw(text_);
}