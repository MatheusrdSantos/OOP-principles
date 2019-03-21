#include "Company.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ctime>

int Company::nCompanies = 0;

Company::Company(std::string name, std::string cnpj){
    this->name = name;
    this->cnpj = cnpj;
    Company::nCompanies++;
}

Company::~Company(){
    Company::nCompanies--;
}
std::string Company::getName(){
    return this->name;
}
void Company::hire(Employee* employee){
    bool found = (std::find(this->employees.begin(), this->employees.end(), employee) != this->employees.end());
    if(found){
        std::cout<<"Employee already exists!"<<std::endl;
    }else{
        this->employees.push_back(employee);
        std::cout<<"Employee hired!"<<std::endl;
        Employee::nEmployees++;
    }
}

void Company::fire(Employee* employee){
    int old_size = this->employees.size(); 
    this->employees.remove(employee);
    int new_size = this->employees.size();
    if(old_size>new_size){
        Employee::nEmployees--;
        std::cout<<"Employee is fired."<<std::endl;
    }else{
        std::cout<<"Employee doesn't work in this company."<<std::endl;
    }
}

void Company::displayEmployees(){
    auto it = this->employees.begin();
    auto end = this->employees.end();
    
    std::cout<<"Employees: "<<std::endl;
    for(;end!=it; advance(it, 1))
    {
        std::cout<<(*it);
    }

    std::cout<<std::endl;
}

void Company::incraseSalary(float percentage){
    auto it = this->employees.begin();
    auto end =this->employees.end();
    
    for(;end!=it; advance(it, 1))
    {
        (*it)->setSalary((*it)->getSalary()+((*it)->getSalary()*percentage/100));
    }
}

void Company::displayRecentEmployees(){
    auto it = this->employees.begin();
    auto end =this->employees.end();

    std::time_t t = time(NULL);
	std::tm* timePtr = localtime(&t);
    
    Date actualDate(timePtr->tm_mday, timePtr->tm_mon+1, timePtr->tm_year+1900);

    std::cout<<"Employees in test period: "<<std::endl;
    std::cout<<"Actual date: "<<actualDate<<std::endl;
    for(;end!=it; advance(it, 1))
    {
        if((*it)->getHiringDate()->sumDays(90)>=actualDate){
            std::cout<<(*it);
        }
    }
}