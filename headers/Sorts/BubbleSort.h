#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortFunct.h"

template<class Temp>
class BubbleSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  BubbleSort();
  ~BubbleSort();

  //Getters y Setters
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;

};

template<class Temp>
BubbleSort<Temp>::BubbleSort() {

}

template<class Temp>
BubbleSort<Temp>::~BubbleSort() {

}

template<class Temp>
std::string BubbleSort<Temp>::name() const {
  return "BubbleSort";
}

template<class Temp>
std::string BubbleSort<Temp>::info() const {
  return "ss.str";
}

template <class Temp>
bool BubbleSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  for (int i{1}; i < vector.size(); i++) {
    for (int j{vector.size() - 1}; j >= i; j--) {
      window.clear();
      vector.color(j, sf::Color::Red);
      if (vector[j] < vector[j-1]) {
        vector.swap(vector[j-1], vector[j]);
      }
      vector.render(window);
      window.display();
      vector.clear(j);
    }
  }
  return true;
}

#endif