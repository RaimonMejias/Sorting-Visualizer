/*!
 * @file Item.h
 * @brief Clase plantilla para la creación de elementos para el SortingVector
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

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
  void reset_counter();
  void color(const sf::Color& color);

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
  sf::Vector2f pos_;

  Temp item_;
  int comp_;

};

/***************************************************************  Constructores y Destructor  ***************************************************************/
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

/***************************************************************  Getters y Setters  ***************************************************************/
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
void Item<Temp>::reset_counter() {
  comp_ = 0;
}

template<class Temp>
void Item<Temp>::color(const sf::Color& color) {
  rect_.setFillColor(color);
}

/***************************************************************  Renders y Updates  ***************************************************************/
template<class Temp>
void Item<Temp>::render(sf::RenderWindow& window, sf::Vector2f pos) {
  rect_.setOutlineColor(sf::Color::Black);
  rect_.setOutlineThickness(0.5);
  rect_.setSize(sf::Vector2f{10, (-1.0f * item_)});
  rect_.setPosition(pos);
  window.draw(rect_);
}

/***************************************************************  Operadores  ***************************************************************/
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