#ifndef UTILS_H
#define UTILS_H

#include "Sorts.h"

template<class Temp>
SortFunct<Temp>* set_sort(int sort) {

  SortFunct<Temp>* funct;

  switch(sort) {
    case 0:
      funct = new SelectSort<Temp>();
      break;
    case 1:
      funct = new InsertSort<Temp>();
      break;
    case 2:
      funct = new BubbleSort<Temp>();
      break;
    case 3:
      funct = new ShakeSort<Temp>();
      break;
    case 4:   
      funct = new QuickSort<Temp>();
      break;
    case 5:
      funct = new MergeSort<Temp>();   
      break;
    case 6:
      funct = new ShellSort<Temp>();
      break;
    case 7:
      funct = new RadixSort<Temp>();
      break;
    default:
      funct = new SelectSort<Temp>();
  } 
  return funct;   
}

#endif