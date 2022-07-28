/*!
 * @file Viewer.h
 * @brief Contiene la declaración de la clase Viewer.h 
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef VIEWER_H
#define VIEWER_H

#include <thread>

#include "SortingVector.h"
#include "Sorts.h"
#include "Debug.h"
#include "Utils.h"
#include "Status.h"
#include "Button.h"

class Viewer {

public:

  //Constructores y Destructor
  Viewer(int size);
  ~Viewer();

  //Getters y Setters 
  
  void reset_counters();
  void clear();

  //Metodos
  void sort();
  void shuffle();
  void check();
  
  //Metodos del Hilo
  void thread_start();
  void thread_abort();
  void thread_work();

  //Botones
  void is_over(sf::RenderWindow& window);
  int is_pressed(sf::RenderWindow& window);
  void action(int index);

  //Render y Updates
  void render(sf::RenderWindow& window);

private:  

  Debug* debug_;
  std::vector<Button> toolbar_;
  SortingVector<int> vector_;
  SortFunct<int>* sort_;

  std::unique_ptr<viewer_status> status_;
  std::thread sorting_thread;
  int state_;

};

#endif