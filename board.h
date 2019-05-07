#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <sstream>
#include <string>
#include <ios>
#include <iomanip>
#include <fstream>
#include <vector>
#include "gamemanager.h"

using namespace std;

enum biomeType{FOREST, HILLS, FIELD, PASTURE, MOUNTAIN, LAST};

class Tile{
    protected:
        int number = rand() % 12 + 1;             // Describes Tile Number from 2 - 12
        biomeType biome;        // Describes Tile Biome
        
        
    public:
        int location1;
        int location2;
        int biomeNum = -1;
        
        void setBiome(biomeType);
        void setNumber(int);
//        string userPlayer1, userPlayer2;
        void setPlayer1Name(string);
        string getPlayer1Name();
        void setPlayer2Name(string);
        string getPlayer2Name();
        string player1Name;
        string player2Name;
        
        biomeType getBiome();
        
        int getNumber();
        void setTile(biomeType, int);
        
        void takeTurnPlayer1();
        void takeTurnPlayer2();
        

        
        string render(int);
        string renderSettlement1(int);
        string renderSettlement2(int);
        void renderBoard(int, int);
};

class gameOutput : public Tile{
    public:
        gameOutput(biomeType, int);
        string render(int);
};

#endif


