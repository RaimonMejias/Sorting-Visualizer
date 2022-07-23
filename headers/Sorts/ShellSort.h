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
  sf::Color color(int value);
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
      vector.clear(j);
      vector[j] = vector[j - delta];
      j = j - delta;
      vector.render(window);
      window.display();
      vector.color(j, color(i));
    }
    vector[j] = auxiliar;
  }  
}

template<class Temp>
sf::Color ShellSort<Temp>::color(int value) {
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