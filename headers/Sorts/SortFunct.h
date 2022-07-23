#ifndef SORTFUNCT_H
#define SORTFUNCT_H

#include "SortingVector.h"

template<class Temp>
class SortFunct {
  
public:

  virtual ~SortFunct() {};

  virtual std::string name() const = 0;
  virtual std::string info() const = 0;
  
  virtual bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) = 0;

};

#endif