#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <string>
#include <list>
#include "Employee.h"
class Company{
    private:
        std::string name;
        std::string cnpj;
        std::list<Employee*> employees;
    public:
        Company(std::string name, std::string cnpj);
        ~Company();
        
        static int nCompanies;

        void hire(Employee* employee);
        void displayEmployees();
        void incraseSalary(float percentage);
        void displayRecentEmployees();
        void fire(Employee* employee);
        std::string getName();
        
};

#endif