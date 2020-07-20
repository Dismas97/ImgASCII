#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

void limpiarBuffer(){
    while (getchar() != '\n' && getchar() != EOF);
}
using namespace std;

sf::Image getImagen(string path){
    sf::Image imagen;
    imagen.loadFromFile(path);
    return imagen;
}

void setTam(sf::Image img,int *ancho, int *alto){
    (*ancho) = img.getSize().x;
    (*alto) = img.getSize().y;
}

char getCharMap(string mapa, sf::Color pixel){
    int tam = mapa.length();
    int escalado = (pixel.b*0.0722+pixel.r*0.2126 + pixel.g*0.7152)*tam;
    escalado/=255;
    return mapa[tam-escalado];
}

int main(){
    int ancho, alto;
    string pathImagen,pathArchivo, escribir = "", mapa=" .,:;ox%#@";
    ofstream archivo;
    sf::Image imagen;
    sf::Color pixel;
    cout<< "Path imagen"<<endl;
    cin >> pathImagen;
    limpiarBuffer();
    cout<< "Path Texto"<<endl;
    cin>>pathArchivo;
    imagen = getImagen(pathImagen);
    setTam(imagen,&ancho,&alto);

    for(int y=0; y<alto; y++){
        for(int x=0; x<ancho; x++){
            escribir+=getCharMap(mapa,imagen.getPixel(x,y));
        }
        escribir+='\n';
    }
    archivo.open(pathArchivo);
    archivo << escribir;
    archivo.close();
    cout<<"Archivo generado con exito\n Presione cualquier tecla para salir"<<endl;
    limpiarBuffer();
    getchar();
    return 0;
}
