/*!
 * @file SelectSort.h
 * @brief Clase que contiene la declaración e implementación de SelectSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
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
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;

private:

  Info<int> info_;

};

/***************************************************************  Constructores y Destructor  ***************************************************************/
template<class Temp>
SelectSort<Temp>::SelectSort() {
  info_ = Info<int>{"SelectSort", 3};
  info_.name_value(0, "I");
  info_.name_value(1, "J");
  info_.name_value(2, "MIN");
}

template<class Temp>
SelectSort<Temp>::~SelectSort() {

}

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& SelectSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool SelectSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  for (int i{0}; i < vector.size(); i++) {
    int min = i;
    info_.set_value(0, i);
    info_.set_value(2, (int)vector[min].item());
    for (int j{i + 1}; j < vector.size(); j++) {
      if (this -> control(status)) { return false; }
      info_.set_value(1, j);
      vector.color(min, sf::Color::Magenta);
      vector.color(j, sf::Color::Red);
      if (vector[j] <= vector[min]) { 
        vector.clear(min);
        min = j; 
        info_.set_value(2, (int)vector[min].item());
      }
      vector.clear(j);
    }
    vector.clear(min);
    if (min != i) {
      vector.swap(vector[min], vector[i]);
      vector.clear(i);
    } 
  }
  return true;
}

#endif