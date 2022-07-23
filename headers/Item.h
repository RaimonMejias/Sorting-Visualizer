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
  int comp() const;

  void set_color(const sf::Color& color);
  void reset_color();
  void debug();

  //Render y Updates
  void render(sf::RenderWindow& window, sf::Vector2f pos);

  //Operadores
  void operator= (const Item<Temp>& item);
  bool operator> (Item<Temp>& item); 
  bool operator< (Item<Temp>& item); 
  bool operator>=(Item<Temp>& item); 
  bool operator<=(Item<Temp>& item); 
  bool operator==(Item<Temp>& item); 
  bool operator!=(Item<Temp>& item); 

private:

  sf::RectangleShape rect_;
  Temp item_;
  sf::Vector2f pos_;

  int comp_;

};

template<class Temp>
Item<Temp>::Item() {
  comp_ = 0;
}

template<class Temp>
Item<Temp>::Item(const Temp& item, sf::Vector2f pos) {
  item_ = item;
  comp_ = 0;
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
int Item<Temp>::comp() const {
  return comp_;
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
void Item<Temp>::render(sf::RenderWindow& window, sf::Vector2f pos) {
  rect_.setOutlineColor(sf::Color::Black);
  rect_.setOutlineThickness(0.5);
  rect_.setSize(sf::Vector2f{10, (-1.0f * item_)});
  rect_.setPosition(pos);
  window.draw(rect_);
}

//Operadores 
template<class Temp>
void Item<Temp>::operator=(const Item<Temp>& item) {
  item_ = item.item();
  comp_ = item.comp();
}

template<class Temp>
bool Item<Temp>::operator>(Item<Temp>& item)  {
  comp_++;
  if (this -> item() > item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator<(Item<Temp>& item)  {
  comp_++;
  if (this -> item() < item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator>=(Item<Temp>& item)  {
  comp_++;
  if (this -> item() >= item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator<=(Item<Temp>& item)  {
  comp_++;
  if (this -> item() <= item.item()) {
    return true;
  }
  return false;
}

template<class Temp>
bool Item<Temp>::operator==(Item<Temp>& item)  {
  comp_++;
  if (this -> item() == item.item()) {
    return true;
  }
  return false;

}

template<class Temp>
bool Item<Temp>::operator!=(Item<Temp>& item)  {
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