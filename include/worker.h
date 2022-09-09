#include <iostream>
#include "employees.h"
#include "boss.h"


class Worker: public Employees {
    char taskAtWork = '0';
public:

    Worker (){
        name = getName() + " - worker";
    }

    void setWork (char work){
        taskAtWork = work;
        std::cout << name << " get Job " << taskAtWork << std::endl;
    }
    char getWork (){
        return taskAtWork;
    }
    ~Worker()=default;
};