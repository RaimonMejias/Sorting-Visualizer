#ifndef SORTINGVECTOR_H
#define SORTINGVECTOR_H

#include <random>
#include <time.h>

#include <vector>
#include <iostream>

#include "Item.h"

template<class Temp>
class SortingVector {

public:

  //Constructores y Destructor
  SortingVector(int size = 0);
  ~SortingVector();

  //Getters y Setters
  int size() const;
  int comp() const;
  int access() const;

  //Metodos
  void shuffle(sf::RenderWindow& window);
  bool check(sf::RenderWindow& window);
  void swap(Item<Temp>& item1, Item<Temp>& item2);
  void color(int index, const sf::Color& colour);
  void clear(int index);

  //Render y Update
  void render(sf::RenderWindow& window);

  //Operadores
  Item<Temp>& operator[](int i);
  const Item<Temp>& operator[](int i) const;

private:

  int access_;
  std::vector<Item<Temp> > vector_;

};

template<class Temp>
SortingVector<Temp>::SortingVector(int size) {
  vector_.resize(size);
  for (unsigned int i{0}; i < vector_.size(); i++) {
    vector_[i] = Item<Temp>{((int)i + 1) * 5, sf::Vector2f{10.0f * i, 720}};
  }
}

template<class Temp>
SortingVector<Temp>::~SortingVector() {
  vector_.clear();
}

template<class Temp>
int SortingVector<Temp>::size() const {
  return vector_.size();
}

template<class Temp>
int SortingVector<Temp>::comp() const {
  int result{0};
  for (int i{0}; i < size(); i++) {
    result += vector_[i].comp();
  }
  return result;
}

template<class Temp>
int SortingVector<Temp>::access() const {
  return access_;
}

template<class Temp>
void SortingVector<Temp>::shuffle(sf::RenderWindow& window) {
  srand(time(NULL));
  for (int i{0}; i < size() * 2; i++) {
    window.clear();
    swap(vector_[rand() % (vector_.size() - 1)], vector_[rand() % (vector_.size() - 1)]);
    render(window);
    window.display();
  }
}

template<class Temp>
bool SortingVector<Temp>::check(sf::RenderWindow& window) {
  for(int i{0}; i < size(); i++) {  
    window.clear();
    if (this -> operator[](i) <= this -> operator[](i + 1)) {
      color(i, sf::Color::Green);
      color(i + 1, sf::Color::Red);
    }
    if (i == size() - 1) {
      color(i, sf::Color::Green);
    }   
    render(window);
    window.display();
  }
  return true;
}

template<class Temp>
void SortingVector<Temp>::swap(Item<Temp>& item1, Item<Temp>& item2) {
  Item<Temp> aux = item1;
  item1 = item2;
  item2 = aux;
}

template<class Temp>
void SortingVector<Temp>::color(int index, const sf::Color& colour) {
  if (index < 0 || index >= size()) { return; }
  vector_[index].color(colour);
}

template<class Temp>
void SortingVector<Temp>::clear(int index) {
  if (index < 0 || index >= size()) { return; }
  vector_[index].color(sf::Color::White);
}


template<class Temp>
void SortingVector<Temp>::render(sf::RenderWindow& window) {
  for(unsigned int i{0}; i < vector_.size(); i++) {
    vector_[i].render(window, sf::Vector2f{10.0f * i, 720});
  }
}

template<class Temp>
Item<Temp>& SortingVector<Temp>::operator[](int i) {
  if (i < 0 || i >= size()) { return vector_[0]; }
  access_++;
  return vector_[i];
}

template<class Temp>
const Item<Temp>& SortingVector<Temp>::operator[](int i) const {
  if (i < 0 || i >= size()) { throw vector_[0]; }
  return vector_[i];
}
#endif