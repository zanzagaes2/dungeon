#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

void checkGuess (int, int, int);
void askForNumber (int, int&);

int main () {
    int numberToGuess;
    std::cout << "Input a number to guess";
    std::cin >> numberToGuess;

    int attempt;
    bool guessTooHigh; //Equals 0 if attempt < numberToGuess
                    // Equals 1 if attempt > numberToGuess
    bool guessed;
    int minNumber = 0;
    int maxNumber = 1000;  // Upper bound of number

    while (true) {
        attempt = (minNumber+maxNumber)/2;
        std::cout << "Guessing attempt: " << attempt << std::endl;
        guessed = attempt == numberToGuess;
         
        if (guessed) {
            std::cout << "Guessed!!!";
            exit(1);
        }

        guessTooHigh = attempt > numberToGuess;
        if (guessTooHigh) { 
            maxNumber = attempt;
            std::cout << "The guess is too low" << std::endl << std::endl;
        }
        else { 
            minNumber = attempt;
            std::cout << "The guess is too high" << std::endl << std::endl;
        }
    } 
}

