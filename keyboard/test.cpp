#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <igloo/igloo.h>
#include "../wordle/modify_stats.h"
#include <main.cpp>
using namespace igloo;

Context(Status_Zero){
    Spec(A){

        int gameState = 0;

        std::string expected = "Please launch the wordle game.";
        read_stats(Stats);
        Assert::That(words, Equals(expected));
    }
};
Context(Status_One){
    Spec(B){
        int gameState = 1;
        std::string expected = "Waiting for Wordle game round to start.";
        read_stats(Stats);
        Assert::That(words, Equals(expected));
    }
};
Context(Status_Two){
    Spec(C){
        int gameState = 2;
        std::string expected = "---";
        read_stats(Stats);
        Assert::That(words, Equals(expected));
    }
};
   
int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
