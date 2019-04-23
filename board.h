#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <sstream>
#include "gamemanager.h"

using namespace std;

enum BiomeType{FOREST, HILLS, FIELD, PASTURE, MOUNTAIN};

class Tile{
    protected:
        int number;     // Describes Tile Number
        BiomeType biome;        // Describes Tile Biome
        
    public:
        void setbiome(BiomeType);
        void setNumber(int);
        
        BiomeType getBiome();
        
        int getNumber();
        
        virtual string render(int);
        virtual bool play(GameManager&);
}
