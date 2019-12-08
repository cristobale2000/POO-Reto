/*
 *Reto - Pensamiento computacional orientado a objetos
 *Clase para inicializar un objeto Fecha
 *Cristóbal Alberto Escamilla Sada - A00827074
 *6 de diciembre del 2019
*/

#ifndef Fecha_h
#define Fecha_h

class Fecha{
private:
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
public:
    Fecha();
    Fecha(int, int, int, int, int);
    void setAno(int);
    void setMes(int);
    void setDia(int);
    void setHora(int);
    void setMinuto(int);
    int getAno();
    int getMes();
    int getDia();
    int getHora();
    int getMinuto();
    string datos();
};

Fecha::Fecha(){
    ano = 0;
    mes = 0;
    dia = 0;
    hora = 0;
    minuto = 0;
}
Fecha::Fecha(int ano, int mes, int dia, int hora, int minuto){
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
}
void Fecha::setAno(int ano){
    this->ano = ano;
}
void Fecha::setMes(int mes){
    this->mes = mes;
}
void Fecha::setDia(int dia){
    this->dia = dia;
}
void Fecha::setHora(int hora){
    this->hora = hora;
}
void Fecha::setMinuto(int minuto){
    this->minuto = minuto;
}
int Fecha::getAno(){
    return ano;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getHora(){
    return hora;
}
int Fecha::getMinuto(){
    return minuto;
}
string Fecha::datos(){
    return to_string(ano) + "/" + to_string(mes) + "/" + to_string(dia) + " "
         + to_string(hora) + ":" + to_string(minuto);
}

#endif