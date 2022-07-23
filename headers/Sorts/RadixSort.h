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
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;
  int max_value(SortingVector<Temp>& vector, sf::RenderWindow& window) ;
};

template<class Temp>
RadixSort<Temp>::RadixSort() {

}

template<class Temp>
RadixSort<Temp>::~RadixSort() {

}

template<class Temp>
std::string RadixSort<Temp>::name() const {
  return "RadixSort";
}

template<class Temp>
std::string RadixSort<Temp>::info() const {
  return "En construcción";
}

template <class Temp>
bool RadixSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  std::vector<std::queue<Item<Temp>>> stack_vector;
  stack_vector.resize(10);
  int radix = 1;
  int mod = 10;
  int max = max_value(vector, window);
  
  for (int i{0}; i < max; i++) {
    for(int i{0}; i < vector.size(); i++) {
      window.clear();
      vector[i].set_color(sf::Color::Red);
      stack_vector[(vector[i].item() % mod) / radix].push(vector[i]);
      vector.render(window);
      window.display();
      vector[i].reset_color();
    }
    int counter = 0;
    for(unsigned int i{0}; i < stack_vector.size(); i++) {
      while(!stack_vector[i].empty()) {
        window.clear();
        vector[counter].set_color(sf::Color::Red);
        vector[counter] = stack_vector[i].front();
        stack_vector[i].pop();
        vector.render(window);
        window.display();
        vector[counter].reset_color();
        counter++;
      }
    }
    radix *= 10;
    mod *= 10;
  }
  return true;
}

template<class Temp>
int RadixSort<Temp>::max_value(SortingVector<Temp>& vector, sf::RenderWindow& window) { 
  int max = 0;
  for (int i{0}; i < vector.size(); i++) {
    window.clear();
    if (vector[max] < vector[i]) {
      max = i;
    }
    vector[i].set_color(sf::Color::Yellow);
    vector.render(window);
    window.display();
    vector[i].reset_color();
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