/*!
 * @file Status.h
 * @brief Recopilación de Flags necesarias para mostrar correctamente la información del programa
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef STATUS_H
#define STATUS_H

#include <atomic> 

struct viewer_status {

  std::atomic<bool> WORKING;   //Flag para indicar que el hilo esta en funcionamieto;
  std::atomic<bool> QUIT;      //Flag para indicarle al hilo que debe parar;
  std::atomic<bool> SORTING;   //Flag para indicar si esta ordenando o desordenando;
  std::atomic<bool> CHECKING;  //Flag para indicar si se esta comprobando;
  std::atomic<bool> SHUFFLING; //Flag para indicar si se esta mezclando;
  std::atomic<bool> SORTED;    //Flag para indicar que la lista esta ordenada;
  std::atomic<bool> PAUSED;    //Flag para indicar que esta en pausa el programa;

  viewer_status(): WORKING{false}, QUIT{false}, SORTING{false}, CHECKING{false}, SHUFFLING(false), SORTED{true}, PAUSED{false} {} 
  void shuffling();
  void sorting();
  void checked();
  void sorted();

  bool checkable();
};

#endif