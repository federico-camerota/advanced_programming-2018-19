#include <iostream>
#include <string>

/*Reads a value and it unit from stdin and converts it
 * to it equivalent SI unit of measure.
 */
int main(){

    std::string unit;
    double value;

    std::cin >> value >> unit;
    if (std::cin.fail()){
        std::cerr << "usage: si_converter <value> <unit>" << std::endl;
        return 1;
    }
    else{
        
        if (unit == "inch"){
            value *= 0.0254;
            std::cout << value << " m" << std::endl;
        }
        else if (unit == "ft"){
        
            value *= 0.3048;
            std::cout << value << " m" << std::endl;
        }
        else if (unit == "gal"){
        
            value *= 3.8;
            std::cout << value << " l" << std::endl;
        }
        else if (unit == "mi"){
        
            value *= 1.609344*1000;
            std::cout << value << " m" << std::endl;
        }
        else if (unit == "oz"){

            value *= 28;
            std::cout << value << " g" << std::endl;
        } 
        else{
            std::cerr << "error: " << unit << " is not a valid unit measure (inch|ft|oz|gal|mi)" << std::endl;
            return 2;
        }
    }
    return 0;
}
