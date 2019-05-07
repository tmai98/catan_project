#include "board.h"
#include "gamemanager.h"

// TODO: Add set commands.
void Tile::setBiome(biomeType b){
    biome = b;
}

void Tile::setNumber(int n){
    number = n;
}

biomeType Tile::getBiome(){
    return biome;
}

int Tile::getNumber(){
    number = rand() % 11 + 2;       // Randomizes number each time the function is called.
    return number;
}

void Tile::setPlayer1Name(string name){
    player1Name = name;
}

string Tile::getPlayer1Name() {
    return player1Name;
}

void Tile::setPlayer2Name(string name){
    player2Name = name;
}

string Tile::getPlayer2Name() {
    return player2Name;
}

void Tile::renderBoard(int rows, int columns) {     // Function to render board
    int height = 9;        // Deals with hieght of cards.
    int temp11 = rand() % rows;     // Random number within the range of rows for a settlement to be spawned for player1
    int temp12 = rand() % columns;      // Random number within the range of columns for a settlement to be spawned for player1
    int temp21 = rand() % rows;
    int temp22 = rand() % columns;
    
    if (temp11 == temp21 && temp12 == temp22){      // The next two if statements are to help prevent player 1 and 2 recieving the same settlement location
        temp21 = rand() % rows;
    }
        
    if (temp11 == temp21 && temp12 == temp22){
        temp21 = rand() % rows;
    }
    
    for (int t = 0; t < rows; t++){     // Outputs the number of rows
        for (int i = 0; i < height; i++) {     // Outputs each case in render function
            for (int j = 0; j < columns; j++) {     // Outputs the number of columns
                if (temp11 == t && temp12 == j){
                    cout << renderSettlement1(i) << " ";        // Outputs a settlement at the randomly generated location for player1
                }
                else if (temp21 == t && temp22 == j){
                    cout << renderSettlement2(i) << " ";        // Outputs a settlement at the randomly generated location for player2
                }
                else {
                    cout << render(i) << " ";       // Renders basic Tiles
                }
            }
        cout << endl;
        }
    }
}

/*Tile::Tile(biomeType b, int n){
    setBiome(b);
    setNumber(n);
}*/

/*string Tile::render(int line){
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
}*/

void Tile::setTile(biomeType b, int n){
    setBiome(b);
    setNumber(n);
}

