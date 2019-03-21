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
    cin>>name;
    cout<<"CNPJ: ";
    cin>>cnpj;
    Company* company = new Company(name, cnpj);
    companies.push_back(company);

    cout<<"Company added."<<endl;
}

void Controller::run(){
    int command = 0;
    while(command!=7){
        printMenu();
        command = getUserCommand();
        if(command==1){
            createCompany();
        }
    }
}