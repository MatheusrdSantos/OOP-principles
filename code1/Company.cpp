#include "Company.h"
Company::Company(std::string name, std::string cnpj, Employee* employees){
    this->name = name;
    this->cnpj = cnpj;
    this->employees = employees;
}