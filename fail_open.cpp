#include <iostream>
#include <fstream>

int main () {
    std::ifstream failInputFile;
    failInputFile.open("Existent.file");
    std::ios_base::iostate stateIO = failInputFile.rdstate(); //puede comprobarse como 
                                                             //if (failInputFile.rdstate()). 
                                                             //rdstate devuelve 0 si no ha habido ningún error.
    std::cout << "EstadoIO: " << stateIO << std::endl;
    std::cout << "EstadoIO: " << bool(failInputFile) << std::endl;

    return 1;
}

// Retorno del programa:
// EstadoIO = 4
