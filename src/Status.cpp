#include "Status.h"

void viewer_status::shuffling() {
  SHUFFLING = true;
  SORTING = false;
  SORTED = false;
  CHECKING = false;
}

void viewer_status::sorting() {
  SHUFFLING = false;
  SORTING = true;
  SORTED = false;
  CHECKING = false;
}

bool viewer_status::checkable() {
  return (!SHUFFLING && !SORTING && SORTED && !CHECKING);
}

void viewer_status::checked() {
  SHUFFLING = false;
  SORTING = false;
  SORTED = true;
  CHECKING = false;
}

void viewer_status::sorted() {
  SHUFFLING = false;
  SORTING = false;
  SORTED = true;
  CHECKING = false;
}