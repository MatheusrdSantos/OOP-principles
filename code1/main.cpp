#include <iostream>
#include "Employee.h"
#include "Company.h"
#include <list>
int main(int argc, char const *argv[]){
    Company google("google", "1231");
    Date d1(19, 3, 19);
    Date d2(18, 3, 19);
    Employee e1("João", 1000.0, &d1);
    Employee e2("Maria", 2000.0, &d1);
    google.hire(&e1);
    google.hire(&e2);
    google.displayEmployees();
    return 0;
}
