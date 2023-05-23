// juego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Character.h"
#include <iostream>
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10; // el tamñano de mapa
const char WALL = '-'; // el muro de mapa
const char EMPTY = ' '; // espacio
const char PLAYER = 'P'; // el jugador
const char EXIT = 'E'; // la salida de juego
const char ENEMY = 'X'; // el enemigo
const char FINAL_ENEMY = 'F'; // el finalenemigo

class Maze {
private:
    vector<vector<char>> maze; // guarda el mapa
    int exitRow;
    int exitCol;
    // inicializa el mapa
    void initializeMaze() {
        maze.assign(SIZE, vector<char>(SIZE, WALL)); // rellenar el muro

        // crea la salidad en la posicion aleatoria
        srand(time(NULL));
        exitRow = rand() % (SIZE - 2) + 1;
        exitCol = rand() % (SIZE - 2) + 1;
        maze[exitRow][exitCol] = EXIT;
    }
public:
    Maze() {
        initializeMaze();
    }

    // imprimir el mapa
    void printMaze() const {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                cout << maze[row][col] << ' ';
            }
            cout << endl;
        }
    }

    // si esta fuera del muro
    bool isValidMove(int row, int col) const {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || maze[row][col] == WALL) {
            return false;
        }
        return true;
    }

    // a ver si llega a  la salida
    bool isExit(int row, int col) const {
        if (row == exitRow && col == exitCol) {
            return true;
        }
        return false;
    }

    // la posicion del jugador 
    void setPlayerPosition(int row, int col) {
        maze[row][col] = PLAYER;
    }

    // para mover el jugador 
    bool movePlayer(int& row, int& col) {
        char move;
        cout << "Enter your move (WASD): ";
        cin >> move;

        int newRow = row;
        int newCol = col;

        // para mover  la posicion de jugador
        switch (move) {
        case 'W':
        case 'w':
            newRow--;
            break;
        case 'A':
        case 'a':
            newCol--;
            break;
        case 'S':
        case 's':
            newRow++;
            break;
        case 'D':
        case 'd':
            newCol++;
            break;
        default:
            cout << "Invalid move! Use WASD to move." << endl;
            return false;
        }

        // a ver si esta bine la posicion de jugador 
        if (!isValidMove(newRow, newCol)) {
            cout << "Invalid move!" << endl;
            return false;
        }

        // actualizar la posicion de mapa y jugador
        maze[row][col] = EMPTY;
        row = newRow;
        col = newCol;
        maze[row][col] = PLAYER;

        // comprobar si llega a la salida
        if (isExit(row, col)) {
            cout << "Congratulations! You reached the exit!" << endl;
            return true;
        }

        return false;
    }
};


int main()
{
    Maze maze;

    int playerRow = 0;
    int playerCol = 0;
    maze.setPlayerPosition(playerRow, playerCol);

    Enemy enemy("Enemy", 10, 5); // crea enemigo que contiene la vida 5 y ataque 5

    int finalEnemyRow = SIZE - 1;
    int finalEnemyCol = rand() % (SIZE - 2) + 1;
    FinalEnemy finalEnemy("Final Enemy", 20, 10, 15); // crea el final enemigo que contenga la vida 20 y ataque 10 y supeataque 15
    finalEnemy.setPosition(finalEnemyRow, finalEnemyCol);

    maze.printMaze();
    while (true) {
        if (maze.movePlayer(playerRow, playerCol)) {
            break;
        }

        enemy.move();

        int enemyRow, enemyCol;
        enemy.getPosition(enemyRow, enemyCol);
        maze.setPlayerPosition(playerRow, playerCol);
        maze.setPlayerPosition(enemyRow, enemyCol);

        // comprueba si el jugador entre en contacto con el enmigo
        if (playerRow == enemyRow && playerCol == enemyCol) {
            while (enemy.isAlive() && finalEnemy.isAlive()) {
                // el jugador ataca al enemigo
                maze.printMaze();
                cout << "Player attacked enemy!" << endl;
                maze.printMaze();
                player.attackEnemy(enemy);

                if (!enemy.isAlive()) {
                    cout << "Congratulations! You defeated the enemy!" << endl;
                    break;
                }
                //si enemigo ataca al enemigo
                cout << "Enemy attacked player!" << endl;
                enemy.attackEnemy(player);

                if (!player.isAlive()) {
                    cout << "Game Over! You were defeated by the enemy." << endl;
                    return 0;
                }
            }
        }

        // 
        // comprueba si el jugador entre en contacto con el finalenmigo
        if (playerRow == finalEnemyRow && playerCol == finalEnemyCol) {
            while (player.isAlive() && finalEnemy.isAlive()) {
                // si el jugador ataca al final enemigo
                maze.printMaze();
                cout << "Player attacked final enemy!" << endl;
                maze.printMaze();
                player.attackEnemy(finalEnemy);

                if (!finalEnemy.isAlive()) {
                    cout << "Congratulations! You defeated the final enemy!" << endl;
                    break;
                }

                // el final enemigo usa super ataque
                cout << "Final enemy used a super attack!" << endl;
                finalEnemy.superAttack(player);

                if (!player.isAlive()) {
                    cout << "Game Over! You were defeated by the final enemy." << endl;
                    return 0;
                }
            }
        }

        cout << endl;
        maze.printMaze();
    }

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
