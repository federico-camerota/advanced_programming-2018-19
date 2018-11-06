#include <iostream>
#include <vector>

int main(){

    std::vector<double> a{1,2,3,4,5,6};
    std::cout << (++(a.end()) == a.begin()) << std::endl;
    return 0;
}
