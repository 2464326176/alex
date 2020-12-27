//********************
// Author:  yh 
// Time:    2020/12/15.
// 
//********************
//

#include "runTime.h"



double runTime::returnRunTime()
{
    return (double)(end_t - start_t) / CLOCKS_PER_SEC;
}

void runTime::printfTime(){
    printf("cpu start：%ld\n, cpu end：%ld\n", this->start_t, this->end_t);
    printf("cpu处理时间：%ld\n", (double)(this->end_t - this->start_t) / CLOCKS_PER_SEC);
}

void runTime::runStart(){
    this->start_t = clock();
    printf("cpu start：%ld\n", this->start_t);
}

void runTime::runClose(){
    this->end_t = clock();
    printf("cpu end：%ld\n", this->end_t);

}

int main(){
    runTime *r1 = new runTime(1);
    for(int i=0;i<10000000;++i){


    }
    delete r1;
    return 0;
}