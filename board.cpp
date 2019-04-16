#include "board.h"

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
        case 3:    
            // TODO: Bottom of Card. Somehow include house to card if claimed.
                break;
        default:
            return " ";
    }
}