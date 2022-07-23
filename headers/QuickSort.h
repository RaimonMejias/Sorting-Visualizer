#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stack>
#include "SortFunct.h"

template<class Temp>
class QuickSort : public SortFunct<Temp> {

public:

  //Constructores y Destructor
  QuickSort();
  ~QuickSort();

  //Getters y Setters
  std::string name() const override;
  std::string info() const override;

  //Metodos
  bool sort(std::vector<Item<Temp> >& vector, int& access) override;
  //bool quick(std::vector<Item<Temp> >& vector, int ini, int fin, int& access);

private:

  std::stack<sf::Vector2u> stk_;
  unsigned int i_;
  unsigned int j_;
  unsigned int ini_;
  unsigned int fin_;
  unsigned int piv_;
  int state_;

  Item<Temp> pivot_;

};


template<class Temp>
QuickSort<Temp>::QuickSort() {
  i_ = 0;
  j_ = 0;
  ini_ = 0;
  fin_ = 0;
  piv_ = 0;
  state_ = -2;
}

template<class Temp>
QuickSort<Temp>::~QuickSort() {

}

template<class Temp>
std::string QuickSort<Temp>::name() const {
  return "QuickSort";
}

template<class Temp>
std::string QuickSort<Temp>::info() const {
  std::stringstream ss;
  ss << "Ini = " << ini_ << " Fin = " << fin_ << " Pivot = " << pivot_.item() <<  std::endl;
  ss << "I = " << i_ << " J = " << j_ << " Stack size = " << stk_.size() <<  std::endl;  
  return ss.str();
}

template <class Temp>
bool QuickSort<Temp>::sort(std::vector<Item<Temp> >& vector, int& access) { // TODO ESTO POR NO PODER HACER UN BUCLE FOR 

  if (state_ == 4) { return true; }
  vector[i_].reset_color();
  vector[j_].reset_color();
  switch (state_) {

    case -2:
      ini_ = 0;
      fin_ = vector.size() - 1;
      i_ = ini_;
      j_ = fin_;
      state_ = -1;
      piv_ = (i_ + j_) / 2;
      vector[i_].set_color(sf::Color::Red);
      vector[j_].set_color(sf::Color::Blue);     
      pivot_ = vector[piv_];
      vector[piv_].set_color(sf::Color::Magenta);
      stk_.push(sf::Vector2u{ini_, fin_});
      break;

    case -1:
      if (stk_.size() > 0) {
        ini_ = stk_.top().x;
        fin_ = stk_.top().y;
        piv_ = (ini_ + fin_) / 2;
        pivot_ = vector[piv_];
        vector[piv_].set_color(sf::Color::Magenta);
        i_ = ini_;
        j_ = fin_;
        vector[i_].set_color(sf::Color::Red);
        vector[j_].set_color(sf::Color::Blue);   
        stk_.pop();
        state_  = 0;
      } else {
        state_ = 4;
      }
      break;

    case 0:
      if (vector[i_] < pivot_) { 
        if (i_ != piv_) {
          vector[i_].set_color(sf::Color{254, 71, 71}); 
        } else {
          vector[i_].set_color(sf::Color{254, 71, 71} + sf::Color::Magenta); 
        }
        i_++; 
        if (i_ >= vector.size()) {
          i_--; 
          state_ = 1;
        }
        vector[i_].set_color(sf::Color::Red);
      } else {
        state_ = 1;
      }
      break;
    
    case 1: 
      if (vector[j_] > pivot_) { 
        if (j_ != piv_) {
          vector[j_].set_color(sf::Color{91, 91, 254});
        } else {
          vector[j_].set_color(sf::Color{91, 91, 254} + sf::Color::Magenta);
        }
        j_--;
        if (j_ < 0) {
          j_++;
          state_ = 2; 
        } 
        vector[j_].set_color(sf::Color::Blue);
      } else {
        state_ = 2;
      }
      break;  

    case 2:
      if (i_ <= j_) {
        swap(vector[i_], vector[j_]);
        vector[i_].set_color(sf::Color{254, 71, 71});
        vector[j_].set_color(sf::Color{91, 91, 254});
        i_++;
        if (i_ >= vector.size()) { i_--; }
        j_--;
        if (j_ < 0) { j_++; }
        state_ = 0;
      } else {
        state_ = 3;
      }
      break;

    case 3:
      for (unsigned int i{0}; i < vector.size(); i++) {
        vector[i].reset_color();
      }
      state_ = -1;
      if (ini_ < j_) {
        stk_.push(sf::Vector2u{j_, fin_});
      }
      if (i_ < fin_) {
        stk_.push(sf::Vector2u{ini_, i_});
      }
      break;

    default:
      break;
  }
  return false;
}


#endif