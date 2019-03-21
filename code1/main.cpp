#include <iostream>
#include "Employee.h"
#include "Company.h"
#include <list>
using namespace std;

void printMenu(){
    cout<<"Company manager: "<<endl;
    cout<<"1 - Create company; "<<endl;
    cout<<"2 - Hire employee; "<<endl;
    cout<<"3 - Listar funcionários; "<<endl;
    cout<<"4 - Aumentar salários; "<<endl;
    cout<<"5 - Listar funcionários novos (últimos 90 dias); "<<endl;
    cout<<"6 - Ver média de funcionários por empresa; "<<endl;
}
int getUserCommand(){
    int command;
    cout<<"-> ";
    cin>>command;
    return command;
}

int main(int argc, char const *argv[]){

    int command = 0;
    while(command!=-1){
        printMenu();
        command = getUserCommand();
    }
    
    /* Company google("google", "1231");
    Date d1(19, 3, 2018);
    Date d2(19, 3, 2019);
    Date d3(10, 3, 2019);
    Employee e1("João", 1000.0, &d1);
    Employee e2("João Carlos", 1000.0, &d2);
    Employee e3("Maria J.", 3000.0, &d3);
    google.hire(&e1);
    google.hire(&e2);
    google.hire(&e3);
    google.incraseSalary(5.3);
    google.displayEmployees();
    google.displayRecentEmployees();
    
    
    Company microsoft("microsoft", "12111");
    Date d5(19, 3, 2018);
    Date d6(19, 3, 2019);
    Date d7(10, 3, 2019);
    Employee e4("Luiz", 1000.0, &d5);
    Employee e5("Carlos S.", 1000.0, &d6);
    Employee e6("Thiago J.", 3000.0, &d7);
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
    std::cout<<"Avarage: "<<Employee::nEmployees/Company::nCompanies<<std::endl; */
    return 0;
}
