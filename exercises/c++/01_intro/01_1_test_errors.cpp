#include <iostream>
#include <string>

void new_line();

/*Tests the compile time effect of different kinds of errors*/
int main(){

    //int double = 1234;
    //int double{1235};
    //std::string text= "hello, world!"
    std::string text= "hello, world!";
    //std::cotu << text;
    //std::cout << Text_wrong;
    std::cout << text;
    new_line(text);
    return 0;
}

void new_line(){

    std::cout << "\n";
}
