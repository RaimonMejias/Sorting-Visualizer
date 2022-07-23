#ifndef SORTINGVECTOR_H
#define SORTINGVECTOR_H

#include <random>
#include <time.h>

#include <vector>
#include <iostream>

#include "Item.h"
#include "SortFunct.h"
#include "Debug.h"
#include "Utils.h"

template<class Temp>
class SortingVector {

public:

  //Constructores y Destructor
  SortingVector(int size, SortFunct<Temp>* funct = nullptr, Debug* debug = nullptr);
  ~SortingVector();

  //Getters y Setters
  bool is_done() const;
  std::string name() const;
  std::string info() const;

  //Metodos
  void unsort();
  bool sort();
  bool check();

  //Render y Update
  void render(sf::RenderWindow& window);
  void update();

  //Operadores
  Item<Temp>& operator[](int i);

private:

  int access_;
  Debug* debug_;
  SortFunct<Temp>* sort_;
  std::vector<Item<Temp> > vector_;
  unsigned int i_;
  bool done_;
  
};

template<class Temp>
SortingVector<Temp>::SortingVector(int size, SortFunct<Temp>* funct, Debug* debug) {
  access_ = 0;
  i_ = 0;
  done_ = false;
  sort_ = funct;
  debug_ = debug;
  vector_.resize(size);
  for (unsigned int i{0}; i < vector_.size(); i++) {
    vector_[i] = Item<Temp>{((int)i + 1) * 5, sf::Vector2f{10.0f * i, 720}};
  }
}

template<class Temp>
SortingVector<Temp>::~SortingVector() {
  vector_.clear();
  if (sort_)  { delete sort_; }
  if (debug_) { delete debug_; }
}

template<class Temp>
bool SortingVector<Temp>::is_done() const {
  return done_;
}

template<class Temp>
std::string SortingVector<Temp>::name() const {
  if (sort_) {
    return sort_ -> name();
  }
  return "---------";
}

template<class Temp>
std::string SortingVector<Temp>::info() const {
  if (sort_) {
    return sort_ -> info();
  }
  return "No Info";
}

template<class Temp>
void SortingVector<Temp>::unsort() {
  srand(time(NULL));
  int number1{0};
  int number2{0}; 
  for (unsigned int i{0}; i < vector_.size(); i++) {
    while (number1 == number2) {
      number1 = rand() % vector_.size() - 1;
      number2 = rand() % vector_.size() - 1;
    }
    swap(vector_[rand() % (vector_.size() - 1)], vector_[rand() % (vector_.size() - 1)]);
  }
}

template<class Temp>
bool SortingVector<Temp>::check() {
  if (i_ == vector_.size()) {
    vector_[i_ - 1].set_color(sf::Color::Green);
    return true;
  }
  vector_[i_].reset_color();
  if (i_ < vector_.size()) {
    if (vector_[i_] <= vector_[i_ + 1]) {
      vector_[i_].set_color(sf::Color::Green);
      vector_[i_ + 1].set_color(sf::Color::Red);
    }
    i_++;
  }
  return false;
}

template<class Temp>
bool SortingVector<Temp>::sort() {
  if (sort_) {
    return sort_ -> sort(vector_, access_);
  }
  return false;
}

template<class Temp>
void SortingVector<Temp>::render(sf::RenderWindow& window) {
  int comp = 0;
  for(unsigned int i{0}; i < vector_.size(); i++) {
    vector_[i].render(window);
    comp += vector_[i].cmp();
  }
  if (debug_) {
    std::stringstream ss;
    ss << name() << " | Iteracion = " << i_ <<  " | Accesos a memoria = " << access_ << " | Comparaciones = " << comp << std::endl; 
    ss << info();
    debug_ -> string(ss.str());
    debug_ -> render(window);
  }
}

template<class Temp>
void SortingVector<Temp>::update() {
  if (sort() && !done_) {
    done_ = check();
  }
  for(unsigned int i{0}; i < vector_.size(); i++) {
    vector_[i].update(sf::Vector2f{10.0f * i, 720});
  }
}

#endif


/*
  sf::Font font_;
  sf::Text text_;

  if (!font_.loadFromFile("C:\\WINDOWS\\FONTS\\CALIBRIL.TTF")) { }
  text_.setFont(font_);

  std::stringstream ss_;
  sf::Vector2f v = vector_[index_].pos();
  ss_ << "I = " << i_ << std::endl;
  ss_ << "INDEX = " << index_ << " INDEX VALUE = " << vector_[index_].item() << " POSITION = [" << v.x << ","  << v.y << "]" << std::endl;
  v = vector_[j_].pos();
  ss_ << "j = " << j_ << " j VALUE = " << vector_[j_].item() << " POSITION = [" << v.x << ","  << v.y << "]" << std::endl;
  ss_ << "INIT = " << ((init_)? "[TRUE]" : "[FALSE]") << std::endl;
  ss_ << "IS CORRECT = " << ((is_correct_)? "[TRUE]" : "[FALSE]") << std::endl;
  for (unsigned int i{0}; i < vector_.size(); i++) {
    ss_ << vector_[i].item() << " ";
  }
  ss_ << std::endl;
  text_.setString(ss_.str());
  text_.setFillColor(sf::Color::Red);
  text_.setStyle(sf::Text::Bold);
  text_.setCharacterSize(10);
  text_.setPosition(0, 0);
  window.draw(text_);
*/