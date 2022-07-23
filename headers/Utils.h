#ifndef UTILS_H
#define UTILS_H

#include "Item.h"

template<class Temp>
void swap(Item<Temp>& item1, Item<Temp>& item2) {
  Item<Temp> aux = item1;
  item1 = item2;
  item2 = aux;
}

#endif