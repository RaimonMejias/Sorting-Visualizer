#include <iostream>

#include "Viewer.h"

int main() {

  sf::RenderWindow window{sf::VideoMode{1280, 720}, "Visualizador"};
  window.setFramerateLimit(60);

  Viewer view{128, 0, 7};
  view.shuffle(window);
  bool once = true;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)                  { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  { /*vector.update();*/ }

    }
    
    if (!view.is_done()) {
      view.sort(window);
    }

    if (once) {
      view.check(window);
      once = false;
    }

    window.clear();
    view.render(window);
    window.display();

  }
  return 0;
}