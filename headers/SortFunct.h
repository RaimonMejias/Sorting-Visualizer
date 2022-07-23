#ifndef SORTFUNCT_H
#define SORTFUNCT_H

#include <vector>

#include "Item.h"
#include "Utils.h"

template<class Temp>
class SortFunct {

public:

  virtual ~SortFunct() {};

  virtual std::string name() const = 0;
  virtual std::string info() const = 0;
  
  virtual bool sort(std::vector<Item<Temp> >& vector, int& access) = 0;
  void update(const std::vector<Item<Temp> >& vector);

};

template<class Temp>
void SortFunct<Temp>::update(const std::vector<Item<Temp> >& vector) {
  for (unsigned int i{0}; i < vector.size(); i++) {
    vector[i].update()
  }
}

#endif