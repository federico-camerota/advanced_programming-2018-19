#include "revert_array.hpp"
#include <iostream>

int main(){

    int ia_size, da_size, *ia;
    double *da;
    std::cout << "Insert the int array size: ";
    std::cin >> ia_size;
    if (std::cin.fail()){
        std::cerr << "error: invalid int array size" << std::endl;
        exit(1);
    }
    ia = read_array<int>(ia_size);
    if (ia == NULL){
        std::cerr << "error: invalid elements passed" << std::endl;
        exit(2);
    }
        
    std::cout << "Insert the double array size: ";
    std::cin >> da_size;
    if (std::cin.fail()){
        std::cerr << "error: invalid double array size" << std::endl;
        delete[] ia;
        exit(1);
    }
    da = read_array<double>(da_size);
    if (da == NULL){
        std::cerr << "error: invalid elements passed" << std::endl;
        delete[] ia;
        exit(2);
    }
    std::cout << "Integer array:" << std::endl;
    print_reverted(ia, ia_size);
    std::cout << "Double array:" << std::endl;
    print_reverted(da, da_size);

    delete[] ia;
    delete[] da;

}

template <typename T>
T *read_array(const int size){

    T* a{new T[size]};

    for(int i = 0; i < size; i++){
    
        std::cout << "Insert the next element: ";
        std::cin >> a[i];
        if (std::cin.fail()){
            delete[] a;
            return NULL;
        }
    }

    return a;
}

template <typename T>
void print_reverted(T *array, int size){ 
    for (int i = size - 1; i >= 0; i--)
        std::cout << i << ": " << array[i] << std::endl;
}
