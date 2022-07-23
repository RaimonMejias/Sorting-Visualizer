#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "Debug.h"

template<class Temp>
class Item {

public:

  //Constructores y Destructor
  Item();
  Item(const Temp& item, sf::Vector2f pos);
  ~Item();

  //Getters y Setters
  const Temp& item() const;
  Temp item();
  int cmp() const;

  sf::Vector2f size() const;
  sf::Vector2f pos() const;
  void set_color(const sf::Color& color);
  void reset_color();
  void debug();

  //Render y Updates
  void render(sf::RenderWindow& window);
  void update();

  //Operadores
  void operator=(Item<Temp>& item);
  bool operator> (const  Item<Temp>& item) const;
  bool operator< (const Item<Temp>& item) const;
  bool operator>=(const Item<Temp>& item) const;
  bool operator<=(const Item<Temp>& item) const;
  bool operator==(const Item<Temp>& item) const;
  bool operator!=(const Item<Temp>& item) const;

private:

  sf::RectangleShape rect_;
  Temp item_;
  sf::Vector2f size_;
  sf::Vector2f pos_;

  int comp_;

};

template<class Temp>
Item<Temp>::Item() {
  size_ = {0, 0};
  pos_ = {0, 0};
  comp_ = 0;
  update();
}

template<class Temp>
Item<Temp>::Item(const Temp& item, sf::Vector2f pos) {
  item_ = item;
  pos_ = pos;
  comp_ = 0;
  size_ = sf::Vector2f{10, (-1.0f * item_)};
  update();
}

template<class Temp>
Item<Temp>::~Item() {
}

template<class Temp>
const Temp& Item<Temp>::item() const {
  return item_;
}

template<class Temp>
Temp Item<Temp>::item() {
  return item_;
}

template<class Temp>
int Item<Temp>::cmp() const {
  return comp_;
}

template<class Temp>
sf::Vector2f Item<Temp>::size() const {
  return size_;
}

template<class Temp>
sf::Vector2f Item<Temp>::pos() const {
  return pos_;
}

template<class Temp>
void Item<Temp>::set_color(const sf::Color& color) {
  rect_.setFillColor(color);
}

template<class Temp>
void Item<Temp>::reset_color() {
  rect_.setFillColor(sf::Color::White);
}

template<class Temp>
void Item<Temp>::render(sf::RenderWindow& window) {
  window.draw(rect_);
}

template<class Temp>
void Item<Temp>::update() {
  rect_.setOutlineColor(sf::Color::Black);
  rect_.setOutlineThickness(0.5);
  rect_.setSize(size_);
  rect_.setPosition(pos_);
}
/*
template<class Temp>
void Item<Temp>::update(sf::Vector2f pos) {
  item_ = item_;
  size_ = sf::Vector2f{10, (-1.0f * item_)};
  pos_ = pos;
  rect_.setSize(size_);
  rect_.setPosition(pos_);
}
*/

//Operadores 
template<class Temp>
void Item<Temp>::operator=(Item<Temp>& item) {
  item_ = item.item();
  size_ = item.size();
  pos_ = item.pos();
  comp_ = item.cmp();
  update();
}

template<class Temp>
bool Item<Temp>::operator>(const Item<Temp>& item) const {
  comp_++;
  if (this -> item() > item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator<(const Item<Temp>& item) const {
  comp_++;
  if (this -> item() < item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator>=(const Item<Temp>& item) const {
  comp_++;
  if (this -> item() >= item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator<=(const Item<Temp>& item) const {
  comp_++;
  if (this -> item() <= item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator==(const Item<Temp>& item) const {
  comp_++;
  if (this -> item() == item.item()) {
    return true;
  }
  return false;

}

template<class Temp>
bool Item<Temp>::operator!=(const Item<Temp>& item) const {
  comp_++;
  if (this -> item() > item.item()) {
    return true;
  }
  return false;
  
}

template<class Temp>
std::ostream& operator<<(std::ostream& out, const Item<Temp>& item) {
  out << item.item();
  return out;
}

#endif