#include "Date.h"

Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

bool Date::operator==(Date date){
    if(this->day == date.day && this->month == date.month && this->year == date.year){
        return true;
    }else{
        return false;
    }
}

std::ostream& operator<<(std::ostream &stream, Date const date){
    // change this code to american pattern
    stream<<date.day<<"/"<<date.month<<"/"<<date.year;
    return stream;
}