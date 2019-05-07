// Landon Gibson || Ray Gomez || Tien Mai || Hayden Reeser || Cole Healy

#include <iostream>
#include <vector>
#include "board.h"
#include "gamemanager.h"
#include <ctime>
using namespace std;

int main(){
    srand(time(0));     // Randomizer
    
    GameManager gameManager; // Create game for 2 players

    Tile board;    
    
    int rows, columns;      // Declares variables for size of board which is user declared
    int turn;
    bool turn1;
    bool turn2;
    
    string temp;        // Temporary string to store user's name
    
    cout << "Welcome to Catan!" << endl;
    cout << "Enter Player 1's name: ";
    cin >> temp;
    board.setPlayer1Name(temp);
    cout << "Enter Player 2's name: ";
    cin >> temp;
    board.setPlayer2Name(temp);
    cout << "Enter the number of rows for the gamboard: ";
    cin >> rows;
    cout << "Enter the number of columns for the gameboard: ";
    cin >> columns;
    
    board.renderBoard(rows, columns);
    
    // ADD: While loop that will keep the players taking their turns until the game is pronounced over
    do {
            board.takeTurnPlayer1();        // Player 1 Takes their turn
            
            board.takeTurnPlayer2();
             
            
    } while(turn = 1);
    
    return 0;
}
