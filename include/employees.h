#include <iostream>
#include <ctime>
#pragma once
class Employees {
    std::string employeesName [81] = {"Artem","Aleksandr","Maksim","Danil","Dmitri","Ivan","Kiril","Nikita",
                                       "Michail","Egor","Matvei","Andrey","Ilia","Aleksey","Roman","Sergey",
                                       "Vladislav","Yaroslav","Timofei","Arseniy","Denis","Vladimir","Pavel",
                                       "Gleb","Konstantin","Bogdan","Evgeny","Nikolai","Stepan","Zahar","Timur",
                                       "Mark","Semen","Fedor","Georgiy","Lev","Anton","Vadim","Igor`","Ruslan",
                                       "Vyacheslav","Grigoriy","Makar","Artur","Viktor","Stanislav","Saveliy",
                                       "Oleg","David","Leonid","Petr","Yriy","Vitaliy","Miron","Vasiliy",
                                       "Vsevolod","Elisey","Nazar","Rodion","Marat","Platon","German","Ignat",
                                       "Svetoslav","Anatoliy","Tihon","Valeriy","Rostislav","Boris","Fillip",
                                       "Demian","Klim","Valentin","Genadiy","Prohor","Serafim","Sava","Arkadiy",
                                       "Arhip","Taras","Trofim"};

public:
    std::string name;
    std::string getName (){
        std::srand(time(nullptr));
        return employeesName[rand()%80];
    }


};