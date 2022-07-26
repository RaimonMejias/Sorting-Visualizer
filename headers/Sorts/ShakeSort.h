#ifndef SHAKESORT_H
#define SHAKESORT_H

#include "SortFunct.h"

template<class Temp>
class ShakeSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  ShakeSort();
  ~ShakeSort();

  //Getters y Setters 
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector) override;
  
private:

  Info<int> info_;

};

template<class Temp>
ShakeSort<Temp>::ShakeSort() {
  info_ = Info<int>{"ShakeSort", 3};
  info_.name_value(0, "INI");
  info_.name_value(1, "FIN");
  info_.name_value(2, "CAM");
}

template<class Temp>
ShakeSort<Temp>::~ShakeSort() {

}

template<class Temp>
const Info<int>& ShakeSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool ShakeSort<Temp>::sort(SortingVector<Temp>& vector) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  int ini = 1, fin = vector.size() - 1, cam = vector.size();
  while (ini < fin) {
    info_.set_value(0, ini);
    info_.set_value(1, fin);
    for (int i{ini}; i <= fin; i++) {
      vector.color(i, sf::Color::Red);
      if (vector[i] <= vector[i - 1]) {
        vector.swap(vector[i - 1], vector[i]);
        cam = i;
        info_.set_value(2, cam);
      }
      vector.clear(i);
    }
    fin = cam -1;
    for(int i{fin}; i >= ini; i--) {
      vector.color(i, sf::Color::Red);
      if (vector[i] <= vector[i - 1]) {
        vector.swap(vector[i - 1], vector[i]);
        cam = i;
        info_.set_value(2, cam);
      }
      vector.clear(i);
    }
    ini = cam + 1;
  }
  return true;
}

#endif