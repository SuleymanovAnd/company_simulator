#include <iostream>
#include "employees.h"
#include <vector>
#pragma once

class Boss:public Employees {
    int task;
public:
    Boss(){};

    void setTask (int inTask){
        task =inTask ;
    }
    int getTask (){
        return task;
    }
};