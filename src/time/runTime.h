//********************
// Author:  yh 
// Time:    2020/12/15.
// 
//********************
//

#ifndef ALEX_RUNTIME_H
#define ALEX_RUNTIME_H


#include <time.h>
#include <iostream>
#include <stdio.h>

class runTime{
public:
    runTime(){

    }
    runTime(int i){
        printf("构造函数二号");
        this->mutex = 1;
        switch(i){
            case 1: this->start_t = clock();break;
            case 2: this->start_t = clock();break;
            case 3: this->start_t = clock();break;
            default: this->start_t = clock();break;
        }
        printf("cpu start：%ld\n", this->start_t);
    }

    ~runTime(){
        if(this->mutex){
            this->end_t = clock();
            printf("cpu end：%ld\n", this->end_t);
            this->printfTime();
        }
    }

    double returnRunTime();
    void runStart();
    void runClose();
    void printfTime();
    clock_t start_t, end_t;
    int mutex;
};



























#endif //ALEX_RUNTIME_H
