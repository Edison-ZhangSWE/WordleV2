#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <vector>

void printTopScreen(std::string COLOR) {
    std::cout << COLOR << " --- " << RESET;
    }
void printMiddleScreen(char c, std::string COLOR) {
    std::cout << COLOR << "| " << c << " |" << RESET;
    }
void printBottomScreen(std::string COLOR) {
    std::cout << COLOR << " --- " << RESET;
    }
void printScreen(std::vector<std::string> guesses, std::string answer, std::string gameState, std::vector<std::vector<std::string>> colors, int Number_of_Letters){
    system("clear");

for (int i = 0; i<guesses.size(); i++){ // loops through our guesses
    for (int j = 0; j<Number_of_Letters; j++){
        printTopScreen(colors[i][j]); // prints the top of the header with our specified color
}
std::cout << std::endl;
for (int j = 0; j<Number_of_Letters; j++){
    printMiddleScreen(guesses[i][j], colors[i][j]); // prints the middle part, with the array index of our guess
    // array of an array because there are multiple guesses and multiple letters in a guess. same for colors
}
std::cout << std::endl; 
for (int j = 0; j<Number_of_Letters; j++){
    printBottomScreen(colors[i][j]);
}
std::cout << std::endl;
}   
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
// VICTORY SCREEN
if (gameState == "win"){
std::cout << std::endl;
std::cout << "Splendid!" << std::endl;
std::cout << std::endl;
std::cout << "Press [enter] to continue";
}
// DEFEAT SCREEN
else if (gameState == "lose"){
std::cout << std::endl;
std::cout << "The word was: " << answer << std::endl;
std::cout << std::endl;
std::cout << "Better luck next time!" << std::endl;
std::cout << std::endl;
std::cout << "Press [enter] to continue";
}
}
#endif