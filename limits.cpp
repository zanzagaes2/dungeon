#include <climits>
#include <iostream>

int main() {
    std::cout << "\t\tMínimo\tMáximo" << std::endl;
    
    int tipos[6] = {CHAR_MIN, CHAR_MAX, SHRT_MIN, SHRT_MAX, INT_MIN,
                    INT_MAX};

    // Printing Strings stored in 2D array
    for (int i = 0; i < 6; i++)
        std::cout << tipos[i] << std::endl; 

    return 1;
}
