/*!
 * @file ShellSort.h
 * @brief Clase que contiene la declaración e implementación de ShellSort
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
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
  const Info<int>& info() const override;

  //Metodos
  bool sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) override;

private:

  void shellsort(int delta, SortingVector<Temp>& vector, int size, std::unique_ptr<viewer_status>& status);

  Info<int> info_;  
  
};

/***************************************************************  Constructores y Destructor  ***************************************************************/
template<class Temp>
ShellSort<Temp>::ShellSort() {
  info_ = Info<int>{"ShellSort", 3};
  info_.name_value(0, "DELTA");
  info_.name_value(1, "I");
  info_.name_value(2, "J");
}

template<class Temp>
ShellSort<Temp>::~ShellSort() {

}

/***************************************************************  Getters y Setters  ***************************************************************/
template<class Temp>
const Info<int>& ShellSort<Temp>::info() const {
  return info_;
}

/***************************************************************  Metodos  ***************************************************************/
template <class Temp>
bool ShellSort<Temp>::sort(SortingVector<Temp>& vector, std::unique_ptr<viewer_status>& status) {
  int delta = vector.size();
  while (delta > 1) {
    if (this -> control(status)) { return false; }
    delta = delta / 2;
    info_.set_value(0, delta);
    shellsort(delta, vector, vector.size(), status);
  }
  return true;
}

template<class Temp>
void ShellSort<Temp>::shellsort(int delta, SortingVector<Temp>& vector, int size, std::unique_ptr<viewer_status>& status) {
  for(int i{delta}; i < size; i++) {
    if (this -> control(status)) { return; }
    Item<Temp> auxiliar = vector[i];
    int j = i;
    info_.set_value(1, i);
    while ((j >= delta ) && (auxiliar < vector[j - delta])) {
      if (this -> control(status)) { return; }
      info_.set_value(2, j);
      vector.clear(j);
      vector[j] = vector[j - delta];
      j = j - delta;
      vector.color(j, SortFunct<Temp>::color(i));
    }
    vector[j] = auxiliar;
  }  
}

#endif