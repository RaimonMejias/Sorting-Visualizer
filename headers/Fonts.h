/*!
 * @file Fonts.h
 * @brief Clase auxiliar para simplificar el uso de sf::Font
 * @date 28/07/2022
 * @author Raimon Mejías Hernández<alu0101390161@ull.edu.es>
*/
#ifndef FONTS_H
#define FONTS_H

#include <SFML/Graphics.hpp>

#define DEFAULT_PATH "C:\\WINDOWS\\FONTS\\" 

class Fonts : public sf::Font {

public:

  //Constructores y Destructor
  Fonts();
  Fonts(const std::string& font);
  Fonts(const Fonts& font);

  //Getters y Setters 
  bool is_loaded() const;
  std::string font() const;

  //Prefabs
  static const sf::Font Calibri; 
  static const sf::Font Arial;
  
private:

  bool loaded_;

};

#endif