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
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(std::vector<Item<Temp> >& vector, int& access) override;

private:

  unsigned int i_;
  unsigned int j_;
  int state_;

  Item<Temp> key_;

};

template<class Temp>
InsertSort<Temp>::InsertSort() {
  i_ = 1;
  j_ = i_ + 1;
  state_ = 0;
}

template<class Temp>
InsertSort<Temp>::~InsertSort() {

}

template<class Temp>
std::string InsertSort<Temp>::name() const {
  return "InsertSort";
}

template<class Temp>
std::string InsertSort<Temp>::info() const {
  std::stringstream ss;
  ss << "I = " << i_ << " J = " << j_ << std::endl; 
  return ss.str();
}

template <class Temp>
bool InsertSort<Temp>::sort(std::vector<Item<Temp> >& vector, int& access) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  if (i_ == vector.size()) { return true; }
  switch(state_) {
    case 0:
      key_ = vector[i_];
      access++;
      j_ = i_;
      vector[j_].set_color(sf::Color::Red);
      state_ = 1;
      return false;
      break;

    case 1:
      vector[j_].reset_color();
      if (key_ <= vector[j_ - 1] && j_ > 0) {
        vector[j_] = vector[j_ - 1];
        j_--;
        access += 4;
        vector[j_].set_color(sf::Color::Red);
      } else {
        access += 2;
        state_ = 2;
      }
      return false;
      break;

    case 2:
        vector[j_].reset_color();
        vector[j_] = key_; 
        access++;
        i_++;
        state_ = 0;
        return false;
        break;

    default:
      break;
  }
  return false;
}

#endif