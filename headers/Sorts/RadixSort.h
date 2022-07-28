/*!
 * @file RadixSort.h
 * @brief Clase que contiene la declaración e implementación de RadixSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
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
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;

private:

  Info<int> info_;

};

/***************************************************************  Constructores y Destructor  ***************************************************************/
template<class Temp>
RadixSort<Temp>::RadixSort() {
  info_ = Info<int>{"RadixSort", 2};
  info_.name_value(0, "RADIX");
  info_.name_value(1, "MOD");
}

template<class Temp>
RadixSort<Temp>::~RadixSort() {

}

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& RadixSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool RadixSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  std::vector<std::queue<Item<Temp> > > stack_vector;
  stack_vector.resize(10);
  int radix = 1;
  int mod = 10;
  while (radix <= 1000) {
    info_.set_value(0, radix);
    info_.set_value(1, mod);
    for(int i{0}; i < vector.size(); i++) {
      if (this -> control(status)) { return false; }
      vector.color(i, this -> color((vector[i].item() % mod) / radix));
      stack_vector[(vector[i].item() % mod) / radix].push(vector[i]);
    }
    int counter = 0;
    for(unsigned int i{0}; i < stack_vector.size(); i++) {
      while(!stack_vector[i].empty()) {
        if (this -> control(status)) { return false; }
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

#endif