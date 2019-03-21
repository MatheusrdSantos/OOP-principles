#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <string>
#include <iostream>
#include <list>
#include "Date.h"
#include "Employee.h"
#include "Company.h"

using namespace std;

class Controller{
    private:
        static list<Company*> companies;
        static void listCompanies();
        static Company* chooseCompany();
        static void printMenu();
        static int getUserCommand();
        static void createCompany();
        static void addEmployee();
        static void hireEmployee(Employee* employee);
    public:

        static void run();
};

#endif