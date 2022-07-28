/*!
 * @file InsertSort.h
 * @brief Clase que contiene la declaración e implementación de InsertSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef INSERTSORT_H
#define INSERTSORT_H

#include "SortFunct.h"

template<class Temp>
class InsertSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  InsertSort();
  ~InsertSort();

  //Getters y Setters
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;
  
private:

  Info<int> info_;

};

/***************************************************************  Constructores y Destructor  ***************************************************************/
template<class Temp>
InsertSort<Temp>::InsertSort() {
  info_ = Info<int>{"InsertSort", 3};
  info_.name_value(0, "I");
  info_.name_value(1, "J");
  info_.name_value(2, "KEY");
}

template<class Temp>
InsertSort<Temp>::~InsertSort() {

}

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& InsertSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool InsertSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) { 
  for (int i{1}; i < vector.size(); i++) {
    if (this -> control(status)) { return false; }
    Item<Temp> key = vector[i];
    info_.set_value(0, i);
    info_.set_value(2, vector[i].item());
    vector.color(i + 1, sf::Color::Magenta);
    int j = i; 
    while (key < vector[j - 1] && (j > 0) ) {
      if (this -> control(status)) { return false; }
      info_.set_value(1, j); 
      vector.color(j - 1, sf::Color::Red);
      vector[j] = vector[j - 1];
      j--;
      vector.clear(j);
    }
    vector[j] = key;
    vector.clear(i + 1);
  }
  return true;
}

#endif