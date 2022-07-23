#ifndef DEBUG_H
#define DEBUG_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>

class Debug {

public:

  //Constructores y Destructor
  Debug();
  ~Debug();

  //Getters y Setters
  void string(std::string buff);

  //Metodos

  //Render y Update
  void render(sf::RenderWindow& window);
  void update();

  //Operadores

private:

  sf::Font font_;
  sf::Text text_;

};

#endif
