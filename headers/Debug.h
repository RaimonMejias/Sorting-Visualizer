#ifndef DEBUG_H
#define DEBUG_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>

#include "Info.h"
#include "Fonts.h"

struct viewer_status;

class Debug {

public:

  //Constructores y Destructor
  Debug();
  ~Debug();

  //Getters y Setters
  void print(int cmps, int access, const Info<int>& info, const std::unique_ptr<viewer_status>& status);

  //Metodos

  //Render y Update
  void render(sf::RenderWindow& window);

  //Operadores

private:

  Fonts font_;
  sf::Text text_;
  sf::RectangleShape rect_;

};

#endif
