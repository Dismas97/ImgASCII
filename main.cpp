#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;


void limpiarBuffer(){
    while (getchar() != '\n' && getchar() != EOF);
}

void setTam(Image img,int *ancho, int *alto){
    (*ancho) = img.getSize().x;
    (*alto) = img.getSize().y;
}

char getCharMap(string mapa, Color pixel){
    int tam = mapa.length();
    int escalado = (pixel.b*0.0722+pixel.r*0.2126 + pixel.g*0.7152)*tam;
    escalado/=255;
    return mapa[tam-escalado];
}

int main(){
    int ancho, alto;
    Image imagen;
    Color pixel;
    string pathImagen,escribir,pathArchivo, mapa=" .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    ofstream archivo;

    cout<< "Path imagen"<<endl;
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
