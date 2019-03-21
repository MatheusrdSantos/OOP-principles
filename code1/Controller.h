#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <string>
#include <iostream>
#include <list>
#include "Employee.h"
#include "Company.h"

using namespace std;

class Controller{
    private:
        static void printMenu();
        static int getUserCommand();
    public:
        static list<Company*> companies;

        static void run();
};

#endif