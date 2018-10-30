//: Date.h

#include <iostream>

/*
 * mont_type, enum that encodes months of the year
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
        Date (unsigned day, month_type month, unsigned year);
        unsigned day() const;
        month_type month() const;
        unsigned year() const;
        void add_days( const unsigned n);
};

/*
 * Helper functions
 */
bool operator==( const Date& lhs, const Date& rhs);
bool operator!=( const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& os, const month_type& m);
std::ostream& operator<<(std::ostream& os, const Date& d);


