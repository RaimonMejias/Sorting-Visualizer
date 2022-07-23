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
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;
  void Mergesort(SortingVector<Temp>& vector, sf::RenderWindow& window, int ini, int fin);
};


template<class Temp>
MergeSort<Temp>::MergeSort() {

}

template<class Temp>
MergeSort<Temp>::~MergeSort() {

}

template<class Temp>
std::string MergeSort<Temp>::name() const {
  return "MergeSort";
}

template<class Temp>
std::string MergeSort<Temp>::info() const {
  return "ss.str()";
}

template <class Temp>
bool MergeSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { 
  Mergesort(vector, window, 0, vector.size() - 1);
  return true;
}

template<class Temp>
void MergeSort<Temp>::Mergesort(SortingVector<Temp>& vector, sf::RenderWindow& window, int ini, int fin) {
  if (ini < fin) {
    int med = (ini + fin) / 2;
    Mergesort(vector, window, ini, med);
    Mergesort(vector, window, med + 1, fin);
    mix(vector, window, ini, med, fin);
  } 
}

template<class Temp>
void mix(SortingVector<Temp>& vector, sf::RenderWindow& window, int ini, int med, int fin) {
  int i = ini, j = med + 1, k = ini;
  vector.color(ini, sf::Color::Red);
  vector.color(fin, sf::Color::Blue);
  SortingVector<Temp> aux{vector.size()};

  while ((i <= med) && (j <= fin)) {
    window.clear();
    if (vector[i] < vector[j]) {
      aux[k] = vector[i];
      i++;
    } else {
      aux[k] = vector[j];
      j++;
    }
    k++;
    vector.render(window);
    window.display();
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
    window.clear();
    vector[l] = aux[l];  
    vector.color(l, sf::Color::Magenta);
    vector.render(window);
    window.display();
    vector.clear(l);
  }
}

#endif