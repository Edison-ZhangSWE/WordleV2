#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <igloo/igloo.h>
#include <wordle.h>

using namespace igloo;

Context(Wordle){
    Spec(FourLetterWord_PartiallyCorrect){
        std::string guess = "dunk";
        std::string answer = "dark";
        std::vector<string> color = guessColors(guess, answer, 4);
        std::vector<std::string> expected = {GREEN, BLACK, BLACK, GREEN};
        Assert::That(color, Equals(expected));
    }
};
Context(Wordle){
    Spec(EightLetterWord_Correct){
        std::string guess = "concrete";
        std::string answer = "concrete";
        std::vector<string> color = guessColors(guess, answer, 8);
        std::vector<std::string> expected = {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN};
        Assert::That(color, Equals(expected));
    }
};
Context(Wordle){
    Spec(FiveLetterWord_IncorrectPlace){
        std::string guess = "shake";
        std::string answer = "shark";
        std::vector<string> color = guessColors(guess, answer, 4);
        std::vector<std::string> expected = {GREEN, GREEN, GREEN, YELLOW, BLACK};
        Assert::That(color, Equals(expected));
    }
};
Context(Wordle){
    Spec(FiveLetterWord_SameLetterDifferentPlace){
        std::string guess = "ample";
        std::string answer = "eagle";
        std::vector<string> color = guessColors(guess, answer, 4);
        std::vector<std::string> expected = {YELLOW, BLACK, BLACK, GREEN, GREEN};
        Assert::That(color, Equals(expected));
    }
};
   
int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
