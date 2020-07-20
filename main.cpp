#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

void limpiarBuffer(){
    while (getchar() != '\n' && getchar() != EOF);
}

using namespace std;

int main(){
    int ancho,altura;
    sf::Image imagen;
    sf::Color pixel;
    string pathImagen;
    cout<< "Nombre imagen"<<endl;
    cin >> pathImagen;
    imagen.loadFromFile(pathImagen);
    ancho = imagen.getSize().x;
    altura = imagen.getSize().y;
    cout<< ancho<<'\n'<<altura<<"\nPresione cualquier tecla para continuar"<<endl;
    limpiarBuffer();
    getchar();
    return 0;
}
