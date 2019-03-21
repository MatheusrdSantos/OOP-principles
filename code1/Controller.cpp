#include "Controller.h"

using namespace std;

list<Company*> Controller::companies;
void Controller::printMenu(){
    cout<<"Company manager: "<<endl;
    cout<<"1 - Create company; "<<endl;
    cout<<"2 - Hire employee; "<<endl;
    cout<<"3 - List Employees; "<<endl;
    cout<<"4 - Increase salary; "<<endl;
    cout<<"5 - List new employees (last 90 days); "<<endl;
    cout<<"6 - Display employee average; "<<endl;
    cout<<"7 - Exit; "<<endl;
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

void Controller::listEmployees(){
    Company* company = chooseCompany();
    company->displayEmployees();
}

void Controller::increaseSalary(){
    Company* company = chooseCompany();
    float increase;
    cout<<"Amount of increase in percentage: ";
    cin>>increase;
    company->incraseSalary(increase);
}

void Controller::listNewEmployees(){
    Company* company = chooseCompany();
    company->displayRecentEmployees();
}

void Controller::displayEmployeesAverage(){
    cout<<"Average (Employee per Company): "<<Employee::nEmployees/Company::nCompanies<<endl;
}

void Controller::run(){
    int command = 0;
    while(command!=7){
        printMenu();
        command = getUserCommand();
        if(command == 1){
            createCompany();
        }else if(command == 2){
            addEmployee();
        }else if(command == 3){
            listEmployees();
        }else if(command == 4){
            increaseSalary();
        }else if(command == 5){
            listNewEmployees();
        }else if(command == 6){
            displayEmployeesAverage();
        }
    }
}