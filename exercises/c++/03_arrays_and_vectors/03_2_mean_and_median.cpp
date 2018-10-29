#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

double  mean (const std::vector<double> &);
double median (const std::vector<double> &);

int main (int argc, char *argv[]){

    std::vector<double> values;
    double read;
    if ( argc > 1){

        std::ifstream input_file;
        input_file.open(argv[1]);
        if (!input_file){
        
            std::cerr << "error: " << argv[1] << " is not a valid filename" << std::endl;
            exit(1);
        }
        while (input_file >> read)
            values.push_back(read);
        input_file.close();
    }
    else{
    
        while (std::cin >> read)
            values.push_back(read);
    }
    if (values.size() > 0){
        std::cout << "The mean is " <<  mean(values) << std::endl;
        std::cout << "The median is " << median(values) << std::endl;
    }
}


double  mean (const std::vector<double> &vect){

    double sum = 0;
    for (const double x : vect)
        sum += x;
    return sum/vect.size();
}

double median (const std::vector<double> &vect){

    std::sort(vect.begin(), vect.end());
    if (vect.size()%2 == 0)
        return (vect.at(vect.size()/2) + vect.at(vect.size()/2 - 1))/2;
    else
        return vect.at(vect.size()/2);
}

