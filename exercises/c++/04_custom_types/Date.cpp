//: Date.cpp

#include "Date.h"
#include <iostream>

/*
 * Date custom constructor
 */
Date::Date (unsigned day, month_type month, unsigned year) :
    d{day},
    m{month},
    y{year}
{}

/*
 * Return date day 
 */
unsigned Date::day() const {

    return d;
}
/*
 * Return date month
 */
month_type Date::month() const{
        
    return m;
}
/*
 * Return date year
 */
unsigned Date::year() const{

    return y;
}
/*
 * Add n days to a date
 */
void Date::add_days( const unsigned n){

    for (unsigned i = 0; i < n; i++)
        add_day();
}
/*
 * add_day function, adds a single day to a Date
 */
void Date::add_day(){

   d++;
   switch(m){
   
       case month_type::JAN:
       case month_type::MAR:
       case month_type::MAY:
       case month_type::JUL:
       case month_type::AUG:
       case month_type::OCT:
       case month_type::DEC:
            if (d > 31){
                d = 1;
                ++m;
                if (m == month_type::JAN)
                    y++;
            }
            break;
        case month_type::FEB:
            if (is_leap(y) ? d > 29 : d > 28){
                d = 1;
                ++m;
            }
            break;
        default:
            if (d > 30){
            
                d = 1;
                ++m;
            }
   } 
}





/*
 * Helper functions
 */
bool operator==( const Date& lhs, const Date& rhs){

    return (lhs.year() == rhs.year()) && (lhs.month() == rhs.month()) && (lhs.day() == rhs.day());
}
bool operator!=( const Date& lhs, const Date& rhs){

    return !(lhs == rhs);
}
std::ostream& operator<<(std::ostream& os, const month_type& m){

    os << int(m);
    return os;
}
std::ostream& operator<<(std::ostream& os, const Date& d){

    os << d.year() <<"/"<< d.month() << "/" << d.day();
    return os;
}
month_type& operator++(month_type& month){

    month = month_type((int(month)  % 12) + 1); 
    return month;
}
/*
 * Test if a year is leap
 */
bool is_leap(const unsigned y){

    return (y%4 == 0) && !(y%400 == 0);
}
