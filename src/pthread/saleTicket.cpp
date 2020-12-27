
#include "saleTicket.h"
 
using namespace std;
 

int SaleTicket(void* lpParameter)
{
 
    THD_DATA* pThreadData = (THD_DATA*)lpParameter;
    TICKET* pSaleData = pThreadData->pTicket;

    if (pSaleData->nCount > 0)
    {
        cout << pThreadData->strThreadName << "出售第" << pSaleData->nCount -- << "的票,";
        if (pSaleData->nCount >= 0) {
            cout << "出票成功!剩余" << pSaleData->nCount << "张票." << endl;
        } else {
            cout << "出票失败！该票已售完。" << endl;
        }
    }
    return 0;
}