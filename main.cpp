#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;

int main(){
  int ancho,altura;
  sf::Image imagen;
  sf::Color pixel;
  imagen.loadFromFile("ej1.jpg");
  ancho = imagen.getSize().x;
  altura = imagen.getSize().y;
  cout<< ancho <<endl;
  cout<< altura <<endl;
  return 0;
}
