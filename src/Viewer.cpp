#include "Viewer.h"

Viewer::Viewer(int size, bool info, int sort) {
  vector_ = SortingVector<int>{size};
  switch(sort) {
    case 0:
      sort_ = new SelectSort<int>();
      break;
    
    case 1:
      sort_ = new InsertSort<int>();
      break;
    
    case 2:
      sort_ = new BubbleSort<int>();
      break;

    case 3:
      sort_ = new ShakeSort<int>();
      break;

    case 4:   
      sort_ = new QuickSort<int>();
      break;

    case 5:
      sort_ = new MergeSort<int>();
      break;
      
    case 6:
      sort_ = new ShellSort<int>();
      break;

    case 7:
      sort_ = new RadixSort<int>();
      break;
      
    default:
      sort_ = new SelectSort<int>();
  }
}

Viewer::~Viewer() {
  if (debug_) { delete debug_; }
  if (sort_)  { delete sort_;  }
}

bool Viewer::is_done() const {
  return done_;
}

std::string Viewer::name() const {
  if (sort_) {
    return sort_ -> name();
  }
  return "---------";
}

std::string Viewer::info() const {
  if (sort_) {
    return sort_ -> info();
  }
  return "No Info";
}

bool Viewer::sort(sf::RenderWindow& window) {
  if (sort_) {
    done_ = sort_ -> sort(vector_, window);
    return done_;
  }
  return false;
}

void Viewer::shuffle(sf::RenderWindow& window) {
  vector_.shuffle(window);
}

void Viewer::check(sf::RenderWindow& window) {
  vector_.check(window);
}


void Viewer::render(sf::RenderWindow& window) {
  vector_.render(window);
}