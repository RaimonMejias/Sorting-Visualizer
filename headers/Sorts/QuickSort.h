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
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;
  void quicksort(SortingVector<Temp>& vector, sf::RenderWindow& window, int ini, int fin);
};


template<class Temp>
QuickSort<Temp>::QuickSort() {

}

template<class Temp>
QuickSort<Temp>::~QuickSort() {

}

template<class Temp>
std::string QuickSort<Temp>::name() const {
  return "QuickSort";
}

template<class Temp>
std::string QuickSort<Temp>::info() const {
  return "ss.str()";
}

template <class Temp>
bool QuickSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { 
  quicksort(vector, window, 0, vector.size()- 1);
  return true;
}

template<class Temp>
void QuickSort<Temp>::quicksort(SortingVector<Temp>& vector, sf::RenderWindow& window, int ini, int fin) {
  int i = ini, j = fin;
  Item<Temp> pivot = vector[(i + j) / 2];
  vector[(i + j) / 2].set_color(sf::Color::Magenta);
  while (i <= j) {
    while (vector[i] < pivot) {
      window.clear();
      vector[i].set_color(sf::Color::Red);
      vector.render(window);
      window.display();
      vector[i].set_color(sf::Color{254, 71, 71});
      i++;
    }
    while (vector[j] > pivot) {
      window.clear();
      vector[j].set_color(sf::Color::Blue);
      vector.render(window);
      window.display();
      vector[j].set_color(sf::Color{91, 91, 254});
      j--;
    }
    if (i <= j) {
      vector.swap(vector[i], vector[j]);
      vector[i].set_color(sf::Color{254, 71, 71});
      vector[j].set_color(sf::Color{91, 91, 254});
      i++;
      j--;
    } 
  }
  for (int i{0}; i < vector.size(); i++) {
    vector[i].reset_color();
  }
  if (ini < j) { quicksort(vector, window, ini, j); }
  if (i < fin) { quicksort(vector, window, i, fin); }  
}

#endif