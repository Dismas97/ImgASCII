#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;

/**
@author Dismas
**/

void limpiarBuffer(){
    while (getchar() != '\n' && getchar() != EOF);
}

void setTam(Image img,int *ancho, int *alto){
    (*ancho) = img.getSize().x;
    (*alto) = img.getSize().y;
}

char getCharMap(string mapa, Color pixel){
    int escalado = (pixel.b*0.0722+pixel.r*0.2126 + pixel.g*0.7152)*mapa.length();
    escalado/=255;
    return mapa[escalado];
}

int main(){
    int ancho, alto;
    Image imagen;
    Color pixel;
    string pathImagen,escribir,pathArchivo;
    string mapa;
    ofstream archivo;
    cout<<"Cantidad de caracteres:\n(1) 10 (2) 70 (3) 96\n";
    int cant;
    cin>>cant;
    switch(cant){
        case 1: mapa = "@#*+=;:-. "; break;
        case 2: mapa = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. "; break;
        case 3: mapa = "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[] {}?j|()=~!-/<>\\\"^_';,:`. "; break;
        default: mapa = "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[] {}?j|()=~!-/<>\\\"^_';,:`. ";
    }

    cout<<"Path imagen"<<endl;
    cin >> pathImagen;

    imagen.loadFromFile(pathImagen);
    pathArchivo=pathImagen.substr(0,pathImagen.length()-4);
    pathArchivo+=".txt";
    archivo.open(pathArchivo);
    setTam(imagen,&ancho,&alto);
    limpiarBuffer();

    for(int y=0; y<alto; y++){
        escribir="";
        for(int x=0; x<ancho; x++){
            escribir+=getCharMap(mapa,imagen.getPixel(x,y));
        }
        archivo<<escribir<<endl;
    }
    archivo.close();
    cout<<"Archivo generado con exito\nPresione cualquier tecla para salir"<<endl;
    getchar();
    return 0;
}
