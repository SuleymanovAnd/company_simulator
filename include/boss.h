#include <iostream>
#include "employees.h"
#include <vector>
#pragma once

class Boss:public Employees {
    int task;
public:
    Boss(){name = getName () + " - BOSS";};

    void setTask (int inTask){
        task = inTask ; std:: cout << "task set" << std::endl;
    }
    int getTask (){
        return task;
    }
};