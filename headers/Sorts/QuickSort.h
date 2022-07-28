/*!
 * @file QuickSort.h
 * @brief Clase que contiene la declaración e implementación de QuickSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stack>
#include "SortFunct.h"

template<class Temp>
class QuickSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  QuickSort();
  ~QuickSort();

  //Getters y Setters
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;

private:

  void quicksort(SortingVector<Temp>& vector, int ini, int fin, std::unique_ptr<viewer_status>& status);

  Info<int> info_;
   
};

/***************************************************************  Constructores y Destructor  ***************************************************************/
template<class Temp>
QuickSort<Temp>::QuickSort() {
  info_ = Info<int>{"QuickSort", 3};
  info_.name_value(0, "INI");
  info_.name_value(1, "FIN");
  info_.name_value(2, "PIVOT");
}

template<class Temp>
QuickSort<Temp>::~QuickSort() {

}

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& QuickSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool QuickSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) { 
  quicksort(vector, 0, vector.size()- 1, status);
  return true;
}

template<class Temp>
void QuickSort<Temp>::quicksort(SortingVector<Temp>& vector, int ini, int fin, std::unique_ptr<viewer_status>& status) {
  int i = ini, j = fin;
  info_.set_value(0, ini);
  info_.set_value(1, fin);
  info_.set_value(2, vector[(i + j) / 2].item());
  Item<Temp> pivot = vector[(i + j) / 2];
  vector.color((i + j) / 2, sf::Color::Magenta);
  while (i <= j) {
    while (vector[i] < pivot) {
      if (this -> control(status)) { return; }
      vector.color(i, sf::Color::Red);
      vector.color(i, sf::Color{254, 71, 71});
      i++;
    }
    while (vector[j] > pivot) {
      if (this -> control(status)) { return; }
      vector.color(j, sf::Color::Blue);
      vector.color(j, sf::Color{91, 91, 254});
      j--;
    }
    if (i <= j) {
      vector.swap(vector[i], vector[j]);
      vector.color(i, sf::Color{254, 71, 71});
      vector.color(j, sf::Color{91, 91, 254});
      i++;
      j--;
    } 
  }
  vector.bleach();
  if (ini < j) { quicksort(vector, ini, j, status); }
  if (i < fin) { quicksort(vector, i, fin, status); }  
}

#endif