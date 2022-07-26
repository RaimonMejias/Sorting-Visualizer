#include "Debug.h"
#include "Viewer.h"

Debug::Debug() {
  font_ = Fonts{"CALIBRIL.TTF"};
  text_.setFont(font_);
}

Debug::~Debug() {

}

void Debug::print(int cmps, int access, const Info<int>& info, const std::unique_ptr<viewer_status>& status) {
  std::stringstream ss;
  if (!font_.is_loaded()) { return; }
  ss << info.name() << " | Comparaciones = " << cmps << " | Accesos = " << access << "| Estado = ";
  if (!status -> SORTING && !status -> SORTED && !status -> CHECKING)     { ss << "Desordenando | "; }
  else if (status -> SORTING && !status -> SORTED && !status -> CHECKING) { ss << "Ordenando | "; }
  else if (!status -> SORTING && status -> SORTED && status -> CHECKING)  { ss << "Comprobando | "; }
  else                                                                    { ss << "Ordenado | "; }
  for (int i{0}; i < info.size(); i++) {
    ss << info.value(i).first << " = " << info.value(i).second << ((i < info.size() - 1)? " | " : "");
  }
  text_.setString(ss.str());
}

void Debug::render(sf::RenderWindow& window) {
  rect_.setPosition(1, 1);
  rect_.setSize(sf::Vector2f{1278, 20});
  rect_.setFillColor(sf::Color::Black);
  rect_.setOutlineThickness(1);
  text_.setPosition(5, 2);
  text_.setFillColor(sf::Color::White);
  text_.setStyle(sf::Text::Bold);
  text_.setCharacterSize(15);
  window.draw(rect_);
  window.draw(text_);
}