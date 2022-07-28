#include "Viewer.h"

/***************************************************************  Constructores y Destructor  ***************************************************************/
Viewer::Viewer(int size) {
  vector_ = SortingVector<int>{size};
  status_ = std::make_unique<viewer_status>();
  sort_ = nullptr;
  debug_ = new Debug();
  std::vector<std::string> texts{"SelecSort", "InsertSort", "BubbleSort", "ShakeSort", 
                                 "QuickSort", "MergeSort",  "ShellSort",  "RadixSort", 
                                 "Shuffle",   "Check",      "Pause",      "Abort"     };
  toolbar_.resize(12);
  for (unsigned int i{0}; i < toolbar_.size(); i++) {
    toolbar_[i] = Button{{(1 + (float)i) + (85 * (float)i), 22}, texts[i]};
  }
}

Viewer::~Viewer() {
  if (debug_) { delete debug_; }
  if (sort_)  { delete sort_;  }
  toolbar_.clear();
}

/***************************************************************  Getters y Setters  ***************************************************************/
void Viewer::reset_counters() {
  vector_.reset_counters();
}

void Viewer::clear() {
  vector_.bleach();
}

/***************************************************************  Metodos  ***************************************************************/
void Viewer::sort() {
  if (status_ -> PAUSED || status_ -> QUIT) { return; }
  if (sort_) {
    status_ -> sorting();
    sort_ -> sort(vector_, status_);
  }
  status_ -> WORKING = false;
}

void Viewer::shuffle() {
  if (status_ -> PAUSED || status_ -> QUIT) { return; }
  status_ -> shuffling();
  vector_.shuffle(status_);
  status_ -> WORKING = false;
  status_ -> SHUFFLING = false;
}

void Viewer::check() {
  if (status_ -> PAUSED || status_ -> QUIT) { return; }
  if (vector_.check(status_)) {
    status_ -> checked();
  }
  status_ -> WORKING = false;
}

/***************************************************************  Metodos del Hilo  ***************************************************************/
void Viewer::thread_start() {
  if (status_ -> WORKING || status_ -> PAUSED) { return; } 
  if (sorting_thread.joinable()) { sorting_thread.join(); }
  sorting_thread = std::thread(&Viewer::thread_work, this);
  status_ -> WORKING = true;
}

void Viewer::thread_abort() {
  status_ -> QUIT = true;
  sorting_thread.join();
  Viewer::clear();
  Viewer::reset_counters();
  status_ -> QUIT = false;
}

void Viewer::thread_work() {
  Viewer::clear();
  Viewer::reset_counters();
  switch (state_){
    case -1:
      Viewer::shuffle();
      break;
    
    case 0:
      Viewer::check();
      break;

    case 1:
      Viewer::sort();
      Viewer::check();
      break;
  }
}

/***************************************************************  Botones  ***************************************************************/
void Viewer::is_over(sf::RenderWindow& window) {
  for (unsigned int i{0}; i < toolbar_.size(); i++) {
    toolbar_[i].is_over(window);
  }
}

int Viewer::is_pressed(sf::RenderWindow& window) {
  for (unsigned int i{0}; i < toolbar_.size(); i++) {
    if (toolbar_[i].is_over(window)) { 
      return i;
    }
  }
  return -1;   
}
void Viewer::action(int index) {
  if (index < 0 || index > 11) { return; }
  switch (index) {
    case 8:
      state_ = -1;
      break;

    case 9:
      status_ -> CHECKING = true;
      state_ = 0;
      break;

    case 10:
      status_ -> PAUSED = !status_ -> PAUSED;
      return;

    case 11:
      thread_abort();
      return;

    default:
      if (status_ -> WORKING) { break; }
      if (sort_) { 
        delete sort_;
        sort_ = nullptr;
      }
      sort_ = set_sort<int>(index);
      state_ = 1;
  }
  thread_start();
}

/*************************************************************** Renders y Updates  ***************************************************************/
void Viewer::render(sf::RenderWindow& window) {
  Info<int> info{"Not selected", 0};
  if (sort_) {
    info = sort_ -> info();
  }
  else if (status_ -> CHECKING) {
    info = Info<int>{"Checking", 0};
  }
  else if (status_ -> SHUFFLING) {
    info = Info<int>{"Shuffling", 0};
  }
  debug_ -> print(vector_.comp(), vector_.access(), info, status_);
  debug_ -> render(window);
  for (unsigned int i{0}; i < toolbar_.size(); i++) {
    toolbar_[i].render(window);
  }
  vector_.render(window);
}