#ifndef VIEWER_H
#define VIEWER_H

#include "SortingVector.h"
#include "Sorts.h"
#include "Debug.h"

class Viewer {

public:

  Viewer(int size, bool info, int sort);
  ~Viewer();

  bool is_done() const;
  std::string name() const;
  std::string info() const;
  void set_sort(int index);

  bool sort(sf::RenderWindow& window);
  void shuffle(sf::RenderWindow& window);
  void check(sf::RenderWindow& window);

  void clear();

  void render(sf::RenderWindow& window);

private:  

  Debug* debug_;
  SortingVector<int> vector_;
  SortFunct<int>* sort_;
  bool done_;

};

#endif