#include <stdio.h>
#include <stdlib.h>

#define MAXBUFSIZE 1024
#define MIDBUFSIZE 512
#define MINBUFSIZE 128

#define LOG_NONE    (char* )"none"
#define LOG_DEBUG   (char* )"debug"
#define LOG_INFO    (char* )"info"
#define LOG_ERROR   (char* )"error"

enum LOGLEVEL{
    None,
    Debug,
    Info,
    Error,
};


void LogInfo(const char * format, ...);

char* LogToString(LOGLEVEL level);










