/*
 *Reto - Pensamiento computacional orientado a objetos
 *Clase para inicializar un objeto Vuelo
 *Cristóbal Alberto Escamilla Sada - A00827074
 *6 de diciembre del 2019
*/

#ifndef Vuelo_h
#define Vuelo_h

#include "Avion.h"
#include "Fecha.h"

class Vuelo{
private:
    Fecha fecha;
    string numVuelo;
    string llegadaSalida;
    string aerolinea;
    string destino;
    Avion avion;
    int numPasajeros;
public:
    Vuelo();
    Vuelo(Fecha, string, string, string, string, Avion, int);
    void setFecha(Fecha);
    void setNumVuelo(string);
    void setLlegadaSalida(string);
    void setAerolinea(string);
    void setDestino(string);
    void setAvion(Avion);
    void setNumPasajeros(int);
    Fecha getFecha();
    string getNumVuelo();
    string getLlegadaSalida();
    string getAerolinea();
    string getDestino();
    Avion getAvion();
    int getNumPasajeros();
    string datos();
};

Vuelo::Vuelo(){
    fecha = Fecha();
    numVuelo = "";
    llegadaSalida = "";
    aerolinea = "";
    destino = "";
    avion = Avion();
    numPasajeros = 0;
}
Vuelo::Vuelo(Fecha fecha, string numVuelo, string llegadaSalida,
             string aerolinea, string destino, Avion avion, int numPasajeros){
    this->fecha = fecha;
    this->numVuelo = numVuelo;
    this->llegadaSalida = llegadaSalida;
    this->aerolinea = aerolinea;
    this->destino = destino;
    this->avion = avion;
    this->numPasajeros = numPasajeros;
}
void Vuelo::setFecha(Fecha fecha){
    this->fecha = fecha;
}
void Vuelo::setNumVuelo(string numVuelo){
    this-> numVuelo = numVuelo;
}
void Vuelo::setLlegadaSalida(string llegadaSalida){
    this->llegadaSalida = llegadaSalida;
}
void Vuelo::setAerolinea(string aerolinea){
    this->aerolinea = aerolinea;
}
void Vuelo::setDestino(string destino){
    this->destino = destino;
}
void Vuelo::setAvion(Avion avion){
    this->avion = avion;
}
void Vuelo::setNumPasajeros(int numPasajeros){
    this->numPasajeros = numPasajeros;
}
Fecha Vuelo::getFecha(){
    return fecha;
}
string Vuelo::getNumVuelo(){
    return numVuelo;
}
string Vuelo::getLlegadaSalida(){
    return llegadaSalida;
}
string Vuelo::getAerolinea(){
    return aerolinea;
}
string Vuelo::getDestino(){
    return destino;
}
Avion Vuelo::getAvion(){
    return avion;
}
int Vuelo::getNumPasajeros(){
    return numPasajeros;
}
string Vuelo::datos(){
    return fecha.datos() + " " + numVuelo + " " + llegadaSalida + " "
         + aerolinea + " " + destino + " " + avion.getMarcaModelo() + " "
         + to_string(numPasajeros) + " " + to_string(avion.getCapacidad());
}

#endif