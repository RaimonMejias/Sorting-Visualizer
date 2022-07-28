/*!
 * @file Debug.cpp
 * @brief Implementación de los metodos de la clase Debug
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#include <iostream>

#include "Viewer.h"

int main() {

  sf::RenderWindow window{sf::VideoMode{1280, 720}, "Visualizador"};
  sf::Event event;
  window.setFramerateLimit(60);

  Viewer view{128};

  while (window.isOpen()) {
    
    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)                  { window.close();       }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close();       }
      if (event.type == sf::Event::MouseMoved)              { view.is_over(window); }

      if (event.type == sf::Event::MouseButtonPressed) {
        view.action(view.is_pressed(window));
      }
    }

    window.clear();
    view.render(window);
    window.display();

  }
  return 0;
}