void Tile::takeTurnPlayer1() {      // Player 1 takes turn
    int input, temp;        // Local variables for input
    int turn;
    GameManager gamemanager;
    gamemanager.startMaterials;
    cout << player1Name << "'s turn." << endl;
    cout << player1Name << " rolled a " << getNumber() << "!" << endl;
    
    if (number == location1) {
        player1Mats.at(biomeNum)++;     // If the number rolled eqauls the number of the tile that player1 is on, then they will recieve an additional resource depending upon the biome they are on
    }
    
/* The next few lines of code are for the menu options that the player can navigate through to complete their turn */
    
    cout << "Wood (" << player1Mats.at(0) << ") Bricks (" << player1Mats.at(1) << ") Grain (" << player1Mats.at(2) << ") Wool (" << player1Mats.at(3) << ") Ore (" << player1Mats.at(4) << ")" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1: Buy, 2: Trade, 3: End Turn" << endl;
    cin >> input;

    if (input == 1) {
        cout << "What would you like to buy?" << endl;
        cout << "1: Settlement (1 wood, 1 brick, 1 grain, 1 wool)" << endl;
        cout << "2: City (2 ore, 3 grain)" << endl;
        cout << "3: Development Card (1 ore, 1 grain, 1 wool)" << endl;
        cout << "4: Quit" << endl;
        
        cin >> temp;
        if (temp == 1) {
            
            if (player1Mats.at(0) >= 1 && player1Mats.at(1) >= 1 && player1Mats.at(2) >= 1 && player1Mats.at(3) >= 1 && player1Mats.at(4) >= 1){
                player1Mats.at(0) = player1Mats.at(0) - 1;
                player1Mats.at(1) = player1Mats.at(1) - 1;
                player1Mats.at(2) = player1Mats.at(2) - 1;
                player1Mats.at(3) = player1Mats.at(3) - 1;
                player1Mats.at(4) = player1Mats.at(4) - 1;
                
                cout << player1Mats.at(0) << endl;
                cout << player1Mats.at(1) << endl;
                cout << player1Mats.at(2) << endl;
                cout << player1Mats.at(3) << endl;
                cout << player1Mats.at(4) << endl;
            }
            else {
                cout << "Sorry, not enough sauce" << endl;
            }
            
        }
        turn = 1;
    }
    else if (input == 2) {
        cout << "What resources would you like to give away? (You will be giving away 3 of this resource)" << endl;
        cout << "1: Wood (" << player1Mats.at(0) << ") 2: Bricks (" << player1Mats.at(1) << ") 3: Grain (" << player1Mats.at(2) << ") 4: Wool (" << player1Mats.at(3) << ") 5: Ore (" << player1Mats.at(4) << ") 6: Quit Trading" << endl;
        
        cin >> temp;
        
        if (player1Mats.at(temp) >= 3) {
            player1Mats.at(temp) = player1Mats.at(temp) - 3;
            cout << "Which resource would you like to recieve?" << endl;
            cout << "1: Wood (" << player1Mats.at(0) << ") 2: Bricks (" << player1Mats.at(1) << ") 3: Grain (" << player1Mats.at(2) << ") 4: Wool (" << player1Mats.at(3) << ") 5: Ore (" << player1Mats.at(4) << ")" << endl;
            cin >> temp;
            player1Mats.at(temp)++;
            cout << "Wood (" << player1Mats.at(0) << ") Bricks (" << player1Mats.at(1) << ") Grain (" << player1Mats.at(2) << ") Wool (" << player1Mats.at(3) << ") Ore (" << player1Mats.at(4) << ")" << endl;

        }
        
        else {
            cout << "Sorry, not enough resources." << endl;
        }
        turn = 1;
        
    }
      else if (input == 3) {
        
        turn = 1;
        
    }

    
}

void Tile::takeTurnPlayer2() {      // Player 2 takes turn
    int input, temp;        // Local variables for input
    int turn;
    vector<int> player1Mats(5);     // Each player starts with one material from each biome
    player1Mats.at(0) = 1;
    player1Mats.at(1) = 1;
    player1Mats.at(2) = 1;
    player1Mats.at(3) = 1;
    player1Mats.at(4) = 1;
    cout << player2Name << "'s turn." << endl;
    cout << player2Name << " rolled a " << getNumber() << "!" << endl;
    
    if (number == location1) {
        player1Mats.at(biomeNum)++;     // If the number rolled eqauls the number of the tile that player1 is on, then they will recieve an additional resource depending upon the biome they are on
    }
    
/* The next few lines of code are for the menu options that the player can navigate through to complete their turn */
    
    cout << "Wood (" << player1Mats.at(0) << ") Bricks (" << player1Mats.at(1) << ") Grain (" << player1Mats.at(2) << ") Wool (" << player1Mats.at(3) << ") Ore (" << player1Mats.at(4) << ")" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1: Buy, 2: Trade, 3: End Turn" << endl;
    cin >> input;
    
    if (input == 1) {
        cout << "What would you like to buy?" << endl;
        cout << "1: Settlement (1 wood, 1 brick, 1 grain, 1 wool)" << endl;
        cout << "2: City (2 ore, 3 grain)" << endl;
        cout << "3: Development Card (1 ore, 1 grain, 1 wool)" << endl;
        cout << "4: Quit" << endl;
        
        cin >> temp;
        turn = 1;
    }
    else if (input == 2) {
        cout << "What resources would you like to give away? (You will be giving away 3 of this resource)" << endl;
        cout << "1: Wood (" << player1Mats.at(0) << ") 2: Bricks (" << player1Mats.at(1) << ") 3: Grain (" << player1Mats.at(2) << ") 4: Wool (" << player1Mats.at(3) << ") 5: Ore (" << player1Mats.at(4) << ") 6: Quit Trading" << endl;
        
        cin >> temp;
        
        if (player1Mats.at(temp) >= 3) {
            player1Mats.at(temp) = player1Mats.at(temp) - 3;
            cout << "Which resource would you like to recieve?" << endl;
            cout << "1: Wood (" << player1Mats.at(0) << ") 2: Bricks (" << player1Mats.at(1) << ") 3: Grain (" << player1Mats.at(2) << ") 4: Wool (" << player1Mats.at(3) << ") 5: Ore (" << player1Mats.at(4) << ")" << endl;
            cin >> temp;
            player1Mats.at(temp)++;
            cout << "Wood (" << player1Mats.at(0) << ") Bricks (" << player1Mats.at(1) << ") Grain (" << player1Mats.at(2) << ") Wool (" << player1Mats.at(3) << ") Ore (" << player1Mats.at(4) << ")" << endl;

        }
        
        else {
            cout << "Sorry, not enough resources." << endl;
        }
        turn = 1;
        
    }
    else if (input == 3) {
        
        turn = 1;
        
    }
    
}

