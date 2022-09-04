#include <iostream>
#include "employees.h"
#pragma once

class Boss:public Employees {
    int task;
public:

    void setTask (int inTask){
        task = inTask;
    }
    int getTask (){
        return task;
    }
};