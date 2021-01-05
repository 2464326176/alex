#include "LogPrint.h"
#include <stdarg.h>






void LogInfo(const char * format, ...){
    char TmpBuf[MAXBUFSIZE];
    char formatBuf[MIDBUFSIZE];
    va_list aptr;
    va_start(aptr, format);
    vsprintf(formatBuf, format, aptr);
    sprintf(TmpBuf, "%s,  %s", LOG_DEBUG, formatBuf);
    printf("%s\n", TmpBuf);
    va_end(aptr);
}

char* LogToString(LOGLEVEL level){

    switch(level){
        case Debug:
            return LOG_NONE; break;
        case Info:
            return LOG_DEBUG; break;
        case Error:
            return LOG_INFO; break;
        default:
            return LOG_ERROR;
    }

}

