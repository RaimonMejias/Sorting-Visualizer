#include <iostream>

#include "Viewer.h"

int main() {

  sf::RenderWindow window{sf::VideoMode{1280, 720}, "Visualizador"};
  window.setFramerateLimit(60);

  Viewer view{25, 0, 0};
  bool once = true;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)                  { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  { /*vector.update();*/ }

    }
    
    if (once) {
      for (int i{0}; i < 8; i++) {
        view.shuffle(window);
        view.set_sort(i);
        view.sort(window);
        view.check(window);
        view.clear();
      }
      once = false;
    }

    window.clear();
    view.render(window);
    window.display();

  }
  return 0;
}