#include "Controller.h"

using namespace std;

list<Company*> Controller::companies;
void Controller::printMenu(){
    cout<<"Company manager: "<<endl;
    cout<<"0 - Execute test without input (preloaded case);"<<endl;
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

void Controller::executeTest(){
    Company google("google", "1231");
    Date d1(19, 3, 2018);
    Date d2(19, 3, 2019);
    Date d3(10, 3, 2019);
    Employee e1("João", 1000.0, &d1);
    Employee e2("João Carlos", 1000.0, &d2);
    Employee e3("Maria J.", 3000.0, &d3);

    cout<<"HIRING AT GOOGLE:"<<endl;
    google.hire(&e1);
    google.hire(&e2);
    google.hire(&e3);

    cout<<"CANT HIRE TWICE: "<<endl;
    google.hire(&e1);
    google.incraseSalary(5.3);
    google.displayEmployees();

    cout<<"DISPLAY RECENT EMPLYEES(90 DAYS BEFORE): "<<endl;
    google.displayRecentEmployees();
    
    
    Company microsoft("microsoft", "12111");
    Date d5(19, 3, 2018);
    Date d6(19, 3, 2019);
    Date d7(10, 3, 2019);
    Employee e4("Luiz", 1000.0, &d5);
    Employee e5("Carlos S.", 1000.0, &d6);
    Employee e6("Thiago J.", 3000.0, &d7);

    cout<<"HIRING AT MICROSOFT:"<<endl;
    
    microsoft.hire(&e4);
    microsoft.hire(&e5);
    microsoft.hire(&e6);
    microsoft.incraseSalary(5.3);
    microsoft.displayEmployees();
    microsoft.displayRecentEmployees();

    std::cout<<"C: "<<Company::nCompanies<<std::endl;
    std::cout<<"E: "<<Employee::nEmployees<<std::endl;
    std::cout<<"Avarage: "<<Employee::nEmployees/Company::nCompanies<<std::endl;
    
    Date d9(10, 3, 2019);
    Employee e7("Roberto Carlos", 0, &d9);
    microsoft.hire(&e7);
    std::cout<<"E: "<<Employee::nEmployees<<std::endl;
    microsoft.fire(&e7);
    std::cout<<"E: "<<Employee::nEmployees<<std::endl;
    std::cout<<"Avarage: "<<Employee::nEmployees/Company::nCompanies<<std::endl;
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
        }else if(command == 0){
            executeTest();
        }
    }
}