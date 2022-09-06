#include <iostream>
#include "manager.h"

int main() {
    std::cout << "Enter the number of teams: " << std::endl;
    int number;
    std::cin >> number;

    int end;
    for (int i = 0; i < number;i++){
        int workersAmount;
        std::cout << "Enter the number of workers in " << i+1 << " team.";
        std::cin >> workersAmount;

        Boss newBoss = *new Boss ();
        for(int j = 0 ; j < end;j++){
            int task;
            std::cout << "Enter task: ";
            std::cin >>task;
            newBoss.setTask(task);
            Manager(i,workersAmount,&newBoss);
        }

    }

}
