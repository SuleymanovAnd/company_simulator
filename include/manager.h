#include <iostream>
#include "employees.h"
#include "boss.h"
#include "worker.h"
#include <cstdlib>
#include <vector>


class Manager: public Employees {
    int serialNumber;
    int hash;
    Boss* chief;
    struct newTeam {
        std::vector <Worker*> workers;
        int taskA = 0;
        int taskB = 0;
        int taskC = 0;
        int busyWorkers = 0;
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
    int allWorkersBusy (){
      // std::cout << (int)team->busyWorkers << std::endl;
        return (int)team->busyWorkers - (int)team->workers.size();
    }

    Manager (int inSerialNumber, int amountOfWorkers, Boss* newBoss): serialNumber(inSerialNumber)
    {
        name = getName() + " - manager";
        setChief (newBoss);
        std::cout << name << " get task"<<std::endl;
        newTeam workTeam; //std::cout << "create new team"<<std::endl;
        setTeam (&workTeam);// std::cout << "set new team"<<std::endl;
        workTeam.workers.resize (amountOfWorkers);// std::cout << "resize new team"<<std::endl;
        creatingABCTasks (); //std::cout << "create ABC"<<std::endl;
        distributionOfTasks();  //std::cout << "distribution"<<std::endl;
    }

    void creatingABCTasks (){
        int allocator;

        int endTasks = createSubtask ();
        for (int i =0; i < endTasks ;i++){
            std::srand(time(nullptr));
            allocator = rand()% 3 + 1;
            switch (allocator){
                case 1: std::cout << "A"<<std::endl; team->taskA = (int)team->taskA+1;break;
                case 2: std::cout << "B"<<std::endl; team->taskB = (int)team->taskB+1;break;
                case 3: std::cout << "C"<<std::endl; team->taskC = (int)team->taskC+1;break;
                default: std::cout << "default"<< std::endl ;break;
            }
        }
    }

    void distributionOfTasks () {
        int taskSelection = 1;
        bool allWorkersBusy = (int) team->busyWorkers == team->workers.size();
        int allTask = (int) team->taskA + (int) team->taskB + (int) team->taskC;
        for (int i = 0; !allWorkersBusy && allTask != 0; i++) {
// из за не работающего rand решил использовать i для распределения задач
            if (i % 2 == 0 || i == 0) taskSelection = 1;
            if (i % 3 == 0) taskSelection = 2;
            if (i % 4 == 1 || i % 3 == 1) taskSelection = 3;

            if (team->workers[i] == nullptr) {
                team->workers[i] = new Worker();
            } else {
                   // std::cout << "worker[i]" << std::endl;
                  //  std::cout << team->busyWorkers << "worker busy " << team->workers.size() << " " << allTask << " AllTask"
                        //      << std::endl;
                    switch (taskSelection) {
                        case 1:
                            if (team->taskA != 0) {
                              //  std::cout << 7 << std::endl;
                                team->taskA--;
                                team->workers[i]->setWork('A');
                                team->busyWorkers++;
                                allTask--;
                                break;
                            }
                            else {
                                std::cout << "Task A == 0" << std::endl;
                                break;
                            }
                        case 2:
                            if (team->taskB != 0) {
                              //  std::cout << 8 << std::endl;
                                team->taskB--;
                                team->workers[i]->setWork('B');
                                team->busyWorkers++;
                                allTask--;
                                break;
                            }
                            else {
                                std::cout << "Task B == 0" << std::endl;
                                break;
                            }
                        case 3:
                            if (team->taskC != 0) {
                                //std::cout << 9 << std::endl;
                                team->taskC--;
                                team->workers[i]->setWork('C');
                                team->busyWorkers++;
                                allTask--;
                                break;
                            }
                            else {
                                std::cout << "Task C == 0" << std::endl;
                                break;
                            }
                        default:
                            break;
                    }
                    allWorkersBusy = team->busyWorkers == team->workers.size();
            }
            if( i >= team->workers.size() -1 ) i = 0;
        } if (allWorkersBusy) { std::cout << "all workers busy"; }
        else {std::cout << team->workers.size() - team->busyWorkers <<
                        " workers dont busy!";}
    }
    ~Manager()=default;
};