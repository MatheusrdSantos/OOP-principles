#include "Company.h"
#include <algorithm>
#include <iostream>
#include <iterator>
Company::Company(std::string name, std::string cnpj){
    this->name = name;
    this->cnpj = cnpj;
}

void Company::hire(Employee* employee){
    bool found = (std::find(this->employees.begin(), this->employees.end(), (*employee)) != this->employees.end());
    if(found){
        std::cout<<"Employee already exists!";
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