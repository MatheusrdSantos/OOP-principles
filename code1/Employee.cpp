#include "Employee.h"

Employee::Employee(std::string name,float salary, Date* hiringDate){
    this->name = name;
    this->salary = salary;
    this->hiringDate = hiringDate;
}