string Tile::render(int line){
    stringstream ss;
    switch(line){
        case 0: return ".___________.";     // First Row of Card
        case 1:
            biome = biomeType(rand() % LAST);       // This randomizes the biomes from the first biome to the last. "LAST" is used becuase when you use the % operator 
                                                    // it does not include the last enumeration element. Therefore, another enumeration element had to be added so that 
                                                    // all desired biomes would be included in the randomizer.
            
            switch(biome){
                case FOREST:       // Each card has a type, the "[field]" should be replaced by an enum BiomeType{FIELD, MOUNTAIN, PASTURE, FOREST, HILLS}.
                    getNumber();
                    ss << "|Forest   " << setw(2) << number << "|";         // Second Row of Card. Inlcudes biome and the number which are stored in string stream.
                                                                            // "setw(2)" is used for formatting the digits to account for 2 digits numbers like 10, 11, 12
                    break;
                case HILLS:
                    getNumber();
                    ss << "|Hills    " << setw(2) << number << "|";
                    break;
                case FIELD:
                    getNumber();
                    ss << "|Field    " << setw(2) << number << "|";
                    break;
                case PASTURE:
                    getNumber();
                    ss << "|Pasture  " << setw(2) << number << "|";
                    break;
                case MOUNTAIN:
                    getNumber();
                    ss << "|Mountain " << setw(2) << number << "|";
                    break;
                default:
                    return "|           |";
                    break;
            }
            return ss.str();        // Returns the String Stream.
        case 2: return "|           |";
        case 3: return "|           |";        // There is two dashes on the right side because that is the only the backshash would work like one slash.
        case 4: return "|           |";        // It will not affect the way the board looks. One of the slashes will disappear
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
                break;
        default:
            return "";
    }
}

