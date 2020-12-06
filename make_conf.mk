RM = rm -f
MV = mv -f
MKDIR = mkdir -p
RMDIR = rm -rf   


# -------------------------------------------
ECHO_END:=\033[0m"
ECHO_GREEN:=echo "\033[32m
ECHO_RED:=echo "\033[31m
ECHO_YELLOW:=echo "\033[33m
ECHO_BLUE:=echo "\033[34m
ECHO_GREEN_YELLOW:=echo "\033[42;30m

# -------------------------------------------

CXX:=g++

COMPILE_C ?= $(CXX)
COMPILE_CXX ?= $(CXX)
COMPILE_ASM ?= $(CXX)
COMPILE_AR ?= ar

OPT ?=0

COMPILE_WARN ?= -Wall  
COMPILE_STATIC ?= -s

CFLAGS+= $(DIR_LIST_INCLUDE_I) $(COMPILE_WARN) -O$(OPT) $(COMPILE_STATIC)
CXXFLAGS+= $(DIR_LIST_INCLUDE_I) $(COMPILE_WARN) -O$(OPT) $(COMPILE_STATIC)
ASFLAGS+= -Wa,-adhlns=$(<:.S=.lst),-gstabs $(DIR_LIST_INCLUDE_I)

COMPILE_CFLAGS = $(CFLAGS)
COMPILE_CXXFLAGS = $(CXXFLAGS)
COMPILE_ASFLAGS = $(ASFLAGS)

LDFLAGS+= -lstdc++
LDFLAGS+= -lpthread
LDFLAGS+= -fPIC
LDFLAGS+= -ldl
LDFLAGS+= $(DIR_LIST_INCLUDE_I)
LDFLAGS+= $(DIR_LIST_DDL_L)



FILE_LIST_LIB_A+=\