#include <iostream>

#include "Viewer.h"
#include "Externals\RichText-master\RichText.hpp"

int main() {

  sf::RenderWindow window{sf::VideoMode{1280, 720}, "Visualizador"};
  sf::Event event;
  window.setFramerateLimit(60);

  Viewer view{128, 0};

  while (window.isOpen()) {
    
    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)                  { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  { view.start();    }

    }

    window.clear();
    view.render(window);
    window.display();

  }
  return 0;
}