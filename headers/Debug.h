/*!
 * @file Debug.h
 * @brief Clase auxiliar para realizar la impresión de información
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef DEBUG_H
#define DEBUG_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>

#include "Status.h"
#include "Info.h"
#include "Fonts.h"

struct viewer_status;

class Debug {

public:

  //Constructores y Destructor
  Debug();
  ~Debug();

  //Metodos
  void print(int cmps, int access, const Info<int>& info, const std::unique_ptr<viewer_status>& status);

  //Render y Update
  void render(sf::RenderWindow& window);

private:

  Fonts font_;
  sf::Text text_;
  sf::RectangleShape rect_;

};

#endif
