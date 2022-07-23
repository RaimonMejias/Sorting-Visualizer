#ifndef SELECTSORT_H
#define SELECTSORT_H

#include "SortFunct.h"

template <class Temp>
class SelectSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  SelectSort();
  ~SelectSort();

  //Getters y Setters
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;

};

template<class Temp>
SelectSort<Temp>::SelectSort() {

}

template<class Temp>
SelectSort<Temp>::~SelectSort() {

}

template<class Temp>
std::string SelectSort<Temp>::name() const {
  return "SelectSort";
}

template<class Temp>
std::string SelectSort<Temp>::info() const {
  return "En construcción";
}

template <class Temp>
bool SelectSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  for (int i{0}; i < vector.size(); i++) {
    int min = i;
    for (int j{i + 1}; j < vector.size(); j++) {
      vector[min].set_color(sf::Color::Magenta);
      window.clear();
      vector[j].set_color(sf::Color::Red);
      if (vector[j] <= vector[min]) { 
        vector[min].reset_color();
        min = j; 
      }
      vector.render(window);
      window.display();
      vector[j].reset_color();
    }
    vector[min].reset_color();
    if (min != i) {
      vector.swap(vector[min], vector[i]);
      vector[i].reset_color();
    } 
  }
  return true;
}

#endif