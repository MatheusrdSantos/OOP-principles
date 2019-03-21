#include "Controller.h"

using namespace std;
list<Company*> companies;
list<Company*> Controller::companies = companies;
void Controller::printMenu(){
    cout<<"Company manager: "<<endl;
    cout<<"1 - Create company; "<<endl;
    cout<<"2 - Hire employee; "<<endl;
    cout<<"3 - Listar funcionários; "<<endl;
    cout<<"4 - Aumentar salários; "<<endl;
    cout<<"5 - Listar funcionários novos (últimos 90 dias); "<<endl;
    cout<<"6 - Ver média de funcionários por empresa; "<<endl;
    cout<<"7 - Sair; "<<endl;
}
int Controller::getUserCommand(){
    int command;
    cout<<"-> ";
    cin>>command;
    return command;
}

void Controller::createCompany(){
    string name;
    string cnpj;
    
    cout<<"Company register:"<<endl;
    cout<<"Name: ";
    cin.ignore();
    getline(cin, name);
    //cin>>name;
    cout<<"CNPJ: ";
    cin>>cnpj;
    
    Company* company = new Company(name, cnpj);
    companies.push_back(company);

    cout<<"Company added."<<endl;
}

void Controller::listCompanies(){
    auto it = companies.begin();
    auto end = companies.end();
    int i = 1;
    std::cout<<"Companies: "<<std::endl;
    for(;end!=it; advance(it, 1))
    {
        std::cout<<i<<" - "<<(*it)->getName()<<';'<<endl;
        i++;
    }
}

Company* Controller::chooseCompany(){
    int i;
    listCompanies();
    cout<<"Choose one company: ";
    cin>>i;

    auto it = companies.begin();
    advance(it, i-1);

    return (*it);
}

void Controller::hireEmployee(Employee* employee){
    Company* company = chooseCompany();
    company->hire(employee);
}

void Controller::addEmployee(){
   std::string name;
   float salary;
   Date* hiringDate = new Date(); 
   cout<<"Employee register:"<<endl;
   cout<<"Name: ";
   cin.ignore();
   getline(cin, name);
   cout<<"salary: ";
   cin>>salary;
   cout<<"*date format: dd/mm/yyyy"<<endl;
   cout<<"hiringDate: ";
   cin>>hiringDate;
   Employee* employee = new Employee(name, salary, hiringDate);
   cout<<employee;
   hireEmployee(employee);
}

void Controller::run(){
    int command = 0;
    while(command!=7){
        printMenu();
        command = getUserCommand();
        if(command==1){
            createCompany();
        }else if(command==2){
            addEmployee();
        }
    }
}