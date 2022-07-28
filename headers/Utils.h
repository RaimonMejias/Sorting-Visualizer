/*!
 * @file Utils.h
 * @brief Contiene la declaración y la implementación de funciones utiles
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef UTILS_H
#define UTILS_H

#include "Sorts.h"

template<class Temp>
SortFunct<Temp>* set_sort(int sort) {

  switch(sort) {
    case 0:
      return new SelectSort<Temp>();
    case 1:
      return new InsertSort<Temp>();
    case 2:
      return new BubbleSort<Temp>();
    case 3:
      return new ShakeSort<Temp>();
    case 4:
      return new QuickSort<Temp>();
    case 5:
      return new MergeSort<Temp>();   
    case 6:
      return new ShellSort<Temp>();
    case 7:
      return new RadixSort<Temp>();
    default:
      return nullptr;
  } 
}

#endif