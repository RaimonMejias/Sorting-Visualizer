#ifndef SHAKESORT_H
#define SHAKESORT_H

#include "SortFunct.h"

template<class Temp>
class ShakeSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  ShakeSort();
  ~ShakeSort();

  //Getters y Setters 
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(std::vector<Item<Temp> >& vector, int& access) override;

private:

  unsigned int i_;
  unsigned int ini_;
  unsigned int fin_;
  unsigned int cam_;
  int state_;

  Item<Temp> key_;

};

template<class Temp>
ShakeSort<Temp>::ShakeSort() {
  i_ = 0;
  ini_ = 0;
  fin_ = 0; // ARREGLAR ESTO
  cam_ = 0;
  state_ = -1;
}

template<class Temp>
ShakeSort<Temp>::~ShakeSort() {

}

template<class Temp>
std::string ShakeSort<Temp>::name() const {
  return "ShakeSort";
}

template<class Temp>
std::string ShakeSort<Temp>::info() const {
  std::stringstream ss;
  ss << "Ini = " << ini_ << " Fin = " << fin_ << " Cam = " << cam_ << " S = " << ((state_)? " <- " : " -> ") << std::endl; 
  return ss.str();
}

template <class Temp>
bool ShakeSort<Temp>::sort(std::vector<Item<Temp> >& vector, int& access) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 

  if (state_ == 2) { return true;}
  vector[i_].reset_color();
  switch (state_) {
    case -1:
      ini_ = 1;
      i_ = ini_;
      fin_ = vector.size() -1;
      cam_ = vector.size();
      state_ = 0;
      break;

    case 0:
      if (vector[i_] <= vector[i_ - 1]) {
        swap(vector[i_], vector[i_ - 1]);
        cam_ = i_;
        access += 3;
      }
      access += 2;
      if (i_ < fin_) {
        i_++;
        vector[i_].set_color(sf::Color::Red);
      } else {
        fin_ = cam_ - 1;
        i_ = fin_;
        state_ = 1;
      }
      break;

    case 1:
      if (vector[i_] <= vector[i_ - 1]) {
        swap(vector[i_], vector[i_ - 1]);
        cam_ = i_;
        access += 3;
      }
       access += 2;
      if (i_ > ini_) {
        i_--  ;
        vector[i_].set_color(sf::Color::Red);
      } else {
        ini_ = cam_ + 1;
        i_ = ini_;
        state_ = 0;
      }
      break;

    default:
      break;  
  }

  if (ini_ >= fin_) { 
    state_ = 2;
    return true; 
  }
  return false;
}

#endif