#include <iostream>
#include "Date.h"

int main(){

    Date today{25, month_type::FEB, 2016};
    Date otherday{25, month_type::DEC, 2018};

    for (int i = 0; i < 15; i++){
    
        today.add_days(1);
        std::cout << today.day() << " " << int(today.month()) << " " << today.year() << std::endl;
    }
    //std::cout << today << std::endl;
    //std::cout << otherday << std::endl;
    //std::cout << (today == otherday) << std::endl;
}
