#include "Viewer.h"

Viewer::Viewer(int size, int sort) {
  vector_ = SortingVector<int>{size};
  status_ = std::make_unique<viewer_status>();
  sort_ = set_sort<int>(sort);
  debug_ = new Debug();
}

Viewer::~Viewer() {
  if (debug_) { delete debug_; }
  if (sort_)  { delete sort_;  }
}

bool Viewer::is_done() const {
  return status_ -> SORTED;
}

void Viewer::start() {
  if (sorting_thread.joinable()) { sorting_thread.join(); }
  sorting_thread = std::thread(&Viewer::work, this);
}

// stop
void Viewer::stop() {
  status_ -> QUIT = true;
  sorting_thread.detach();
}

// select algh

// start shuffle

// start check

void Viewer::work() {
  for (int i{0}; i < 8; i++) {
    Viewer::clear();
    Viewer::reset_counters();
    sort_ = set_sort<int>(i);
    Viewer::shuffle();
    Viewer::sort();
    Viewer::check();
  }
}

void Viewer::sort() {
  if (sort_) {
    sort_ -> sort(vector_);
    status_ -> sorting();
  }
  status_ -> SORTING = false;
  status_ -> SORTED = true;
  status_ -> CHECKING = false;
}

void Viewer::shuffle() {
  if (status_ -> SORTED) {
    vector_.shuffle();
    status_ -> shuffling();
  }
}

void Viewer::check() {
  if (status_ -> checkable()) {
    vector_.check();
    status_ -> checked();
  }
}

void Viewer::clear() {
  vector_.bleach();
}

void Viewer::reset_counters() {
  vector_.reset_counters();
}

void Viewer::render(sf::RenderWindow& window) {
  Info<int> info{"Not Defined", 0};
  if (sort_) {
    info = sort_ -> info();
  }
  if (debug_) {
  
    debug_ -> print(vector_.comp(), vector_.access(), info, status_);
    debug_ -> render(window);
  }
  vector_.render(window);
}

////////////////////////////////////////////////////////////////////////////////////////
//                                 Viewer_status                                      //
////////////////////////////////////////////////////////////////////////////////////////

void viewer_status::shuffling() {
  SORTING = false;
  SORTED = false;
  CHECKING = false;
}

void viewer_status::sorting() {
  SORTING = true;
  SORTED = false;
  CHECKING = false;
}

bool viewer_status::checkable() {
  return (!SORTING && SORTED && !CHECKING);
}

void viewer_status::checked() {
  SORTING = false;
  SORTED = true;
  CHECKING = false;
}
