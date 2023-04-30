#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <vector>

using namespace std;
    struct Stats{
        int gameState, timesPlayed, averageAttempts, winPercentage, currentStreak, longestStreak;
        vector<string> Words, Wins;
        vector<int> Attempts;
    };

    #include "wordle.h"
    #include "modify_stats.h"
    #include "menu_screen.h"
    #include "stats_screen.h"
    #include "tutorial_screen.h"
   

    int main(int argc, char* argv[]) {
        if (argc != 4){
            cout << "Invalid number of arguments." << endl;
            exit(0);
        }
        vector<int> listOfNumbers_in_Texts = {2267, 3937, 6881, 8913, 9023};
        Stats stats;
        string user_option;
        int Number_of_Letters = std::stoi(argv[1]);
        string AllowedGuesses_words_file_name = argv[3];
        string Possible_words_file_name = argv[2];

        system("clear"); // reading the stats and printing the menu screen
        read_stats(stats);
        modify_stats(stats);
        print_menu_screen();


        while (cin >> user_option){ // makes sure that the user's input is within the parameters of 1-5.
            cin.ignore(); //51234
            if (user_option == "5"){ // exits the wordle game, updates the game state so the keyboard knows
                stats.gameState = 0;
                modify_stats(stats);
                system("clear");
                break;
            }
            else if (user_option == "1"){ // starts a game, updates the stats file before the game ends
                system("clear");
                stats.gameState = 2;
                modify_stats(stats);
                startGame(stats, Possible_words_file_name, AllowedGuesses_words_file_name, Number_of_Letters, listOfNumbers_in_Texts);
                stats.gameState = 1;
                modify_stats(stats);
            }
            else if (user_option == "2"){ // prints out tutorial screen
                while (!user_option.empty()){
                    system("clear");
                    print_Tutorial_screen();
                    getline(cin, user_option);
                }
            }
            else if (user_option == "3"){ // prints out stats screen
                while (!user_option.empty()){
                    system("clear");
                    print_stats_screen(
                        stats.timesPlayed, 
                        stats.averageAttempts, 
                        stats.winPercentage, 
                        stats.currentStreak, 
                        stats.longestStreak, 
                        stats.Words, 
                        stats.Attempts, 
                        stats.Wins,
                        Number_of_Letters);
                    getline(cin, user_option);
                }
            }
            else if (user_option == "4"){ // Resets stats file (stats.txt) and prints out stats screen.
                ResetStatsFile();
                read_stats(stats);
                while (!user_option.empty()){
                    system("clear");
                    print_stats_screen(
                        stats.timesPlayed, 
                        stats.averageAttempts, 
                        stats.winPercentage, 
                        stats.currentStreak, 
                        stats.longestStreak, 
                        stats.Words, 
                        stats.Attempts, 
                        stats.Wins,
                        Number_of_Letters);
                    getline(cin, user_option);
                }
            }
            
            system("clear");
            print_menu_screen();
        }

    return 0;
}


/* First step 
    to check if the word is in the list of allowed text            !=string::npos
    second step
    to check letter by letter to see if its in the word (make a separate variable, remove the letter from this temp variable
    if it is in the word. dont do anything if it isnt)
    if it is, check if that index has the index of the word. for instance, if u guessed frink and the word was flirt,
    the f will be checked against index 0 of the real word. if it is correct, it lights green. if not, make it yellow (because
    we only reach this check if the letter is in the word anyway.)

    unit tests: 
    Testing word that isnt in allowed.txt
    Invalid INputs: Testing 4 Letter word / Symbols that aren't letters 
    Testing Word with multiple letters, for instance Speed (if they guess 3 Es, only the first two should be colored)

*/