#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortFunct.h"

template<class Temp>
class BubbleSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  BubbleSort();
  ~BubbleSort();

  //Getters y Setters
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(std::vector<Item<Temp> >& vector, int& access) override;

private:

  unsigned int i_;
  unsigned int j_;
  bool ini_;

};


template<class Temp>
BubbleSort<Temp>::BubbleSort() {
  i_ = 1;
  j_ = 0;
  ini_ = 0;
}

template<class Temp>
BubbleSort<Temp>::~BubbleSort() {

}

template<class Temp>
std::string BubbleSort<Temp>::name() const {
  return "BubbleSort";
}

template<class Temp>
std::string BubbleSort<Temp>::info() const {
  std::stringstream ss;
  ss << "I = " << i_ << std::endl; 
  return ss.str();
}

template <class Temp>
bool BubbleSort<Temp>::sort(std::vector<Item<Temp> >& vector, int& access) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 

  if (i_ == vector.size()) { return true; }

  if (!ini_) {
    j_ = vector.size() - 1;
    ini_ = true;
  }
  vector[j_].reset_color();
  if (vector[j_] <= vector[j_ - 1]) {
    swap(vector[j_], vector[j_ - 1]);
    access += 3;
  }
  access += 2; 
  if (j_ > i_) {
    j_--;
    vector[j_].set_color(sf::Color::Red);
    return false;
  }
  if (i_ < vector.size()) {
    i_++;
    j_ = vector.size() - 1;
    return false;
  }
  return true;
}

#endif