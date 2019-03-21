#include "Controller.h"

using namespace std;

void Controller::printMenu(){
    cout<<"Company manager: "<<endl;
    cout<<"1 - Create company; "<<endl;
    cout<<"2 - Hire employee; "<<endl;
    cout<<"3 - Listar funcionários; "<<endl;
    cout<<"4 - Aumentar salários; "<<endl;
    cout<<"5 - Listar funcionários novos (últimos 90 dias); "<<endl;
    cout<<"6 - Ver média de funcionários por empresa; "<<endl;
}
int Controller::getUserCommand(){
    int command;
    cout<<"-> ";
    cin>>command;
    return command;
}

void Controller::run(){
    int command = 0;
    while(command!=-1){
        printMenu();
        command = getUserCommand();
    }
}