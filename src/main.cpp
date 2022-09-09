#include <iostream>
#include "manager.h"

int main() {
    std::cout << "Enter the number of teams: " << std::endl;
    int number;
    std::cin >> number;

    Boss newBoss = *new Boss ();
    for (int i = 0; i < number;i++){
        int workersAmount;
        std::cout << "Enter the number of workers in " << i+1 << " team.";
        std::cin >> workersAmount;

        int task;

        std::cout << "Enter task: ";
        std::cin >>task;
        newBoss.setTask(task);
        Manager taskManager = *new Manager(i,workersAmount,&newBoss);
            while (!taskManager.allWorkersBusy()){
                std::cout << "Enter task again: ";
                std::cin >>task;
                newBoss.setTask(task);
                taskManager.creatingABCTasks ();
                taskManager.distributionOfTasks();
            }
    }

}
