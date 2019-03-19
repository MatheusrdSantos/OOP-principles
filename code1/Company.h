#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <string>
#include "Employee.h"
class Company{
    private:
        std::string name;
        std::string cnpj;
        Employee* employees;
    public:
        Company(std::string name, std::string cnpj, Employee* employees);
        ~Company(){};
};

#endif