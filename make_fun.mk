# -------------------------------------------
DIR_ROOT_REAL=$(realpath $(DIR_ROOT))
NAME_MODULE := $(notdir $(CURDIR))
DIR_OUTPUT:=$(DIR_ROOT)/output
DIR_BIN:=$(DIR_OUTPUT)/bin
DIR_OBJ:=$(DIR_OUTPUT)/obj
DIR_LIB:=$(DIR_OUTPUT)/lib
DIR_DDL:=$(DIR_ROOT)/lib64

# -------------------------------------------
DIR_LIST_INCLUDE_I:=$(addprefix -I,$(DIR_LIST_INCLUDE))
DIR_LIST_DDL_L:= $(addprefix -L,$(DIR_DDL))
DIR_LIST_DDL_NAME:= $(addprefix -l,$(DIR_LIST_DDL))

DIR_LIST_SUB:=$(addprefix  $(CURDIR)/,$(DIR_LIST_SUB))
DIR_CURDIR:=$(subst $(DIR_ROOT_REAL),,$(CURDIR))
DIR_OBJ_OUT:=$(DIR_OBJ)$(DIR_CURDIR)


FILE_LIST_OBJ:=$(FILE_LIST_C:%.c=%.o)
FILE_LIST_OBJ+=$(FILE_LIST_CPP:%.cpp=%.o)
FILE_LIST_OBJ+=$(FILE_LIST_S:%.s=%.o)

FILE_LIST_OBJ:=$(addprefix  $(DIR_OBJ_OUT)/,$(FILE_LIST_OBJ))
FILE_LIB_A:=$(DIR_LIB)/libobj.a
FILE_LIST_LIB_APP:=$(DIR_BIN)/$(NAME_MODULE).bin
FILE_LIST_LIB_DDL:=$(DIR_DDL)/$(NAME_MODULE).bin
# ------------------------------------------- 
make_root:make_start make_subdir make_end

make_start:
	@$(ECHO_BLUE)\t-----------------------------$(ECHO_END)
	@$(ECHO_BLUE)\t-\t [编译开始]  \t    -$(ECHO_END)
	@$(ECHO_BLUE)\t-----------------------------$(ECHO_END)
	@$(ECHO_BLUE)[COMPILE_C]$(COMPILE_C) 	 	[COMPILE_CFLAGS]$(COMPILE_CFLAGS)$(ECHO_END)
	@$(ECHO_BLUE)[COMPILE_CXX]$(COMPILE_CXX) 	[COMPILE_CXXFLAGS]$(COMPILE_CXXFLAGS)$(ECHO_END)
	@$(ECHO_BLUE)[COMPILE_ASM]$(COMPILE_ASM) 	[COMPILE_ASFLAGS]$(COMPILE_ASFLAGS)$(ECHO_END)
	@$(ECHO_BLUE)[COMPILE_AR]$(COMPILE_AR)   	[LDFLAGS]$(LDFLAGS)$(ECHO_END)
	@$(ECHO_BLUE)[OPT]$(OPT)  $(ECHO_END)
	@$(ECHO_BLUE)[COMPILE_STATIC]$(COMPILE_STATIC)  $(ECHO_END)
	@$(ECHO_BLUE)[FILE_LIST_LIB_A]$(FILE_LIST_LIB_A)  $(ECHO_END)


make_end: 
	@$(ECHO_BLUE)[编译完成]$(ECHO_END)         

make_subdir:
	@for list in $(DIR_LIST_SUB);\
	do\
		cd $$list && make all|| exit 1;\
	done

make_app:make_lib_a make_bin

make_lib_a:make_obj
	@$(MKDIR) `dirname $(FILE_LIB_A)`
	@$(ECHO_YELLOW)[$(COMPILE_AR)]-rcs $(FILE_LIB_A) $(FILE_LIST_OBJ)$(ECHO_END)
	$(COMPILE_AR) -rcs $(FILE_LIB_A) $(FILE_LIST_OBJ)

make_bin:$(FILE_LIST_LIB_APP)

make_obj:$(FILE_LIST_OBJ)


make_clean:
	$(RMDIR) $(DIR_OUTPUT)

make_show:
	@$(ECHO_GREEN_YELLOW)[DIR_CURDIR] $(DIR_CURDIR) $(ECHO_END)
	@$(ECHO_GREEN)[FILE_LIST_C] $(FILE_LIST_C) $(ECHO_END)
	@$(ECHO_GREEN)[DIR_LIST_INCLUDE] $(subst $(DIR_ROOT)/,[DIR_ROOT]/,$(DIR_LIST_INCLUDE)) $(ECHO_END)
	@$(ECHO_GREEN)[DIR_LIST_DDL] $(subst $(DIR_ROOT)/,[DIR_ROOT]/,$(DIR_LIST_DDL)) $(ECHO_END)	
	@$(ECHO_GREEN)[DIR_LIST_DDL_NAME] $(subst $(DIR_ROOT)/,[DIR_ROOT]/,$(DIR_LIST_DDL_NAME)) $(ECHO_END)


# ------------------------------------------- 


$(DIR_OBJ_OUT)/%.o: %.c
	@$(MKDIR) `dirname $@`
	@$(ECHO_YELLOW)[$(COMPILE_C)]$< -o $@ $(ECHO_END)
	$(COMPILE_C) -c $(COMPILE_CFLAGS) $< -o $@

$(DIR_OBJ_OUT)/%.o: %.cpp
	@$(MKDIR) `dirname $@`
	@$(ECHO_YELLOW)[$(COMPILE_CXX)]$< -o $@ $(ECHO_END)
	$(COMPILE_CXX) -c $(COMPILE_CXXFLAGS) $< -o $@

$(DIR_OBJ_OUT)/%.o: %.s
	@$(MKDIR) `dirname $@`
	@$(ECHO_YELLOW)[$(COMPILE_C)]$< -o $@ $(ECHO_END)
	$(COMPILE_ASM) -c $(COMPILE_ASFLAGS) $< -o $@

 

$(FILE_LIST_LIB_APP): $(FILE_LIB_A)
	@$(MKDIR) `dirname $@`
	@$(ECHO_YELLOW)[$(COMPILE_C)]$< -o $@ $(ECHO_END)
	$(COMPILE_C) $(LDFLAGS) -L$(DIR_LIB) -lobj  $(DIR_LIST_DDL_NAME) -o $@
