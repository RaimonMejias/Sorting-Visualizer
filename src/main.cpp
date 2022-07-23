#include <iostream>
#include "SelectSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"
#include "ShakeSort.h"
#include "QuickSort.h"
#include "SortingVector.h"

int main() {

  sf::RenderWindow window{sf::VideoMode{1280, 720}, "Visualizador"};
  window.setFramerateLimit(60);

  SortFunct<int>* funct= new QuickSort<int>();
  Debug* debug = new Debug();
  SortingVector<int> vector{128, funct, debug};
  vector.unsort();
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)                  { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close();  }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  { vector.update(); }

    }
/*
    if (!vector.is_done()) {
      vector.update();
    }

    window.clear();
    vector.render(window);
    window.display();
*/

  }

  return 0;
}