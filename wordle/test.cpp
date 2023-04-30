#include <igloo/igloo.h>

using namespace igloo;

Context(Wordle){
    Spec(LongWords){
        std::string a = "flabbergasted";
        randomWordle(a);
        std::string actual = "";
        Assert::That(a, Equals(actual));
    }

    Spec(RepeatedLetters){
        std::string a = "eagle";
        randomWordle(a);
        std::string actual = "eagle"
        Assert::That(a, Equals(actual));
    }

    Spec(EmptyInput){
        std::string a = "";
        randomWordle(a);
        std::string actual = "";
        Assert::That(a, Equals(actual));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
