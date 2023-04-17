// el juego lancha.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Class.h"
#include <iostream>
using namespace std;


//variables
int numj;
std::string nom[4];


//declaracion funciones
void menu();
void nombres();
void disenio();



void menu() {//Captura de numero de jugadores
    do {
        cout << "   Cuantos jugadores desean ingresar (maximo 4 jugadores)--> ";
        cin >> numj;
        cout << endl;

        if (numj > 4) {
            cout << "Error Maximo 4 jugadores" << endl;
        }
        else if (numj < 1) {
            cout << "Error Elige de 1 a 4 jugadores" << endl;
        }

        system("Pause");
        system("cls");
    } while (numj < 1 || numj > 4);

}				//menu()


//***********
void nombres() {	//Se capturan los nombres  con el que van a ingresar

    for (int i = 0; i < numj; i++)
    {
        cout << "Ingresa el nombre del jugador (lancha1 or lancha2)" << i + 1 << " --> ";
        cin >> nom[i];
        cout << endl;
    }
    system("cls");

}				// nombres()

//************

void disenio() {				//El "diseño" del juego
    cout << "===========================================================================" << endl;
    cout << "=                           BIENVENIDO AL JUEGO                           =" << endl;
    cout << "=                                LANCHA                                   =" << endl;
    cout << "===========================================================================" << endl;

}





int main()
{
    //Llamada de funciones
    disenio();
    menu();
    disenio();
    nombres();
    disenio();
    srand(time(NULL));

    lancha lancha1("Lancha 1");
  
    for (int turno = 1; turno <= 5; turno++) {
        cout << "=== Turno " << turno << " ===" << endl;
        // Lanzar el dado y actualizar la velocidad de cada lancha
        lancha1.lanzar_dado();
       
         
        lancha1.actualizar_distancia_recorrida();
        
        // Usar el nitro si el jugador lo desea
        int opcion;
        cout << "Quiere usar el nitro? (1 = si, 0 = no)" << endl;
        cin >> opcion;
        if (opcion == 1) {
            lancha1.usar_nitro();
          
           
        }
        
        
        // Actualizar la distancia recorrida de cada lancha
    }
    system("Pause");
    system("cls");

    lancha lancha2("Lancha 2");
    for (int turno = 1; turno <= 5; turno++) {
        cout << "=== Turno " << turno << " ===" << endl;
        // Lanzar el dado y actualizar la velocidad de cada lancha
       
        lancha2.lanzar_dado();

     
        lancha2.actualizar_distancia_recorrida();

        // Usar el nitro si el jugador lo desea
        int opcion;
        cout << "Quiere usar el nitro? (1 = si, 0 = no)" << endl;
        cin >> opcion;
        if (opcion == 1) {
          
            lancha2.usar_nitro();
            
        } 
        
        // Actualizar la distancia recorrida de cada lancha
    }
    

    cout << "la distacia de lancha1  " <<   lancha1.get_distancia_recorrida()<<endl;
    cout << "la distacia de lancha2  " <<   lancha2.get_distancia_recorrida()<<endl;

    if (lancha1.get_distancia_recorrida() > lancha2.get_distancia_recorrida()) {
        cout << "ha ganado la lancha 1" << endl;
    }
    else if (lancha1.get_distancia_recorrida() < lancha2.get_distancia_recorrida()) {

        cout << "ha perdido la lancha 1" << endl;
    }
    else if (lancha1.get_distancia_recorrida() == lancha2.get_distancia_recorrida()) {
        cout << "empate" << endl;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
