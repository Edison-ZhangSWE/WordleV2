//Calculate the variables for the stats
// modifies based on the round


//after each iteration of the program,
// TimesPlayed++;
// averageAttempts = (int)reduce(AttemptsVec.begin(), AttemptsVec.end()) / TimesPlayed; // #include <numeric>
// winPercentage = (float)wins / (float)TimesPlayed // #include <iomanip>
// winPercentage.setprecision(2);
// if (win == true){ // MAKE SURE TO USE A BOOLEAN CALLED WIN
//     currentStreak++;
//     if(currentStreak > longestStreak){
//         longestStreak = currentStreak;
//     }
// }
// elif (win == false){
//     currentStreak = 0;
// }
// }
// }
#ifndef MODIFY_STATS_H
#define MODIFY_STATS_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>

void read_stats(Stats& stats) {
    std::ifstream file("stats.txt");
    if (file) {// if the file exists 
    // within this file, we store multiple variables
    // times played, vector of attempts (used to calculate avg attempts), amount of wins(divide by num of games), streak
    // longest streak 
        stats.Words.clear();
        stats.Attempts.clear();
        stats.Wins.clear();
        file >> stats.gameState
             >> stats.timesPlayed
             >> stats.averageAttempts
             >> stats.winPercentage
             >> stats.currentStreak
             >> stats.longestStreak;
             std::string line;
             getline(file, line);
        while (getline(file, line)) {
            std::istringstream iss(line); // this istringstream command stores the variables into a line
            std::string word, win;
            int attempt; // changes the vars on the txt file, with a \n
            iss >> word >> attempt >> win;
            
            stats.Words.push_back(word);
            stats.Attempts.push_back(attempt);
            stats.Wins.push_back(win);
        }
        stats.gameState = 1;
    } 
    else {
        std::cerr << "Error: Could not open file.\n";
    }
    }


void modify_stats(Stats& stats){ // & lets us change the real variables
    std::ofstream file("stats.txt", std::ios::trunc); // ofstream takes a file, and rewrites the data instead
    //we will use this to hold our stats, and update our variables (while reading it with the previous function)
    if (file.is_open()){
        int numWins = 0, attemptSum = 0, currentStreak = 0, longestStreak = 0;
        for (std::string win : stats.Wins){
            if (win == "Yes"){
                numWins++, currentStreak++;
                if (currentStreak > longestStreak) longestStreak = currentStreak;
            }  
            else currentStreak = 0;//this means that t was a loss
            }
    
        for (int i : stats.Attempts) attemptSum += i; 
            stats.timesPlayed = stats.Words.size();
            stats.averageAttempts = stats.timesPlayed ? attemptSum/stats.Attempts.size() : 0; 
            // if its true, it will give the number, if its false it will give 0.
            stats.winPercentage = stats.timesPlayed ? ((float)numWins/stats.Wins.size()) * 100 : 0;
            // same concept, but will give the win percentage if true.
            stats.currentStreak = currentStreak, stats.longestStreak = longestStreak;
            file << stats.gameState << ' ' << stats.timesPlayed << ' ' << stats.averageAttempts << ' ' << stats.winPercentage << ' ' << stats.currentStreak << ' ' << stats.longestStreak << '\n';
            for (int i = 0; i< stats.Words.size(); i++){
                file << stats.Words[i] << ' ' << stats.Attempts[i] << ' ' << stats.Wins[i] << '\n';
            }
            file.close();
        }
        else std::cerr << "Error: Could not open file." << std::endl;
        }
        void ResetStatsFile() {
            std::ofstream file("stats.txt", std::ios::trunc); //clears the files
            if(file.is_open()){
                file << "1 0 0 0 0 0"; 
                //1 is game state, 2 is timesPlayed, 3 is Attempts, 4 is winPercentage, 5 is currentStreak, 6 is 
                // longestStreak.
                file.close();
            }
            else std::cerr << "Error: Could not open file." << std::endl;     
        }
        #endif        





