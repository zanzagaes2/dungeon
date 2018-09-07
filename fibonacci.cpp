#include <iostream>
#include <stdlib.h>

int main (int argc, char *argv[]) {
   int maximo =  atoi (argv[1]);
   int numeroFibonnaci = 1;
   int numero1 = 1;
   int numero2 = 1; 
   while (true) {
       numeroFibonnaci = numero1 + numero2;
       numero1 = numero2;
       numero2 = numeroFibonnaci;
       if (numeroFibonnaci > maximo) {
           break;
       }
       std::cout << numeroFibonnaci << std::endl;
   }


}
