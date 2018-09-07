#include <iostream>
#include <string>

int main(){
    std::string var1 = "er";
    char var2;
    var2 = char(var1[0]);
    std::cout << var2;
    std::cout << int(var2);

}
