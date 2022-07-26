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
  bool sort(SortingVector<Temp>& vector) override;
  
private:

  Info<int> info_;

};

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

template<class Temp>
const Info<int>& InsertSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool InsertSort<Temp>::sort(SortingVector<Temp>& vector) { 
  for (int i{1}; i < vector.size(); i++) {
    Item<Temp> key = vector[i];
    info_.set_value(0, i);
    info_.set_value(2, vector[i].item());
    vector.color(i + 1, sf::Color::Magenta);
    int j = i; 
    while (key < vector[j - 1] && (j > 0) ) {
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