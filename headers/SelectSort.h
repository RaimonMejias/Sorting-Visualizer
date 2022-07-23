#ifndef SELECTSORT_H
#define SELECTSORT_H

#include "SortFunct.h"

template <class Temp>
class SelectSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  SelectSort();
  ~SelectSort();

  //Getters y Setters
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(std::vector<Item<Temp> >& vector, int& access) override;

private:

  unsigned int i_;
  unsigned int index_;
  unsigned int j_;

  Item<Temp> min_value_;

  int state_;

};

template<class Temp>
SelectSort<Temp>::SelectSort() {
  i_ = 0;
  index_ = 0;
  j_ = i_ + 1;
  state_ = 0;
}

template<class Temp>
SelectSort<Temp>::~SelectSort() {

}

template<class Temp>
std::string SelectSort<Temp>::name() const {
  return "SelectSort";
}

template<class Temp>
std::string SelectSort<Temp>::info() const {
  std::stringstream ss;
  ss << "I = " << i_ << " J = " << index_ << " MINVAL = " << min_value_.item() << std::endl; 
  return ss.str();
}

template <class Temp>
bool SelectSort<Temp>::sort(std::vector<Item<Temp> >& vector, int& access) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 
  if (i_ == vector.size() - 1) {
    return true;
  }
  vector[j_].reset_color();
  switch (state_) {
    case 0:
      index_ = i_;
      j_ = i_ + 1; 
      min_value_ = vector[index_];
      access++;
      vector[j_].set_color(sf::Color::Red);
      state_ = 1;
      return false;
      break;

    case 1:
      if (vector[j_] <= min_value_) {
        vector[index_].reset_color();
        index_ = j_;
        min_value_ = vector[index_];
        access++;
      }
      access++;
      if (j_ < vector.size() - 1) { 
        j_++; 
        vector[j_].set_color(sf::Color::Red);
      } else {
        state_ = 2;
      }
      return false;
      break;

    case 2: 
      vector[index_].reset_color();
      vector[index_] = vector[i_];
      vector[i_] = min_value_;
      access += 4;
      i_++;
      state_ = 0;
      return false;
      break;
  }
  return false;
}

/* REVISAR ESTO MAÑANA 
template <class Temp>
bool SelectSort<Temp>::sort(std::vector<Item<Temp> >& vector, int& access, sf::RenderWindow& window) {
  for (unsigned int i{0}; i < vector.size(); i++) {
    window.clear();
    unsigned int min = i;
    for (unsigned int j{i + 1}; j < vector.size(); j++) {
      vector[j-1].reset_color();
      if (vector[j] <= vector[min]) { min = j; }
      vector[j].set_color(sf::Color::Red);
      // IMPRIMIR COSA
      window.display();
    } 
    swap(vector[min], vector[i]);

  }
}
*/

#endif