cmake_minimum_required(VERSION 3.22)

set (MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set(SOURCE
        main.cpp

        )
set(INCLUDE
        ${MY_DIRECTORY}/employees.h
        ${MY_DIRECTORY}/boss.h
        ${MY_DIRECTORY}/manager.h
        ${MY_DIRECTORY}/team.h
        )




add_executable(elf_village ${SOURCE} ${INCLUDE})
target_include_directories (elf_village PUBLIC ${MY_DIRECTORY})