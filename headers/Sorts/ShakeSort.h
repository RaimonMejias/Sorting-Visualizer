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
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;

};

template<class Temp>
ShakeSort<Temp>::ShakeSort() {

}

template<class Temp>
ShakeSort<Temp>::~ShakeSort() {

}

template<class Temp>
std::string ShakeSort<Temp>::name() const {
  return "ShakeSort";
}

template<class Temp>
std::string ShakeSort<Temp>::info() const {
  return "ss.str()";
}

template <class Temp>
bool ShakeSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  int ini = 1, fin = vector.size() - 1, cam = vector.size();
  while (ini < fin) {
    for (int i{ini}; i <= fin; i++) {
      window.clear();
      vector[i].set_color(sf::Color::Red);
      if (vector[i] <= vector[i - 1]) {
        vector.swap(vector[i - 1], vector[i]);
        cam = i;
      }
      vector.render(window);
      window.display();
      vector[i].reset_color();
    }
    fin = cam -1;
    for(int i{fin}; i >= ini; i--) {
      window.clear();
      vector[i].set_color(sf::Color::Red);
      if (vector[i] <= vector[i - 1]) {
        vector.swap(vector[i - 1], vector[i]);
        cam = i;
      }
      vector.render(window);
      window.display();
      vector[i].reset_color();
    }
    ini = cam + 1;
  }
  return true;
}

#endif