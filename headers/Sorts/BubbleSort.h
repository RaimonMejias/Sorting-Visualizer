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
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector) override;

private:

  Info<int> info_;
  
};

template<class Temp>
BubbleSort<Temp>::BubbleSort() {
  info_ = Info<int>{"BubbleSort", 1};
  info_.name_value(0, "I");
}

template<class Temp>
BubbleSort<Temp>::~BubbleSort() {

}

template<class Temp>
const Info<int>& BubbleSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool BubbleSort<Temp>::sort(SortingVector<Temp>& vector) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  for (int i{1}; i < vector.size(); i++) {
    info_.set_value(0, i);
    for (int j{vector.size() - 1}; j >= i; j--) {
      vector.color(j, sf::Color::Red);
      if (vector[j] < vector[j-1]) {
        vector.swap(vector[j-1], vector[j]);
      }
      vector.clear(j);
    }
  }
  return true;
}

#endif