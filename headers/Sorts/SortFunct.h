#ifndef SORTFUNCT_H
#define SORTFUNCT_H

#include "SortingVector.h"
#include "Info.h"

template<class Temp>
class SortFunct {
  
public:

  virtual ~SortFunct() {};

  virtual const Info<int>& info() const = 0;
  
  virtual bool sort(SortingVector<Temp>& vector) = 0;

  sf::Color color(int value);

};

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

#endif