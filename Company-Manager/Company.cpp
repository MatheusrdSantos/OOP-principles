#include "Company.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ctime>

int Company::nCompanies = 0;

Company::Company(string name, string cnpj){
    this->name = name;
    this->cnpj = cnpj;
    Company::nCompanies++;
}

Company::~Company(){
    Company::nCompanies--;
}
string Company::getName(){
    return this->name;
}
void Company::hire(Employee* employee){
    //bool found = (find(this->employees.begin(), this->employees.end(), employee) != this->employees.end());
    auto it = this->employees.begin();
    auto end = this->employees.end();
    bool found = false;
    //cout<<"Employees: "<<endl;
    for(;end!=it; advance(it, 1))
    {
        if((*(*it)) == employee){
            found = true;
            break;
        }
    }

    cout<<endl;
    if(found){
        cout<<"Employee already exists!"<<endl;
    }else{
        this->employees.push_back(employee);
        cout<<"Employee hired!"<<endl;
        Employee::nEmployees++;
    }
}

void Company::fire(Employee* employee){
    int old_size = this->employees.size(); 
    this->employees.remove(employee);
    int new_size = this->employees.size();
    if(old_size>new_size){
        Employee::nEmployees--;
        cout<<"Employee is fired."<<endl;
    }else{
        cout<<"Employee doesn't work in this company."<<endl;
    }
}

void Company::displayEmployees(){
    auto it = this->employees.begin();
    auto end = this->employees.end();
    
    cout<<"Employees: "<<endl;
    for(;end!=it; advance(it, 1))
    {
        cout<<(*it);
    }

    cout<<endl;
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

    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    
    Date actualDate(timePtr->tm_mday, timePtr->tm_mon+1, timePtr->tm_year+1900);

    cout<<"Employees in test period: "<<endl;
    cout<<"Actual date: "<<actualDate<<endl;
    for(;end!=it; advance(it, 1))
    {
        if((*it)->getHiringDate()->sumDays(90)>=actualDate){
            cout<<(*it);
        }
    }
}