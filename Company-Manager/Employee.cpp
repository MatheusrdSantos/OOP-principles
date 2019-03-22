#include "Employee.h"

int Employee::nEmployees = 0; 

Employee::Employee(string name,float salary, Date* hiringDate){
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

ostream& operator<<(ostream &stream, Employee* const employee){
    stream<<"----------------------"<<endl;
    stream<<"Name: "<<employee->name<<endl;
    stream<<"Salary: "<<employee->salary<<endl;
    stream<<"Hiring date: "<<employee->hiringDate<<endl;
    stream<<"----------------------"<<endl;
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

