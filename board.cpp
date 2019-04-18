#include "board.h"

// TODO: Add set commands.

// Default Card
string Card::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

string gameBoard::render(int line){
    stringstream ss;
    switch(line){
        case 0: return ".___________.";     // First Row of Card
        case 1:
            switch(biome){
                case [field]:       // Each card has a type, the "[field]" should be replaced by an enum BiomeType{FIELD, MOUNTAIN, PASTURE, FOREST, HILLS}.
                    ss << "|Field     " << number << "|";       // Second Row of Card. Inlcudes biome and the number which are stored in string stream.
                    break;
                case [mountain]:
                    ss << "|Mountain  " << number << "|";
                    break;
                case [pasture]:
                    ss << "|Pasture   " << number << "|";
                    break;
                case [forest]:
                    ss << "|Forest    " << number << "|";
                    break;
                case [hills]:
                    ss << "|Hills     " << number << "|";
                    break;
            return ss.str();        // Returns the String Stream.
            break;
            }
        case 2: return "|   _____   |";
        case 3: return "|  /     \\  |";  // There is two dashes on the right side because that is the only the backshash would work like one slash.
        case 4: return "| /_  0  _\\ |";  // It will not affect the way the board looks. One of the slashes will disappear
        case 5: return "|   |   |   |";
        case 6: return "|   |___|   |";
        case 7: return "|___________|";
                break;
        default:
            return " ";
    }
}   
