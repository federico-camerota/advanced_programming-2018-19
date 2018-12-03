#include <iostream>

/*
 * mont_type enum encodes months of the year
 */
enum class month_type {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

/*
 * Function prototypes
 */
bool is_leap(const unsigned y);
month_type& operator++(month_type& month);


/*
 * Date class
 */
class Date{

    private:
        month_type m;
        unsigned d;
        unsigned y;
        void add_day();

    public:
        unsigned day() const {
        
            return d;
        }
        month_type month() const{
        
            return m;
        }
        unsigned year() const{
        
            return y;
        }
        void add_days( const unsigned n){
        
            for (unsigned i = 0; i < n; i++)
                add_day();
        }
        Date (unsigned day, month_type month, unsigned year) :
            d{day},
            m{month},
            y{year}
        {}
};



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
 * Test if a year is leap
 */
bool is_leap(const unsigned y){

    return (y%4 == 0) && !(y%400 == 0);
}


/*
 * Helper functions
 */
bool operator==( const Date& lhs, const Date& rhs);
bool operator!=( const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& os, const month_type& m);
std::ostream& operator<<(std::ostream& os, const Date& d);

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


int main(){

    Date today{25, month_type::FEB, 2016};
    Date otherday{25, month_type::DEC, 2018};

    for (int i = 0; i < 15; i++){
    
        today.add_days(1);
        std::cout << today.day() << " " << int(today.month()) << " " << today.year() << std::endl;
    }
    std::cout << today << std::endl;
    std::cout << otherday << std::endl;
    std::cout << (today == otherday) << std::endl;
}
