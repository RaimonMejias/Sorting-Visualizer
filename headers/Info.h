#ifndef INFO_H
#define INFO_H

#include <string>
#include <vector>

template<class Temp>
class Info {

public:

  Info();
  Info(std::string name, int values);

  std::string name() const;
  std::pair<std::string, Temp> value(int index) const;
  int size() const;

  void name_value(int index, std::string name);
  void set_value(int index, Temp value);
  
private:

  std::string name_;
  std::vector<std::pair<std::string, Temp> > values_;

};

template<class Temp>
Info<Temp>::Info() {

}

template<class Temp>
Info<Temp>::Info(std::string name, int values) {
  name_ = name;
  if (values <= 0) { values = 1; }
  values_.resize(values);
}

template<class Temp>
std::string Info<Temp>::name() const {
  return name_;
}

template<class Temp>
int Info<Temp>::size() const {
  return values_.size();
}

template<class Temp>
std::pair<std::string, Temp> Info<Temp>::value(int index) const {
  if (index < 0 || (unsigned int)index >= values_.size()) { return values_[0]; }
  return values_[index];
}

template<class Temp>
void Info<Temp>::name_value(int index, std::string name) {
  values_[index].first = name;
}

template<class Temp>
void Info<Temp>::set_value(int index, Temp value) {
  values_[index].second = value;
}

#endif