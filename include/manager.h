#include <iostream>
#include "employees.h"
#include "boss.h"
#include <cstdlib>
#include <vector>

class Manager: public Employees {

    int hash;
    struct team {
        std::vector <int> workers;
    };

    team* team;

    int createSubtask (){
        std::srand(hash);
        int tasksCount = rand() % (team->workers.size() + 1);
        return tasksCount;
    }

public:

};