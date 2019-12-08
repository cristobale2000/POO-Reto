/*
 *Reto - Pensamiento computacional orientado a objetos
 *Integra las tres clases para resolver la situación problema
 *Cristóbal Alberto Escamilla Sada - A00827074
 *6 de diciembre del 2019
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Avion.h"
#include "Fecha.h"
#include "Vuelo.h"

//Lee el archivo de entrada y asigna la información de los vuelos a un vector
vector<Vuelo> asignarVuelos(){
    vector<Vuelo> vuelos;
    ifstream archivo;
    string fechaDia, fechaHora, numVuelo, llegadaSalida, aerolinea, destino, avionMarcaModelo, pasajeros, avionCapacidad;
    archivo.open("datos_vuelos.txt");

        while(archivo >> fechaDia >> fechaHora >> numVuelo >> llegadaSalida
           >> aerolinea >> destino >> avionMarcaModelo >> pasajeros
           >> avionCapacidad){
            vuelos.push_back(Vuelo(Fecha(stoi(fechaDia.substr(0,4)),stoi(fechaDia.substr(5,7)),
                              stoi(fechaDia.substr(8)),stoi(fechaHora.substr(0,2)),
                              stoi(fechaHora.substr(3))),numVuelo,llegadaSalida,
                              aerolinea,destino,
                              Avion(avionMarcaModelo,stoi(avionCapacidad)),
                              stoi(pasajeros)));
        }

    archivo.close();
    return vuelos;
}

//Valida si en el índice que toma como parámetro del vector que toma como
//parámetro ocurre un cambio de día
bool validarCambioDia(vector<Vuelo> vuelos, int indice){
    bool validacion = false;
    if(indice > 0){
        if(vuelos[indice-1].getFecha().getAno() != vuelos[indice].getFecha().getAno()
        || vuelos[indice-1].getFecha().getMes() != vuelos[indice].getFecha().getMes()
        || vuelos[indice-1].getFecha().getDia() != vuelos[indice].getFecha().getDia()){
            validacion = true;
        }
    }
    return validacion; 
}

//Cuenta el número de días en el archivo de entrada
int cuentaDias(vector<Vuelo> vuelos){
    int dias = 1;
    for(int i = 0; i < vuelos.size(); i++){
        if(validarCambioDia(vuelos,i)){
            dias++;
        }
    }

    return dias;
}

//Resuelve la pregunta #1
string horaSaturacion(vector<Vuelo> vuelos){
    string saturaciones = "";
    int cantidadDias = cuentaDias(vuelos);
    vector<int> horas;
    for(int i = 0; i < 24; i++){
        horas.push_back(0);
    }
    int horaSaturada = 0;
    Fecha fechas[cantidadDias][2];
    int dias[cantidadDias][2];
    for(int i = 0; i < cantidadDias; i++){
        dias[i][0] = i;
        dias[i][1] = 0;
    }
    int cuentaDias = 0;
    for(int i = 0; i < vuelos.size(); i++){
        if(!validarCambioDia(vuelos,i)){
            fechas[cuentaDias][1] = vuelos[i].getFecha();
            horas[vuelos[i].getFecha().getHora()]++;
            if(horas[vuelos[i].getFecha().getHora()] > horas[dias[cuentaDias][1]]){
                dias[cuentaDias][1] = vuelos[i].getFecha().getHora();
            }
        }else{
            cuentaDias++;
            fechas[cuentaDias][1] = vuelos[i].getFecha();
            dias[cuentaDias][1] = vuelos[i].getFecha().getHora();
            for(int i = 0; i < 24; i++){
                horas[i] = 0;
            }
            horas[vuelos[i].getFecha().getHora()]++;
        }
    }
    for(int i = 0; i < cantidadDias; i++){
        saturaciones += fechas[i][1].datos().substr(0,fechas[i][1].datos().find(" "))
                     + " - Mayor saturación durante hora " + to_string(dias[i][1]) + "\n";
    }

    return saturaciones;
}

//Resuelve las preguntas #2 y #3
string llegadasSalidasPromedio(vector<Vuelo> vuelos){
    string promedios = "";
    int dias = 1;
    vector<int> llegadasHoras, salidasHoras;
    for(int i = 0; i < 24; i++){
        llegadasHoras.push_back(0);
        salidasHoras.push_back(0);
    }
    for(int i = 0; i < vuelos.size(); i++){
        if(vuelos[i].getLlegadaSalida() == "A"){
            llegadasHoras[vuelos[i].getFecha().getHora()]++;
        }else{
            salidasHoras[vuelos[i].getFecha().getHora()]++;
        }
        if(validarCambioDia(vuelos,i)){
            dias++;
        }
    }
    for(int i = 0; i < 24; i++){
        llegadasHoras[i] /= dias;
        salidasHoras[i] /= dias;
        promedios += "Hora " + to_string(i) + " - " + to_string(llegadasHoras[i])
                  + " llegadas y " + to_string(salidasHoras[i]) + " salidas promedio\n";
    }

    return promedios;
}

//Resuelve la pregunta #4
string llegadasSalidasAerolinea(vector<Vuelo> vuelos){
    string llegadasSalidas = "";
    vector<string> aerolineas;
    aerolineas.push_back(vuelos[0].getAerolinea());
    vector<int> llegadasAerolineas, salidasAerolineas;
    for(int i = 0; i < vuelos.size(); i++){
        bool existe = false;
        for(int j = 0; j < aerolineas.size(); j++){
            if(aerolineas[j] == vuelos[i].getAerolinea()){
                existe = true;
            }
        }
        if(!existe){
            aerolineas.push_back(vuelos[i].getAerolinea());
        }
    }
    for(int i = 0; i < aerolineas.size(); i++){
        llegadasAerolineas.push_back(0);
        salidasAerolineas.push_back(0);
    }
    for(int i = 0; i < vuelos.size(); i++){
        for(int j = 0; j < aerolineas.size(); j++){
            if(vuelos[i].getAerolinea() == aerolineas[j] && vuelos[i].getLlegadaSalida() == "A"){
                llegadasAerolineas[j]++;
            }else if(vuelos[i].getAerolinea() == aerolineas[j] && vuelos[i].getLlegadaSalida() == "S"){
                salidasAerolineas[j]++;
            }
        }
    }
    for(int i = 0; i < aerolineas.size(); i++){
        llegadasSalidas += aerolineas[i] + ": "  + to_string(llegadasAerolineas[i])
                        + " llegadas y " + to_string(salidasAerolineas[i]) + " salidas\n";
    }

    return llegadasSalidas;
}

//Resuelve la pregunta #5
string pasajerosPorDia(vector<Vuelo> vuelos){
    string pasPorDia = "";
    int cantidadDias = cuentaDias(vuelos);
    Fecha fechas[cantidadDias][2];
    int pas[cantidadDias][2];
    for(int i = 0; i < cantidadDias; i++){
        pas[i][0] = i;
        pas[i][1] = 0;
    }
    int cuentaDias = 0;
    for(int i = 0; i < vuelos.size(); i++){
        if(validarCambioDia(vuelos,i)){
            cuentaDias++;
        }
        fechas[cuentaDias][1] = vuelos[i].getFecha();
        pas[cuentaDias][1] += vuelos[i].getNumPasajeros();
    }
    for(int i = 0; i < cantidadDias; i++){
        pasPorDia += fechas[i][1].datos().substr(0,fechas[i][1].datos().find(" "))
                     + " -  " + to_string(pas[i][1]) + " pasajeros atendidos\n";
    }

    return pasPorDia;
}

//Resuelve la pregunta #6
string capacidadPromedioUtilizada(vector<Vuelo> vuelos){
    string capacidadesPromedio = "";
    int cantidadDias = cuentaDias(vuelos);
    Fecha fechas[cantidadDias][2];
    double pas[cantidadDias][2],cap[cantidadDias][2];
    for(int i = 0; i < cantidadDias; i++){
        pas[i][0] = i;
        pas[i][1] = 0;
        cap[i][0] = i;
        cap[i][1] = 0;
    }
    int cuentaDias = 0;
    for(int i = 0; i < vuelos.size(); i++){
        if(validarCambioDia(vuelos,i)){
            cuentaDias++;
        }
        fechas[cuentaDias][1] = vuelos[i].getFecha();
        pas[cuentaDias][1] += vuelos[i].getNumPasajeros();
        cap[cuentaDias][1] += vuelos[i].getAvion().getCapacidad();
    }
    for(int i = 0; i < cantidadDias; i++){
        pas[i][1] *= 100;
        pas[i][1] /= cap[i][1];
        capacidadesPromedio += fechas[i][1].datos().substr(0,fechas[i][1].datos().find(" "))
                     + " -  " + to_string(pas[i][1]) + " % de capacidad utilizada\n";
    }


    return capacidadesPromedio;
}

/*
 *Método main: se corre el programa a través de un menú de opciones con cada
  una de las preguntas
 *Tiene acceso a todos los métodos establecidos anteriormente
 *Este programa funciona con cualquier cantidad de vuelos en el archivo de 
  entrada asi como cualquier cantidad de días y/o aerolineas,considerando
  que los días y las horas están acomodados en orden.
 */
