#include <fstream>
#include <iostream>
#include <string>

int main(){
    std::ifstream inFile; 
    std::ofstream outFile;
    int number1;
    int number2;
    std::string string1;

    inFile.open("indata.in");
    outFile.open("outdata.out");
    inFile >> number1 >> number2 >> string1;
    outFile << string1 << number2 << number1;
    std::cout << "Hey";
}
