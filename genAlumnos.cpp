#include <iostream>
#include <fstream>
#include <random>

int main () {
    // Nº Nota1 Nota2 Nota3
    std::ofstream outFile;
    outFile.open("alumnos.dat");

    int numAlumnos = 50;
    for (int x = 0; x < numAlumnos; x++) {
        int numAlumno = x;
        int nota1 = std::rand() % 10;
        int nota2 = std::rand() % 10;
        outFile << numAlumno << " " << nota1 << " " << nota2 << std::endl;
    } 

}
