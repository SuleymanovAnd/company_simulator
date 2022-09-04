#include <iostream>
#pragma once

class Employees {
    std::string employeesName;
public:
    std::string getName (){
        return employeesName;
    }

    void setName (std::string inName){
        employeesName = inName;
    }
};