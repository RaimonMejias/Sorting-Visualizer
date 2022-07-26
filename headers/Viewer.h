#ifndef VIEWER_H
#define VIEWER_H

#include <thread>
#include <atomic> 

#include "SortingVector.h"
#include "Sorts.h"
#include "Debug.h"
#include "Utils.h"

struct viewer_status {

  viewer_status(): QUIT{false}, SORTING{false}, CHECKING{false}, SORTED{true}, PAUSED{false} {} 
  std::atomic<bool> QUIT;     //Flag para indicarle al hilo que debe parar;
  std::atomic<bool> SORTING;  //Flag para indicar si esta ordenando o desordenando;
  std::atomic<bool> CHECKING; //Flag para indicar si se esta comprobando;
  std::atomic<bool> SORTED;   //Flag para indicar que la lista esta ordenada;
  std::atomic<bool> PAUSED;   //Flag para indicar que esta en pausa el programa;

  void shuffling();
  void sorting();
  bool checkable();
  void checked();

};

class Viewer {

public:

  //Constructores y Destructor
  Viewer(int size, int sort);
  ~Viewer();

  //Getters y Setters 
  bool is_done() const;
  void reset_counters();

  //Metodos del Hilo
  void start();
  void stop();
  void work();

  //Metodos
  void sort();
  void shuffle();
  void check();
  void clear();

  //Render y Updates
  void render(sf::RenderWindow& window);

private:  

  Debug* debug_;
  SortingVector<int> vector_;
  SortFunct<int>* sort_;

  std::unique_ptr<viewer_status> status_;
  std::thread sorting_thread;

};

#endif