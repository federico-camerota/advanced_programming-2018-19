#include "linked_list.h"
#include <string>
#include <iostream>

using namespace mylib;

int main(){

    LinkedList<std::string> list1;
    list1.push_back("string3");
    std::string s1{"string4"};
    list1.push_back(s1);
    list1.push_front("string2");
    s1 = "string1";
    list1.push_front(s1);
    std::cout << "list1:\n" << list1;

    LinkedList<std::string> list2 = list1;
    /**
     * LinkedList<std::string> list2{list1};
     * same as the previous one, both call LinkedList (const LinkedList<T>&).
     * Would expect LinkedList() and then operator= (const LinkedList<T>&) from the previous one
     * compiler optimization?
     */
    for (auto& x : list2)
	x = "new_" + x; //modifies list2 contents but not list1, deep copy.
    std::cout << "list1:\n";
    std::cout << list1;
    std::cout << "list2:\n";
    std::cout << list2;
    LinkedList<std::string> list3 = std::move(list1);//list1 no more in a valid state
    std::cout << "list3:\n";
    std::cout << list3;
    list2 = list3; //force use of operator= both with copy and move semantics.
    std::cout << "list2:\n";
    std::cout << list2;
    std::cout << "list1:\n";
    std::cout << list1; // NO WARNING! Head is set to null since list3 head was (good reason to
			// call always LinkedList() in constructors that not set directly head and 
			// tail, if left uninitialized may be pointing to random memory positions)
			// Q: in case of non pointer members, null object pattern could be a good
			//    idea?
    

    
    const LinkedList<std::string> list4{list2};
    //should produce errors:
    //error: list4.push_back("string5");
    //std::string s3{"string6"};
    //error: list4.push_back(s3);
    //error: list4.push_front("string0");
    //s3 = "string-1";
    //error: list4.push_front(s3);
    //should work:
    std::cout << "list4:\n" << list4;

    LinkedList<std::string> list5("temporary initializing string");
    std::cout << "list5:\n" << list5;
    std::string s4{"lvalue initializing string"};
    LinkedList<std::string> list6(s4);
    std::cout << "list6:\n" << list6;


//    const LinkedList<std::string> constList{list4};
//    //The following line calls no constructor (???)
//    LinkedList<std::string>::iterator<std::string> b{constList.begin()}
//    *b="changed content";//problem here
//    std::cout << "constList:\n" << constList;

    return 0;
}
