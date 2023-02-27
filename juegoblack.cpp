// juegoblack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
class CCard
{
private:
    int naPip[5];
    int nNumber;
    int nDollar;
    int nGamble;
    int nWin;
    int nLose;
    int nDraw;

public:
    CCard();
    void FirstPlayTwo();
    int GetNumber();
    int GetPip();
    void DisplayPip();
    void DisplayPip(int);
    void TurnPlay();//
    void Win();//
    void Lose();//
    void Draw();//
    int SetGamble(int);//
    int GetMoney();//
    void DisplayInfo();//
    int GetCurrentCard();//
};

CCard::CCard()//
{
    nNumber = 0;
    nDollar = 100;//
    for (int i = 0; i < 5; i++)
        naPip[i] = 0;
    nGamble = 0;
    nWin = 0;
    nLose = 0;
    nDraw = 0;

}
int CCard::GetMoney()//
{
    return nDollar;
}

void CCard::DisplayInfo()
{
    cout << "en total juegas" << nWin + nLose + nDraw << "  partido," << "  has ganado" << nWin << "  partido," << "  has perdido " << nLose << "  partido " << "empate " << nDraw << "   partido" << endl;
    cout << "tienes credito para apostar $" << nDollar << ".\n";

}

int CCard::SetGamble(int gamble)//
{
    if (nDollar - gamble < 0)
        return -1;
    if (gamble < 0)
    {
        if (nDollar - 20 < 0)
            return -1;
        nGamble = 20;
    }
    else
        nGamble = gamble;
    nDollar -= nGamble;
    return 0;
}

void CCard::FirstPlayTwo()//
{
    naPip[0] = rand() % 13 + 1;
    naPip[1] = rand() % 13 + 1;
    nNumber = 2;
}

int  CCard::GetCurrentCard()//
{
    return naPip[nNumber - 1];
}


int CCard::GetNumber()//
{
    return nNumber;
}
int CCard::GetPip()//
{
    int nPip = 0;
    for (int i = 0; i < nNumber; i++)
    {
        if (naPip[i] >= 10)
        {
            nPip += 10;
        }

        else
            nPip += naPip[i];
    }
    return nPip;
}

void CCard::DisplayPip()//
{
    for (int i = 0; i < nNumber; i++)
        cout << naPip[i] << "\t";
    cout << endl;
}

void CCard::TurnPlay()//
{
    nNumber++;
    naPip[nNumber - 1] = rand() % 13 + 1;

}

void CCard::Win()//
{
    cout << "la carta de ganador";
    DisplayPip();
    cout << "los puntos de la carta : " << GetPip() << endl;
    nDollar = nDollar + 2 * nGamble;
    nWin++;
    cout << "apuesta $" << nDollar << " ha ganada" << nWin << "veces" << "ha perdido" << nLose << "veces " << "empate" << nDraw << "veces" << endl;
    cout << endl << endl;
}
void CCard::Lose()
{
    nLose++;
    cout << "la carta de perdedor";
    DisplayPip();
    if (GetPip() > 21)
        cout << "se paso \n";
    else
        cout << "los puntos de la carta " << GetPip() << endl;
    cout << "apuesta $" << nDollar << " ha ganado" << nWin << "veces" << "ha perdido" << nLose << "veces " << "empate " << nDraw << "veces " << endl;
    cout << endl << endl;
}

void CCard::Draw()//
{
    nDraw++;
    nDollar += nGamble;
    cout << "la carta de empate ";
    DisplayPip();
    if (GetPip() > 21)
        cout << "se paso \n";
    else
        cout << "los puntos de la carta" << GetPip() << endl;
    cout << "apuesta $" << nDollar << " ha ganado " <<   nWin  << "   veces" << "   ha perdido" << nLose << "veces " << "empate " << nDraw << "veces " << endl;
    cout << endl << endl;
}

void CCard::DisplayPip(int n)//aparte de la carta ,muestra toda la carta
{
    cout << "[*]" << '\t';
    for (int i = 1; i < nNumber; i++)
        cout << naPip[i] << '\t';
    cout << endl;
}

