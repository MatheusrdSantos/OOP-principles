#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <string>
#include <list>
#include "Employee.h"
using namespace std;
class Company{
    private:
        string name;
        string cnpj;
        list<Employee*> employees;
    public:
        Company(string name, string cnpj);
        ~Company();
        
        static int nCompanies;

        void hire(Employee* employee);
        void displayEmployees();
        void incraseSalary(float percentage);
        void displayRecentEmployees();
        void fire(Employee* employee);
        string getName();
        
};

#endif