#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include "Date.h"
#include <ostream>

using namespace std;
class Employee{
    private:
        string name;
        float salary;
        Date hiringDate;
    public:
        Employee(string name, float salary, Date* hiringDate);
        ~Employee();
        
        void setSalary(float salary);
        float getSalary();
        Date* getHiringDate();
        static int nEmployees;

        bool operator==(Employee* employee);
        friend ostream& operator<< (ostream &stream, Employee* employee);

};

#endif