void DisplayRule(void)
{
    cout << "\tBienvenido a blackjack \n";
    cout << "\tla regla del juego \n";
    cout << "\t1.Los jugadores pueden pedir varias cartas \n";
    cout << "\t2.Si el numero total de puntos de cartas es superior a 21, el punto se reventara y el juego se considerara automaticamente perdido \n";
    cout << "\t3.El ganador puede obtener una apuesta doble \n";
    cout << "\t3.el ordenador ya no pide carta cuando el punto de la carta es mayor o igual a 16\n";
    cout << "\t4.buena suerte \n";
    cout << endl << endl;
}




void Judge(CCard& cpu, CCard& player)//
{
    cout << endl;
    if ((cpu.GetPip() > 21 && player.GetPip() > 21) || cpu.GetPip() == player.GetPip())
    {
        cout << "\n\nempate\n";
        cout << "datos de la computadora\t";
        cpu.DisplayPip();
        cout << "los puntos de la carta" << cpu.GetPip() << endl;
        cout << "\ntus datos\t";
        player.Draw();
        cout << endl;
    }
    else if ((cpu.GetPip() > 21) || (player.GetPip() > cpu.GetPip() && player.GetPip() <= 21))
    {
        cout << "\n\nmuy bien ganas \n";
        cout << "datos de la computadora\t";
        cpu.DisplayPip();
        cout << "los puntos de la carta" << cpu.GetPip() << endl;
        cout << "\ntus datos\t";
        player.Win();
        cout << endl;

    }
    else
    {
        cout << "\n\nque pena pierdes\n";
        cout << "datos de la computadora\t";
        cpu.DisplayPip();
        cout << "los puntos " << cpu.GetPip() << endl;
        cout << "\ntus datos\t";
        player.Lose();
        cout << endl;

    }
}


void PlayTurn(CCard& cpu, CCard& player)//
{
    char chChoice;
    int blCpu = 1, blPlayer = 1;
    cpu.FirstPlayTwo();
    player.FirstPlayTwo();
    do
    {
        cout << "tus puntos \t";
        player.DisplayPip();
        cout << "Puntos de computadora \t";
        cpu.DisplayPip(1);
        cout << "El valor de tu carta es " << player.GetPip() << endl;
        if (blPlayer)
        {
            cout << "\n\nquieres pedir la carta'Y' or 'N'";
            cin >> chChoice;
            if ((chChoice == 'Y' || chChoice == 'y'))
            {
               
                    cout << "es la que pides " << player.GetCurrentCard() << endl;
                    if (player.GetPip() > 21)
                        blPlayer = 0;
                
                else
                {
                    cout << "Lo siento, ya has pedido 5 cartas, por lo que no puede pedir mas ";
                    blPlayer = 0;
                }
            }
        }

        if ((chChoice == 'N') || (chChoice == 'n'))
        {
            blPlayer = 0;
        }

        if (cpu.GetPip() < 16 && cpu.GetNumber() < 5)
        {
            cpu.TurnPlay();
            cout << "La computadora pide una carta, y los puntos de la carta son:" << cpu.GetCurrentCard() << endl;
        }
        else
            blCpu = 0;

        if (blCpu && player.GetNumber() < 5 && player.GetPip() < 21)
            blPlayer = 1;

    } while (blCpu || blPlayer);
    Judge(cpu, player);
}
int main()
{
    srand((unsigned)time(NULL));// 
    CCard cpu, player;
    int blLogic;
    int nMoney;
    DisplayRule();// 
    char chChoice;
    cout << "empieza a jugar 'Y'or 'N' ";
    cin >> chChoice;
    while (chChoice == 'Y' || chChoice == 'y')
    {
        do
        {
            cout << "tus apuesta $" << player.GetMoney();
            cout << "\nHaga una apuesta (la apuesta no puede exceder la apuesta)";
            cin >> nMoney;
            blLogic = player.SetGamble(nMoney);
            if (blLogic)
                cout << "Su apuesta no es suficiente, vuelva a apostar!\n";

        } while (blLogic);
        PlayTurn(cpu, player);
        cout << "continuas el juego'Y'or 'N' \n";
        cin >> chChoice;
    }
    player.DisplayInfo();
    cout << "\n\nEres sabio\n";

    return 0;

}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
