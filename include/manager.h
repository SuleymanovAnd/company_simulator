#include <iostream>
#include "employees.h"
#include "boss.h"
#include <cstdlib>
#include <vector>

class Manager: public Employees {
    int serialNumber;
    int hash;
    Boss* chief;
    struct newTeam {
        std::vector <char> workers;
        int taskA;
        int taskB;
        int taskC;

    };

    newTeam* team;

    void hashCreate (Boss *Boss){
        hash = serialNumber + Boss->getTask();
    }

    int createSubtask (){
        hashCreate (chief);
        std::srand(hash);
        int tasksCount = rand() % (team->workers.size() + 1);
        return tasksCount;
    }

public:
    void setTeam ( newTeam* t){
        team = t;
    }

    void setChief (Boss* inChief){
        chief = inChief;
    }

    Manager (int inSerialNumber, int amountOfWorkers, Boss* newBoss): serialNumber(inSerialNumber)
    {
        setChief (newBoss);
        newTeam workTeam;
        setTeam (&workTeam);
        workTeam.workers.resize (amountOfWorkers);
        creatingABCTasks (workTeam.taskA,workTeam.taskB,workTeam.taskC);

    }

    void creatingABCTasks (int &A, int &B, int &C){
        int allocator;
        std::srand(time(nullptr));
        int endTasks = createSubtask ();
        for (int i =0; i < endTasks ;i++){
            allocator = rand() %4 +1;
            switch (allocator){
                case 1: ++A;break;
                case 2: ++B;break;
                case 3: ++C;break;
                default: break;
            }
        }
    }

    void distributionOfTasks (){

    }

    ~Manager()=default;
};