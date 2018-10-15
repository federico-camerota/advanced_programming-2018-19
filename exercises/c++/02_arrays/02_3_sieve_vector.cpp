#include <iostream>
#include <cmath>
#include <vector>

int main(){

    unsigned n;
    std::cout << "Insert max number: ";
    std::cin >> n;
    if (std::cin.fail()){
    
        std::cerr << "error: invalid input" << std::endl;
        exit(1);
    }
    std::vector<bool> primes (n, true);
    primes.at(0) = false;
    for (unsigned j = 1; j + 1 < std::sqrt(n); j++){
    
        if (primes.at(j)){
        
            for (unsigned k = (j+1)*(j+1); k <= n; k+= (j+1))
                primes.at(k-1) = false;
        }
    }
    for (unsigned i = 0; i < n; i++)
        if (primes.at(i))
            std::cout << i + 1 << std::endl;
}
