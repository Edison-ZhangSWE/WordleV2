#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <fstream>
#include <vector>
#include "keyboardprint.h"

using namespace std;

int main(int argc, char* argv[]) {
    int gameState = 0;
    int prev_gamestate;
    string line;
    vector <string> colorOptions = {BLACK, YELLOW, GREEN, RESET};
    vector <vector<string>> colors;
    vector <vector<string>> prev_colors = {{RESET}};
    vector <vector<char>> keyboard = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}, {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'}, {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};

    while(true) {
        ifstream file("../wordle/stats.txt");
        if (file.is_open()){
            file >> gameState;
        if (gameState == 0){ //wordle is not running
            if (prev_gamestate != gameState){
                system("clear");
                cout << "Please launch the Wordle game." << endl;
                ofstream file2("../wordle/keyboard.txt", ios::trunc);
                file2.close();
                prev_gamestate = gameState;
                prev_colors = {{RESET}};
            }
        }
        else if (gameState == 1){ // Wordle is running, but not in game
            if (prev_gamestate != gameState){
                system("clear");
                cout << "Waiting for Wordle game round to start." << endl;
                ofstream file2("../wordle/keyboard.txt", ios::trunc);
                //truncrefreshes the keyboard, before every game
                //reading the keyboard.txt file in wordle
                file2.close();
                prev_gamestate = gameState;
                prev_colors = {{RESET}};

            }
        }
        else { // wordle is currently in game
            prev_gamestate = gameState;
            colors.clear();
            for (vector<char> row : keyboard){
                colors.push_back({});
                for (char c : row){
                    ifstream file2("../wordle/keyboard.txt");
                    colors.back().push_back(colorOptions[3]); //colorsoption?
                    if (file.is_open()){ // 3 different color options
                        for (int i = 0; i<3; i++){ // displaying the keyboard
                        // of the current game
                            getline(file2, line);
                            if (line.find(c) != string::npos) colors.back().back() = colorOptions[i];
                        }
                    }
                    else cerr<< "Error: file could not be opened." << endl;
                }
            }
            if (prev_colors != colors) {
                system("clear");
                printKeyboard(keyboard, colors);
                prev_colors = colors;
            }
        }
    }
            else cerr<< "Error: file could not be opened." << endl;
                file.close();
    }
    return 0;
    }

