#include <iostream>
#include <cstdlib>
#include <pthread.h>


#define NAME_LINE   40
 


//定义线程函数传入参数的结构体
typedef struct __TICKET
{
    int nCount;
    char strTicketName[NAME_LINE];
 
    __TICKET() : nCount(0)
    {
        memset(strTicketName, 0, NAME_LINE * sizeof(char));
    }
}TICKET;
 
typedef struct __THD_DATA
{
    TICKET* pTicket;
    char strThreadName[NAME_LINE];
 
    __THD_DATA() : pTicket(NULL)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
}THD_DATA;
 
 
 //基本类型数据转换成字符串
template<class T>
std::string convertToString(const T val)
{
    std::string s;
    std::strstream ss;
    ss << val;
    ss >> s;
    return s;
}
 
//售票程序
int SaleTicket(LPVOID lpParameter);