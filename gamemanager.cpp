#include "gamemanager.h"

GameManager::GameManager(int numPlayers) {
    this->numPlayers = 2;
    this->currentPlayerIndex = 0;
    this->turnOrderForward = true;
}

void GameManager::nextTurn() {
    currentPlayerIndex++;
}