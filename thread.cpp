#include<iostream>
#include<thread>
#include<unistd.h> //for system configurations

using namespace std;

void taskA()
{
    for(int i=0; i<10; i++)
    {
        sleep(1);
        printf("Task A: %d\n", i);
        fflush(stdout);
    }
}

void taskB()
{
    for(int i=0; i<10; i++)
    {
        sleep(1);
        printf("Task B: %d\n", i);
        fflush(stdout); //to reduce buffering to output device and print immmediately
    }
}

int main()
{
    thread t1(taskA);
    thread t2(taskB);

    t1.join(); //parent process's only job is to create these two threads. it will exit after that if this is not used for making parent process wait for child process execution.
    t2.join();
}