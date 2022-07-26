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
  bool sort(SortingVector<Temp>& vector) override;

private:

  void Delta(int delta, SortingVector<Temp>& vector, int size);

  Info<int> info_;  
  
};

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

template<class Temp>
const Info<int>& ShellSort<Temp>::info() const {
  return info_;
}

template <class Temp>
bool ShellSort<Temp>::sort(SortingVector<Temp>& vector) { ///SIIIIIIIIIIIIUUUUUUUUUUUUUU
  int delta = vector.size();
  while (delta > 1) {
    delta = delta / 2;
    info_.set_value(0, delta);
    Delta(delta, vector, vector.size());
  }
  return true;
}

template<class Temp>
void ShellSort<Temp>::Delta(int delta, SortingVector<Temp>& vector, int size) {
  for(int i{delta}; i < size; i++) {
    Item<Temp> auxiliar = vector[i];
    int j = i;
    info_.set_value(1, i);
    while ((j >= delta ) && (auxiliar < vector[j - delta])) {
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