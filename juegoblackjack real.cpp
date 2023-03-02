// juego3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string.h>
using namespace std;
int n;//la cantidad  de jugador
int card[12];//la cantidad de carta de jugador 
int ranks[12][22];//los puntos de jugador
char suits[12][22];//el color de carta
char hit;//pregunta si jugador quiere pedir otra carta
bool assed[5][14];//comprueba a ver la carta ya esta repartida.
bool loser[12];//la lista de perdedor
bool tie;//a ver si empate
string names[11];//el nombre de jugador;
string croupiere;

void allot(int nameord/*el jugador nameord*/) {
    int st /*el color*/, rk/*los puntos*/;
    srand(int(time(NULL)));//gerera el numero aleatorio
    do {
        st = rand() % 4 + 1;
        rk = rand() % 13 + 1;
    } while (assed[st][rk]);//cuando la carta ya esta usada
    assed[st][rk] = true;//marca esa carta
    suits[nameord][++card[nameord]] = st; //guarda esa carta para no repetir la misma 
    ranks[nameord][++card[nameord]] = rk;//lo mismo
}

void initializa() {
    cout << "\t\t welcome to simple blackjack\n\n";
    memset(assed, false, sizeof(assed));//inicializa toda la carta
    memset(card, 0, sizeof(card));//inicializa la carta de jugador

    do {
        cout << "how many players(1-10):";
        cin >> n;


    } while (n < 1 || n>10);
    for (int i = 1;i <= n;i++) {
        cout << "enter player" << i << "'s name:";//pregunta el nombre de jugador
        cin >> names[i];
        names[n + 1] = croupiere;
    }
    for (int i = 1;i < n;i++) {
        allot(i);//empieza a repartir la  primera carta al jugador 1
        allot(i);// empieza a repatir la   segunda carta al jugador 2
    }

}



int cardsum(int nameord) {
    int cnt = 0;
    for (int i = 1;i <= card[nameord];i++)
        /*   if (ranks[nameord][i] < 11) {
               ranks[nameord][i];
           }
           else
           {
               ranks[nameord][i] = 10;
           }
           */

        cnt = cnt + (ranks[nameord][i] < 11 ? ranks[nameord][i] : 10);//si los puntos de la carta es mayor que 10 ,suma 10 ,sino suma el valor que tiene.
    return cnt;
}
void put_card(int A, int B) {
    switch (ranks[A][B]) {
    case 1:cout << "A";break;//La carta A
    case 11:cout << "J";break;//la carta J 
    case 12:cout << "Q";break;
    case 13:cout << "K";break;
    default:cout << ranks[A][B];// la carta de numero

    }
    switch (suits[A][B])
    {
    case 1:cout << "picas";break;
    case 2:cout << "diamantes";break;
    case 3:cout << "treboles";break;
    case 4: cout << "corazon";break;
    }
    cout << "  ";
}

void put_all() {
    for (int i = 1; i < n; i++)
    {
        cout << names[i] << ":  ";
        for (int cd = 1;cd <= card[i];cd++)
            put_card(i, cd);
        cout << "(" << cardsum(i) << ")\n";
    }
}

void put(int nameord) {
    cout << names[nameord] << ":   ";
    for (int cd = 1;cd <= card[nameord];cd++)
        put_card(nameord, cd);//muestra la informacion de usuaio , sobre todo la carta 
    cout << "(" << cardsum(nameord) << ")\n";

}


int main()
{
    void initializa();
    put_all();
    for (int i = 0; i < n; i++)
    {
        if (loser[i])// si este usuario pierde,toca el siguiente.
            continue;
        do {
            do {
                cout << names[i] << ",do you want a hit?(your point is " << cardsum(i) << "):";//pregunta el usuario quieres pedir mas carta
                cout << hit << endl;

            } while (hit != 'Y' && hit != 'y' && hit != 'N' && hit != 'n');
            if (hit == 'y' || hit == 'Y') {
                allot(i);//pedir mas carta para este usuarioi
                put(i);//muesta la informacion
            }
            else//si no pide la carta
                cout << endl;
            if (cardsum(i) > 21)
                loser[i] = true;//marca este usuario ya pierde
            cout << names[i] << " lose \n\n";
            break;

        } while (hit == 'N' || hit == 'n');
        put(n + 1);
        if (cardsum(n + 1) > 21) {
            loser[n + 1] = true;//marca cropier pierde
            for (int i = 1; i <= n; i++)
            {
                if (loser[i])
                    cout << names[i] << "lose. \n";
                else//si croperi pierde,el usuario que tiene menos 21 gana
                    cout << names[i] << " wins \n";
                cout << "croupiere";
                cout << "lose .";
            }
        }
       
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
