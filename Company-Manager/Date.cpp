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

// overload operator ==
bool Date::operator==(Date date){
    if(this->day == date.day && this->month == date.month && this->year == date.year){
        return true;
    }else{
        return false;
    }
}

// overload operator <=
bool Date::operator<=(Date date){
    if((*this)==date){
        return true;
    }
    if(this->year<date.year){
        return true;
    }else if(this->year==date.year){
        if(this->month<date.month){
            return true;
        }else if(this->month==date.month){
            if(this->day<date.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// overload operator <
bool Date::operator<(Date date){
    if(this->year<date.year){
        return true;
    }else if(this->year==date.year){
        if(this->month<date.month){
            return true;
        }else if(this->month==date.month){
            if(this->day<date.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// overload operator >=
bool Date::operator>=(Date date){
    if((*this)==date){
        return true;
    }
    if(this->year>date.year){
        return true;
    }else if(this->year==date.year){
        if(this->month>date.month){
            return true;
        }else if(this->month==date.month){
            if(this->day>date.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// overload operator >
bool Date::operator>(Date date){
    if(this->year>date.year){
        return true;
    }else if(this->year==date.year){
        if(this->month>date.month){
            return true;
        }else if(this->month==date.month){
            if(this->day>date.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// overload operator <<
ostream& operator<<(ostream &stream, Date const date){
    stream<<date.day<<"/"<<date.month<<"/"<<date.year;
    return stream;
}

// overload operator >>
istream& operator>>(istream &stream, Date* date){
    char separator = '/';
    stream>>date->day>>separator>>date->month>>separator>>date->year;
    return stream;
}

// put day between 1 and 30, the remaining is added to months
void Date::normalizeDay(){
    if(this->day>DAYS_IN_MONTH){
        int newDay = this->day%DAYS_IN_MONTH;
        int monthsToSum = this->day/DAYS_IN_MONTH;
        this->day = newDay;
        this->month+=monthsToSum; 
    }
}

// put month between 1 and 12, the remaining is added to years
void Date::normalizeMonth(){
    if(this->month>MONTHS_IN_YEAR){
        int newMonth = this->month%MONTHS_IN_YEAR;
        int yearsToSum = this->month/MONTHS_IN_YEAR;
        this->month = newMonth;
        this->year+=yearsToSum; 
    }
}

// put days and months in the right format
void Date::normalizeDate(){
    normalizeDay();
    normalizeMonth();
}

// add N days to a date
Date Date::sumDays(int nDays){
    Date newDate(this->day, this->month, this->year);
    newDate.day+=nDays;
    newDate.normalizeDate();
    return newDate;
}