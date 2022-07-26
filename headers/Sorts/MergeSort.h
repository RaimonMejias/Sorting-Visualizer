#ifndef MERGESORT_H
#define MERGESORT_H

#include <stack>
#include "SortFunct.h"

template<class Temp>
class MergeSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  MergeSort();
  ~MergeSort();

  //Getters y Setters
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector) override;

private:

  void Mergesort(SortingVector<Temp>& vector, int ini, int fin);
  void mix(SortingVector<Temp>& vector, int ini, int med, int fin);

  Info<int> info_;
  
};


template<class Temp>
MergeSort<Temp>::MergeSort() {
  info_ = Info<int>{"MergeSort", 3};
  info_.name_value(0, "INI");
  info_.name_value(1, "MED");
  info_.name_value(2, "FIN");
}

template<class Temp>
MergeSort<Temp>::~MergeSort() {

}

template<class Temp>
const Info<int>& MergeSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool MergeSort<Temp>::sort(SortingVector<Temp>& vector) { 
  Mergesort(vector, 0, vector.size() - 1);
  return true;
}

template<class Temp>
void MergeSort<Temp>::Mergesort(SortingVector<Temp>& vector, int ini, int fin) {
  if (ini < fin) {
    int med = (ini + fin) / 2;
    Mergesort(vector, ini, med);
    Mergesort(vector, med + 1, fin);
    mix(vector, ini, med, fin);
  } 
}

template<class Temp>
void MergeSort<Temp>::mix(SortingVector<Temp>& vector, int ini, int med, int fin) {
  info_.set_value(0, ini);
  info_.set_value(1, med);
  info_.set_value(2, fin);
  int i = ini, j = med + 1, k = ini;
  vector.color(ini, sf::Color::Red);
  vector.color(fin, sf::Color::Blue);
  SortingVector<Temp> aux{vector.size()};

  while ((i <= med) && (j <= fin)) {
    if (vector[i] < vector[j]) {
      aux[k] = vector[i];
      i++;
    } else {
      aux[k] = vector[j];
      j++;
    }
    k++;
  } 
  if (i > med) {
    while (j <= fin) {
      aux[k] = vector[j];
      j++;
      k++;
    }
  } else {
    while (i <= med) {
      aux[k] = vector[i];
      i++;
      k++;
    }

  }
  for (int l{ini}; l <= fin; l++) {
    vector[l] = aux[l];  
    vector.color(l, sf::Color::Magenta);
    vector.clear(l);
  }
}

#endif