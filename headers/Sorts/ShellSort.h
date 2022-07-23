#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "SortFunct.h"

template <class Temp>
class ShellSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  ShellSort();
  ~ShellSort();

  //Getters y Setters
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, sf::RenderWindow& window) override;

private:

  void Delta(int delta, SortingVector<Temp>& vector, sf::RenderWindow& window, int size);

};

template<class Temp>
ShellSort<Temp>::ShellSort() {

}

template<class Temp>
ShellSort<Temp>::~ShellSort() {

}

template<class Temp>
std::string ShellSort<Temp>::name() const {
  return "ShellSort";
}

template<class Temp>
std::string ShellSort<Temp>::info() const {
  return "En construcción";
}

template <class Temp>
bool ShellSort<Temp>::sort(SortingVector<Temp>& vector, sf::RenderWindow& window) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  int delta = vector.size();
  while (delta > 1) {
    delta = delta / 2;
    Delta(delta, vector, window, vector.size());
  }
  return true;
}

template<class Temp>
void ShellSort<Temp>::Delta(int delta, SortingVector<Temp>& vector, sf::RenderWindow& window, int size) {
  for(int i{delta}; i < size; i++) {
    Item<Temp> auxiliar = vector[i];
    int j = i;
    while ((j >= delta ) && (auxiliar < vector[j - delta])) {
      window.clear();
      vector[j].reset_color();
      vector[j] = vector[j - delta];
      j = j - delta;
      vector.render(window);
      window.display();
      vector[j].set_color(sf::Color{125, 125, 125});
    }
    vector[j] = auxiliar;
  }  
}

#endif