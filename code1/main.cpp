#include <iostream>
#include "Employee.h"
#include "Company.h"
#include <list>
int main(int argc, char const *argv[]){
    Company google("google", "1231");
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
    //google.displayEmployees();
    google.displayRecentEmployees();
    return 0;
}
