#include <iostream>
#include <vector>

bool prime_check(int, std::vector<int> &);

int main(){

    std::vector<int> primes;
//    std::cout << "allocated size: " << primes.capacity() << std::endl;
    primes.push_back(2);
//    std::cout << "allocated size after first insertion: " << primes.capacity() << std::endl;
    for (int i = 3; i <= 100; i+= 2){
    
        if (prime_check(i, primes))
            primes.push_back(i);
        
    }
    for (int i = 0; i < primes.size(); i++)
        std::cout << primes.at(i) << std::endl;
}


bool prime_check(int num, std::vector<int> &primes){

   if  (primes.size() == 0U)
       return true;
   else{
   
       unsigned i = 0U;
       while (i < primes.size()){
       
           if (num % primes.at(i++) == 0)
               return false;
       }
       return true;
   }
}