int main(){
    vector<Vuelo> vuelos = asignarVuelos();
    char opc = '*';

    while(opc != '6'){
        cout << endl << "                      Reto pensamiento computacional orientado a objetos:" << endl << endl
             << "1. Hora de cada día con mayor saturación." << endl
             << "2. Cantidad de llegadas y salidas por hora promedio (dos preguntas juntas)." << endl
             << "3. Cantidad de llegadas y salidas por aerolínea." << endl
             << "4. Cantidad de pasajeros atendidos por día." << endl
             << "5. Porcentaje promedio de capacidad utilizada en los aviones." << endl
             << "6. Salida del programa" << endl << endl
             << "Tecléa la opción que deseas accesar: ";
        cin >> opc;

        switch (opc){
        case '1':
            cout << endl << horaSaturacion(vuelos) << endl;
            break;
        case '2':
            cout << endl << llegadasSalidasPromedio(vuelos) << endl;
            break;
        case '3':
            cout << endl << llegadasSalidasAerolinea(vuelos) << endl;
            break;
        case '4':
            cout << endl << pasajerosPorDia(vuelos) << endl;
            break;
        case '5':
            cout << endl << capacidadPromedioUtilizada(vuelos) << endl;
            break;
        case '6':
            cout << endl << "Has salido del programa." << endl << endl;
            break;
        default:
            cout << endl << "Opción inválida, vuelve a teclear otra opción." << endl;
            break;
        }
    }
}