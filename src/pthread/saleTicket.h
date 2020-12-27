#include <string.h>
#include <cstring>
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
 
 
template<class T>
std::string convertToString(const T val)
{
    std::string s;
    std::strstream ss;
    ss << val;
    ss >> s;
    return s;
}
 
int SaleTicket(void* lpParameter);