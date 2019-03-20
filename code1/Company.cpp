#include "Company.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ctime>
Company::Company(std::string name, std::string cnpj){
    this->name = name;
    this->cnpj = cnpj;
}

void Company::hire(Employee* employee){
    bool found = (std::find(this->employees.begin(), this->employees.end(), (*employee)) != this->employees.end());
    if(found){
        std::cout<<"Employee already exists!"<<std::endl;
    }else{
        this->employees.push_back((*employee));
    }
}

void Company::displayEmployees(){
    auto it = this->employees.begin();
    auto end =this->employees.end();
    
    std::cout<<"Employees: "<<std::endl;
    for(;end!=it; advance(it, 1))
    {
        std::cout<<(*it);
    }
}

void Company::incraseSalary(float percentage){
    auto it = this->employees.begin();
    auto end =this->employees.end();
    
    for(;end!=it; advance(it, 1))
    {
        (*it).setSalary((*it).getSalary()+((*it).getSalary()*percentage/100));
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
        if(it->getHiringDate()->sumDays(90)>=actualDate){
            std::cout<<(*it);
        }
    }
}