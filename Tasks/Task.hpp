#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <ctime>

struct Task 
{
    int *totalTasks ;
    int *completedTasks ; 
    int *uncompletedTasks ; 
    std::string *tasks ;
    int *currentTaskIndex ;
    //////////////////////////////////////////
    ////// Constructors and Destructos START
    /////////////////////////////////////////
    Task()
    {
        totalTasks = nullptr ;
        completedTasks = nullptr ;
        uncompletedTasks = nullptr ;
        tasks = nullptr ;
        currentTaskIndex = nullptr ;
    }
    Task(const int SIZE)
    {
        totalTasks = new int(SIZE) ;
        completedTasks = new int(0) ; 
        uncompletedTasks = new int(*totalTasks) ;  
        tasks = new std::string[*totalTasks]{""} ; 
        currentTaskIndex = new int(0) ;
    }
    ~Task()
    {
        if(!totalTasks)
            delete totalTasks ;
        if(!completedTasks)
            delete completedTasks ;
        if(!uncompletedTasks)
            delete uncompletedTasks ;
        if(!tasks)
            delete [] tasks ;
    }
    //////////////////////////////////////////
    ////// Constructors and Destructos END
    /////////////////////////////////////////


    //////////////////////////////////////////////////////////////
    //// To Allocate the size manually if the default constructor is called
    void allocateSizeForTasks(const int SIZE)
    {
        totalTasks = new int(SIZE) ;
        completedTasks = new int(0) ; 
        uncompletedTasks = new int(*totalTasks) ;  
        tasks = new std::string[*totalTasks]{""} ; 
        currentTaskIndex = new int(0) ;
    }

    ///////////////////////////////////////////////////////////////
    /////  Get Tasks from the users
    void getTask()
    {
        std::cout << "Enter your tasks for today sir\n" ;
        getline(std::cin >> std::ws , tasks[*currentTaskIndex]) ; 
        (*currentTaskIndex)++ ; 
    }

    void saveTasks()
    {
        std::ofstream file ; 
        file.open("Task.txt" , std::ios::out) ;
        if(!file.is_open())
        {
            std::cerr << "Error in opening the file to save the tasks\n" ;
            exit(0) ;
        }
        for(int st = 0 ;  st <= *totalTasks -  1 ; st++)
        {
            file << tasks[st] << std::endl ;
        }
    }



};