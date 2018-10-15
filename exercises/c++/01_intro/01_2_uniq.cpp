#include <iostream>
#include <string>


/*Reads lines from stdin and collapses repeated lines into a single one
 * adding a counter for the number of repetitions
 */
int main(){

    std::string prevline, line;
    bool first = true;
    int counter = 0;

        /* In this case a while loop seems more appropriate since
         * we do not know how many lines we will have to process
         */
        while (std::getline(std::cin,line)){
    
            if (first){
                prevline = line;
                first = false;
            }
            if (line == prevline)
               counter++; 
            else{
            
                std::cout << counter << " " << prevline << std::endl;
                counter = 1;
                prevline = line;
            }
        }

    std::cout << counter << " " << prevline << std::endl;
}
