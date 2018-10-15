#include <iostream>

bool prime_check(int, int *, int);
int *rescale_array(int *, int *);

/*The array size is initialized to 10 and then
 * when full the size is doubled
 */
int main(){

    int *primes{new int[10]};
    int elems, size;
    elems = 1;
    size = 10;
    primes[0] = 2;
    for (int i = 3; i <= 100; i+= 2){
    
        if (prime_check(i, primes, elems)){
        
            if (elems == size)
                primes = rescale_array(primes, &size);
            primes[elems++] = i;
        }
    }
    for (int i = 0; i < elems; i++)
        std::cout << primes[i] << std::endl;
    delete[] primes;
}


int *rescale_array(int *a, int *size){

    *size = 2*(*size);
    int *new_array{new int[*size]};
    for (int i = 0; i < *size; i++)
        new_array[i] = a[i];
    delete[] a;
    return new_array;

}
bool prime_check(int num, int *primes, int size){

   if  (size == 0)
       return true;
   else{
   
       int i = 0;
       while (i < size){
       
           if (num % primes[i++] == 0)
               return false;
       }
       return true;
   }
}