string Tile::renderSettlement1(int line){       // Player 1's settlement is rendered
    stringstream ss;
    string temp = getPlayer1Name();
    if (temp.length() > 11) {       // If the players name is too long, then it must be resized to fit in the tile
        temp.resize (11);    
    }
    switch(line){
        case 0: return ".___________.";             // First Row of Card
        case 1:
            biome = biomeType(rand() % LAST);       // This randomizes the biomes from the first biome to the last. "LAST" is used becuase when you use the % operator 
                                                    // it does not include the last enumeration element. Therefore, another enumeration element had to be added so that 
                                                    // all desired biomes would be included in the randomizer.
            
            switch(biome){
                case FOREST:                        // Each card has a type, the "[field]" should be replaced by an enum BiomeType{FIELD, MOUNTAIN, PASTURE, FOREST, HILLS}.
                    getNumber();                    // Recieve random number for tile
                    biomeNum = 0;                   // Record the BIOME of the settlement tile
                    location1 = number;             // Records the NUMBER of the settlement tile
                    ss << "|Forest   " << setw(2) << number << "|";         // Second Row of Card. Inlcudes biome and the number which are stored in string stream.
                                                                            // "setw(2)" is used for formatting the digits to account for 2 digits numbers like 10, 11, 12
                    break;
                case HILLS:
                    getNumber();
                    biomeNum = 1;
                    location1 = number;
                    ss << "|Hills    " << setw(2) << number << "|";
                    break;
                case FIELD:
                    biomeNum = 2;
                    getNumber();
                    location1 = number;
                    ss << "|Field    " << setw(2) << number << "|";
                    break;
                case PASTURE:
                    getNumber();
                    biomeNum = 3;
                    location1 = number;
                    ss << "|Pasture  " << setw(2) << number << "|";
                    break;
                case MOUNTAIN:
                    getNumber();
                    biomeNum = 4;
                    location1 = number;
                    ss << "|Mountain " << setw(2) << number << "|";
                    break;
                default:
                    return "|           |";
                    break;
            }
            return ss.str();                    // Returns the String Stream.
        case 2: return "|     __    |";         // There is two dashes on the right side because that is the only the backshash would work like one slash.
        case 3: return "|    /  \\   |";        // It will not affect the way the board looks. One of the slashes will disappear
        case 4: return "|    |__|   |";
        case 5: return "|           |";
        case 6: ss.str("");
                ss <<  "|" << setw(11) << setfill(' ') << right << temp << "|";     // Takes data from the string stream and outputs it in a desired format
                return ss.str();
        case 7: return "|___________|";
                break;
        default:
            return "";
    }
}

/* Settlement 2 has not been properly adjusted to take turn as a take turn function for player 2 has not been made yet */

string Tile::renderSettlement2(int line){
    stringstream ss;
    string temp = getPlayer2Name();
    if (temp.length() > 11) {
        temp.resize (11);    
    }
    switch(line){
        case 0: return ".___________.";     // First Row of Card
        case 1: biome = biomeType(rand() % LAST);   // This randomizes the biomes from the first biome to the last. "LAST" is used becuase when you use the % operator 
                                                    // it does not include the last enumeration element. Therefore, another enumeration element had to be added so that 
                                                    // all desired biomes would be included in the randomizer.
            
            switch(biome){
                case FOREST:       // Each card has a type, the "[field]" should be replaced by an enum BiomeType{FIELD, MOUNTAIN, PASTURE, FOREST, HILLS}.
                    getNumber();
                    ss << "|Forest   " << setw(2) << number << "|";         // Second Row of Card. Inlcudes biome and the number which are stored in string stream.
                                                                            // "setw(2)" is used for formatting the digits to account for 2 digits numbers like 10, 11, 12
                    break;
                case HILLS:
                    getNumber();
                    ss << "|Hills    " << setw(2) << number << "|";
                    break;
                case FIELD:
                    getNumber();
                    ss << "|Field    " << setw(2) << number << "|";
                    break;
                case PASTURE:
                    getNumber();
                    ss << "|Pasture  " << setw(2) << number << "|";
                    break;
                case MOUNTAIN:
                    getNumber();
                    ss << "|Mountain " << setw(2) << number << "|";
                    break;
                default:
                    return "|           |";
                    break;
            }
            return ss.str();        // Returns the String Stream.
        case 2: return "|     __    |";        // There is two dashes on the right side because that is the only the backshash would work like one slash.
        case 3: return "|    /  \\   |";        // It will not affect the way the board looks. One of the slashes will disappear
        case 4: return "|    |__|   |";
        case 5: return "|           |";
        case 6: ss.str("");
                ss << "|" << setw(11) << setfill(' ') << right << temp << "|";
                return ss.str();
        case 7: return "|___________|";
                break;
        default:
            return "";
    }
}

