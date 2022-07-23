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

private:

  int max_value(SortingVector<Temp>& vector, sf::RenderWindow& window) ; 
  sf::Color color(int value);

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
  while (radix <= 1000) {
    for(int i{0}; i < vector.size(); i++) {
      window.clear();
      vector.color(i, color((vector[i].item() % mod) / radix));
      stack_vector[(vector[i].item() % mod) / radix].push(vector[i]);
      vector.render(window);
      window.display();
    }
    int counter = 0;
    for(unsigned int i{0}; i < stack_vector.size(); i++) {
      while(!stack_vector[i].empty()) {
        window.clear();
        vector.color(counter, sf::Color::Red);
        vector[counter] = stack_vector[i].front();
        stack_vector[i].pop();
        vector.render(window);
        window.display();
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
int RadixSort<Temp>::max_value(SortingVector<Temp>& vector, sf::RenderWindow& window) { 
  int max = 0;
  for (int i{0}; i < vector.size(); i++) {
    window.clear();
    if (vector[max] < vector[i]) {
      max = i;
    }
    vector.color(i, sf::Color::Yellow);
    vector.render(window);
    window.display();
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

template<class Temp>
sf::Color RadixSort<Temp>::color(int value) {
  switch(value) {
    case 0:
      return sf::Color{142, 95, 172};
    case 1:
      return sf::Color::Blue;
    case 2:
      return sf::Color::Yellow;
    case 3:
      return sf::Color::Cyan;
    case 4:
      return sf::Color{138, 78, 18};
    case 5:
      return sf::Color{49, 102, 75};
    case 6:
      return sf::Color{255, 129, 0};
    case 7:
      return sf::Color{140, 196, 88};
    case 8:
      return sf::Color{252, 154, 154};
    case 9:
      return sf::Color{0, 83, 168};
  }
  return sf::Color::White;
}

#endif