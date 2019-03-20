#ifndef _DATE_H_
#define _DATE_H_

#include <string>
#include <ostream>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year);
        Date();
        ~Date(){};

        bool operator==(Date date);
        friend std::ostream& operator<< (std::ostream &stream, Date date);
};

#endif