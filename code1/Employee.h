#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include "Date.h"
#include <ostream>
class Employee{
    private:
        std::string name;
        float salary;
        Date hiringDate;
    public:
        Employee(std::string name, float salary, Date* hiringDate);
        ~Employee(){};
        
        bool operator==(Employee employee);

        friend std::ostream& operator<< (std::ostream &stream, Employee employee);

};

#endif