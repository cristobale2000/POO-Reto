/*
 *Reto - Pensamiento computacional orientado a objetos
 *Clase para inicializar un objeto Avión
 *Cristóbal Alberto Escamilla Sada - A00827074
 *6 de diciembre del 2019
*/

#ifndef Avion_h
#define Avion_h

class Avion{
private:
    string marcaModelo;
    int capacidad;
public:
    Avion();
    Avion(string, int);
    void setMarcaModelo(string);
    void setCapacidad(int);
    string getMarcaModelo();
    int getCapacidad();
    string datos();
};

Avion::Avion(){
    marcaModelo = "";
    capacidad = 0;
}
Avion::Avion(string marcaModelo, int capacidad){
    this->marcaModelo = marcaModelo;
    this->capacidad = capacidad;
}
void Avion::setMarcaModelo(string marca){
    this->marcaModelo = marcaModelo;
}
void Avion::setCapacidad(int capacidad){
    this->capacidad = capacidad;
}
string Avion::getMarcaModelo(){
    return marcaModelo;
}
int Avion::getCapacidad(){
    return capacidad;
}
string Avion::datos(){
    return marcaModelo + " " + to_string(capacidad);
}


#endif