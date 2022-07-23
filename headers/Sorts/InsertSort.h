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
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;

};

template<class Temp>
InsertSort<Temp>::InsertSort() {

}

template<class Temp>
InsertSort<Temp>::~InsertSort() {

}

template<class Temp>
std::string InsertSort<Temp>::name() const {
  return "InsertSort";
}

template<class Temp>
std::string InsertSort<Temp>::info() const {
  return "ss.str()";
}

template <class Temp>
bool InsertSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { 
  for (int i{1}; i < vector.size(); i++) {
    Item<Temp> key = vector[i];
    vector[i + 1].set_color(sf::Color::Magenta);
    int j = i; 
    while (key < vector[j - 1] && (j > 0) ) { 
      window.clear();
      vector[j - 1].set_color(sf::Color::Red);
      vector[j] = vector[j - 1];
      j--;
      vector.render(window);
      window.display();
      vector[j].reset_color();
    }
    vector[j] = key;
    vector[i + 1].reset_color();
  }
  return true;
}

#endif