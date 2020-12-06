# 设置当前路径
DIR_ROOT:=.

# 设置递归子目录
DIR_LIST_SUB :=src


include $(DIR_ROOT)/make_conf.mk
all:make_root
clean:make_clean
include $(DIR_ROOT)/make_fun.mk