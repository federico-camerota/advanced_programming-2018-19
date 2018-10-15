#include <iostream>

int get_int();
double get_double();

/*Reads an integer and a double from stdin and prints it to
 * stdout
 */
int main(){

    std::cout << "Insert an integer: " ;
    int i = get_int();
    std::cout << "entered int: " << i << std::endl;
    std::cout << "Insert a double: " ;
    double d = get_double();
    std::cout << "entered double: " << d << std::endl;
}
int get_int(){

    int i;
    while(!(std::cin >> i)){
        std::cin.clear();
        std::cin.ignore();
    }
    return i;
}


double get_double(){

    double d;
    while(!(std::cin >> d)){
    
        std::cin.clear();
        std::cin.ignore();
    }
    return d;
}

