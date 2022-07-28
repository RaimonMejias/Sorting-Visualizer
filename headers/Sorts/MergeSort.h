/*!
 * @file MergeSort.h
 * @brief Clase que contiene la declaración e implementación de MergeSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
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
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;

private:

  void mergesort(SortingVector<Temp>& vector, int ini, int fin, std::unique_ptr<viewer_status>& status);
  void mix(SortingVector<Temp>& vector, int ini, int med, int fin, std::unique_ptr<viewer_status>& status);

  Info<int> info_;
  
};

/***************************************************************  Constructores y Destructor  ***************************************************************/
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

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& MergeSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool MergeSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) { 
  mergesort(vector, 0, vector.size() - 1, status);
  return true;
}

template<class Temp>
void MergeSort<Temp>::mergesort(SortingVector<Temp>& vector, int ini, int fin, std::unique_ptr<viewer_status>& status) {
  if (ini < fin) {
    int med = (ini + fin) / 2;
    mergesort(vector, ini, med, status);
    mergesort(vector, med + 1, fin, status);
    mix(vector, ini, med, fin, status);
  } 
}

template<class Temp>
void MergeSort<Temp>::mix(SortingVector<Temp>& vector, int ini, int med, int fin, std::unique_ptr<viewer_status>& status) {
  info_.set_value(0, ini);
  info_.set_value(1, med);
  info_.set_value(2, fin);
  int i = ini, j = med + 1, k = ini;
  vector.color(ini, sf::Color::Red);
  vector.color(fin, sf::Color::Blue);
  SortingVector<Temp> aux{vector.size()};

  while ((i <= med) && (j <= fin)) {
    if (this -> control(status)) { return; }
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
      if (this -> control(status)) { return; }
      aux[k] = vector[j];
      j++;
      k++;
    }
  } else {
    while (i <= med) {
      if (this -> control(status)) { return; }
      aux[k] = vector[i];
      i++;
      k++;
    }

  }
  for (int l{ini}; l <= fin; l++) {
    vector.color(l, sf::Color::Magenta);
    if (this -> control(status)) { return; }
    vector[l] = aux[l];  
    vector.clear(l);
  }
}

#endif