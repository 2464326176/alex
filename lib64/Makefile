DIR_LIST_DDL+=\
jsoncpp\

DIR_LIST_DDL_N+=\
jsoncpp\
yhcpp\


NAME_MODULE := $(notdir $(CURDIR))#所在的文件夹名称
DIR_LIST_DDL_L:= $(addprefix -L,$(DIR_LIST_DDL))#添加编译选项-I
DIR_LIST_DDL_NAME:= $(addprefix -l, ${DIR_LIST_DDL_N})#添加编译选项-I

ECHO_END:=\033[0m"
ECHO_GREEN:=echo "\033[32m
ECHO_RED:=echo "\033[31m
ECHO_YELLOW:=echo "\033[33m
ECHO_BLUE:=echo "\033[34m
ECHO_GREEN_YELLOW:=echo "\033[42;30m

make_root:make_start  make_end

# 工程开始
make_start:
	@$(ECHO_BLUE)\t-\t  $(DIR_LIST_DDL_NAME) \t    -$(ECHO_END)
	
	


make_end: 
	@$(ECHO_BLUE)[编译完成]$(ECHO_END)         
