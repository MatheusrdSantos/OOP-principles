#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year);
        ~Date(){};
};

#endif