#ifndef _DATE_H_
#define _DATE_H_
#define DAYS_IN_YEAR 365
#define DAYS_IN_MONTH 30
#define MONTHS_IN_YEAR 12

#include <string>
#include <iostream>
#include <ostream>
#include <istream>
using namespace std;
class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year);
        Date();
        ~Date(){};

        Date sumDays(int nDays);
        void normalizeDay();
        void normalizeMonth();
        void normalizeDate();

        bool operator==(Date date);
        bool operator<=(Date date);
        bool operator>=(Date date);
        bool operator<(Date date);
        bool operator>(Date date);
        friend ostream& operator<< (ostream &stream, Date date);
        friend istream& operator>> (istream &stream, Date* date);
};

#endif