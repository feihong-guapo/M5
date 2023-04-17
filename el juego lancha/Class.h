#pragma once
#include  <iostream>

class lancha 
{
private:
	int velocidad;
	int distancia;
	int nitro;
	std::string nombre;
   

public:

    //construcor
    lancha(std::string n) {
        nombre = n;
        velocidad = 0;
        distancia = 0;
        nitro = 1;
    }


    //getters
    std::string get_nombre() {
        return nombre;
    }

    int get_velocidad() {
        return velocidad;
    }

    int get_distancia_recorrida() {
        return distancia;
    }

    int get_nitro() {
        return nitro;
    }


	//setters
   void actualizar_distancia_recorrida() {
        distancia += velocidad * 100;
       std:: cout << nombre << " ha recorrido " << distancia<< " metros." <<std:: endl;
    }


  

    void lanzar_dado() {
        int puntos = rand() % 6;
        velocidad += puntos;
       std:: cout << "El jugador " << nombre << " ha obtenido " << puntos << " en el dado." << std::endl;
    }

  
    void usar_nitro() {
        if (nitro > 0) {
            nitro = 0;
            int r = rand() % 2;
            if (r == 0) {
                velocidad /= 2;
               std::cout << "El jugador " << nombre << " ha usado el nitro, pero ha salido 0 en la ruleta. Su velocidad se divide por la mitad." << std::endl;
            }
            else {
                velocidad *= 2;
                std::cout << "El jugador " << nombre << " ha usado el nitro y ha salido 1 en la ruleta. Su velocidad se multiplica por dos." << std::endl;
            }
        }
        else {
            std::cout << "El jugador " << nombre << " no tiene nitro para usar." << std:: endl;
        }
    }


    
};

