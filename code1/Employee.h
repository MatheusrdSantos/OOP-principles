#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include "Date.h"
class Employee{
    private:
        std::string name;
        float salary;
        Date* hiringDate;
    public:
        Employee(std::string name, float salary, Date* hiringDate);
        ~Employee(){};
};

#endif