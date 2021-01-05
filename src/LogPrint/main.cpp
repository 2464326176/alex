#include <iostream>
#include "LogPrint.h"




int main()
{
    char buf[20] = "index";
    int i = 1;

    LogInfo("index: %s, i:%d", buf, i);

    return 0;
}
