#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <queue>

#include "SortFunct.h"

template <class Temp>
class RadixSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  RadixSort();
  ~RadixSort();

  //Getters y Setters
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector) override;

private:

  int max_value(SortingVector<Temp>& vector) ; 

  Info<int> info_;

};

template<class Temp>
RadixSort<Temp>::RadixSort() {
  info_ = Info<int>{"RadixSort", 2};
  info_.name_value(0, "RADIX");
  info_.name_value(1, "MOD");
}

template<class Temp>
RadixSort<Temp>::~RadixSort() {

}

template<class Temp>
const Info<int>& RadixSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool RadixSort<Temp>::sort(SortingVector<Temp>& vector) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  std::vector<std::queue<Item<Temp>>> stack_vector;
  stack_vector.resize(10);
  int radix = 1;
  int mod = 10;
  while (radix <= 1000) {
    info_.set_value(0, radix);
    info_.set_value(1, mod);
    for(int i{0}; i < vector.size(); i++) {
      vector.color(i, SortFunct<Temp>::color((vector[i].item() % mod) / radix));
      stack_vector[(vector[i].item() % mod) / radix].push(vector[i]);
    }
    int counter = 0;
    for(unsigned int i{0}; i < stack_vector.size(); i++) {
      while(!stack_vector[i].empty()) {
        vector.color(counter, sf::Color::Red);
        vector[counter] = stack_vector[i].front();
        stack_vector[i].pop();
        vector.clear(counter);
        counter++;
      }
    }
    radix *= 10;
    mod *= 10;
  }
  return true;
}

template<class Temp> //HAY ALGO MAL AQUI 
int RadixSort<Temp>::max_value(SortingVector<Temp>& vector) { 
  int max = 0;
  for (int i{0}; i < vector.size(); i++) {
    if (vector[max] < vector[i]) {
      max = i;
    }
    vector.color(i, sf::Color::Yellow);
    vector.clear(i);
  }
  int result;
  Temp max_value = vector[max].item(); 
  while (max_value != 0) {
    max_value = max_value / 10;
    result++;
  }
  return result;
}

#endif