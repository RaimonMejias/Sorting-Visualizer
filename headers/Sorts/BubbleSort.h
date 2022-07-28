/*!
 * @file BubbleSort.h
 * @brief Clase que contiene la declaración e implementación de BubbleSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
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
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;

private:

  Info<int> info_;
  
};

/***************************************************************  Constructores y Destructor  ***************************************************************/
template<class Temp>
BubbleSort<Temp>::BubbleSort() {
  info_ = Info<int>{"BubbleSort", 1};
  info_.name_value(0, "I");
}

template<class Temp>
BubbleSort<Temp>::~BubbleSort() {

}

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& BubbleSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool BubbleSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  for (int i{1}; i < vector.size(); i++) {
    info_.set_value(0, i);
    for (int j{vector.size() - 1}; j >= i; j--) {
      if (this -> control(status)) { return false; }
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