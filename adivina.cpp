#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

void checkGuess (int, int, int);
void askForNumber (int, int&);

int main () {
    const int maxNumber = 1000;  // Upper bound of number
    std::srand (std::time(0));
    int numberToGuess = std::rand() % maxNumber;
    int userGuess;

    while (true) {
        askForNumber (maxNumber, userGuess);
        checkGuess (numberToGuess, userGuess, maxNumber);
    }
    
}

void checkGuess ( /* in */ int numberToGuess,  // Number that must be guessed.
            /* in */ int attemptedNumber,   // User attempt to guess 
            /* in */ int maxNumber)     // Maximum possible number

    // Tells user if their attempt is higher or lower than the number to guess.
    // If the user has given the correct number, the program ends with a
    // greeting message
    //
    // Precondition: attemptedNumber in (1, maxNumber)
    // Poscondition: User knows if attemptedNumber is greater, lower or equal
    // than numberToGuess
{
    if ( attemptedNumber > numberToGuess ) 
    {
        std::cout << "Lower!" << std::endl << std::endl;
        return;
    }
    else if ( attemptedNumber < numberToGuess )
    {
        std::cout << "Higher!" << std::endl << std::endl;
        return;
    }
    else {
        std::cout << "Congratulations." << std::endl << std::endl;
        exit(1);
    }
} 

void askForNumber ( /* in */ int maxNumber, //Maximum possible number
                   /* inout */ int& attemptedNumber)
    // Precondition: maxNumber > 0. 
    // Poscondition: attemptedNumber in (1, maxNumber) 
{
    std::cout << "Please provide a number from 1 to " << maxNumber << std::endl;
    std::cout << "Number: ";
    std::cin >> attemptedNumber;
    return;
}
