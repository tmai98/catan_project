#include "gamemanager.h"

/*void GameManager :: nextTurn() {
    currentPlayerIndex++;
}

void GameManager :: setPlayer1Name(string name){
    player1Name = name;
}

void GameManager :: setPlayer2Name(string name){
    player2Name = name;
}
*/
// boardArray[x][y][number][biomeType][settled];


int GameManager::startMaterials(){
    vector<int> player1Mats(5);     // Each player starts with one material from each biome
    player1Mats.at(0) = 1;
    player1Mats.at(1) = 1;
    player1Mats.at(2) = 1;
    player1Mats.at(3) = 1;
    player1Mats.at(4) = 1;
}