#include <iostream>

#include "Tasks/Task.hpp"


int main()
{
    Task t ;
    int size  = 0 ; 
    std::cout << "Enter the total number of tasks you wanna enter\n" ;    
    std::cin >> size ; 
    t.allocateSizeForTasks(size) ;

    while(*t.currentTaskIndex <= *t.totalTasks - 1)
    {
        t.getTask() ; 
    }
    t.saveTasks() ;

    return 0  ;
}