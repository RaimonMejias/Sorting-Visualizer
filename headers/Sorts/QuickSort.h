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
  bool sort(SortingVector<Temp>& vector) override;

private:

  void quicksort(SortingVector<Temp>& vector, int ini, int fin);

  Info<int> info_;
  
};


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

template<class Temp>
const Info<int>& QuickSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool QuickSort<Temp>::sort(SortingVector<Temp>& vector) { 
  quicksort(vector, 0, vector.size()- 1);
  return true;
}

template<class Temp>
void QuickSort<Temp>::quicksort(SortingVector<Temp>& vector, int ini, int fin) {
  int i = ini, j = fin;
  info_.set_value(0, ini);
  info_.set_value(1, fin);
  info_.set_value(2, vector[(i + j) / 2].item());
  Item<Temp> pivot = vector[(i + j) / 2];
  vector.color((i + j) / 2, sf::Color::Magenta);
  while (i <= j) {
    while (vector[i] < pivot) {
      vector.color(i, sf::Color::Red);
      vector.color(i, sf::Color{254, 71, 71});
      i++;
    }
    while (vector[j] > pivot) {
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
  for (int i{0}; i < vector.size(); i++) {
    vector.clear(i);
  }
  if (ini < j) { quicksort(vector, ini, j); }
  if (i < fin) { quicksort(vector, i, fin); }  
}

#endif