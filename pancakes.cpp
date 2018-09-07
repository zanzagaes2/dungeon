#include <iostream>

struct Eater {
        int number;
        int pancakes;
    };

void insertionSort ( Eater (&)[10] );

int main () {
        Eater eaters[10];
    for (int i=0; i<10; i++) {
        Eater eater;
        eater.number = i+1;
        std::cout << "¿Cuantos pancakes comió " << eater.number << "?: ";
        std::cin >> eater.pancakes;
        std::cout << std::endl;
        eaters[i] = eater; 
    }
    
    for (int i=1; i<10;i++) {
        std::cout << eaters[i].number << " comió " << eaters[i].pancakes << " pancakes." << std::endl;
    }
    insertionSort(eaters);
    for (int i=1; i<10;i++) {
        std::cout << eaters[i].number << " comió " << eaters[i].pancakes << " pancakes." << std::endl;
    }
}

void insertionSort (Eater (&eaters)[10]) {
    for (int i = 0; i<10; i++) {
        for (int j=i; j>0; j--) {
            if (eaters[j-1].pancakes > eaters[j].pancakes) {
                Eater tmp = eaters[j-1];
                eaters[j-1] = eaters[j];
                eaters[j] = tmp;
                  }
        }
    }
}
