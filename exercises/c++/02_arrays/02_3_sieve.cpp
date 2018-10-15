#include <iostream>
#include <cmath>

int main(){

    int n;
    std::cout << "Insert max number: ";
    std::cin >> n;
    if (std::cin.fail()){
    
        std::cerr << "error: invalid input" << std::endl;
        exit(1);
    }
    bool *primes{ new bool[n]};
    primes[0] = false;
    for (int i = 1; i < n; i++)
        primes[i] = true;
    for (int j = 1; j + 1 < std::sqrt(n); j++){
    
        if (primes[j]){
        
            for (int k = (j+1)*(j+1); k <= n; k+= (j+1))
                primes[k-1] = false;
        }
    }
    for (int i = 0; i < n; i++)
        if (primes[i])
            std::cout << i + 1 << std::endl;

    delete[] primes;
}
