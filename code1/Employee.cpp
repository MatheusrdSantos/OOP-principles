#include "Employee.h"

int Employee::nEmployees = 0; 

Employee::Employee(std::string name,float salary, Date* hiringDate){
    this->name = name;
    this->salary = salary;
    this->hiringDate = (*hiringDate);
}

Employee::~Employee(){
    
}

bool Employee::operator==(Employee* employee){
    if(this->name == employee->name && this->salary == employee->salary && this->hiringDate==employee->hiringDate){
        return true;
    }else{
        return false;
    }
}

std::ostream& operator<<(std::ostream &stream, Employee* const employee){
    stream<<"----------------------"<<std::endl;
    stream<<"Name: "<<employee->name<<std::endl;
    stream<<"Salary: "<<employee->salary<<std::endl;
    stream<<"Hiring date: "<<employee->hiringDate<<std::endl;
    stream<<"----------------------"<<std::endl;
    return stream;
}

void Employee::setSalary(float salary){
    this->salary = salary;
}

float Employee::getSalary(){
    return this->salary;
}

Date* Employee::getHiringDate(){
    return &this->hiringDate;
}

