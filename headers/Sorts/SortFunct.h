/*!
 * @file SortFunct.h
 * @brief Clase abstracta para simplificar la selección de un algoritmo de ordenación
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef SORTFUNCT_H
#define SORTFUNCT_H

#include "SortingVector.h"
#include "Status.h"
#include "Info.h"

template<class Temp>
class SortFunct {
  
public:

  //Constructores y Destructor
  virtual ~SortFunct() {};

  //Getters y Setters
  virtual const Info<int>& info() const = 0;
  sf::Color color(int value);
  bool control(std::unique_ptr<viewer_status>& status);

  //Metodos
  virtual bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) = 0;

};

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
sf::Color SortFunct<Temp>::color(int value) {
  switch(value) {
    case 0:
      return sf::Color{142, 95, 172};
    case 1:
      return sf::Color::Blue;
    case 2:
      return sf::Color::Yellow;
    case 3:
      return sf::Color::Cyan;
    case 4:
      return sf::Color{138, 78, 18};
    case 5:
      return sf::Color{49, 102, 75};
    case 6:
      return sf::Color{255, 129, 0};
    case 7:
      return sf::Color{140, 196, 88};
    case 8:
      return sf::Color{252, 154, 154};
    case 9:
      return sf::Color{0, 83, 168};
  }
  return sf::Color::White;
}

template<class Temp>
bool SortFunct<Temp>::control(std::unique_ptr<viewer_status>& status) {
  while (status -> PAUSED && !status -> QUIT) { std::this_thread::sleep_for(std::chrono::microseconds(1)); }
  return status -> QUIT;
}

#endif