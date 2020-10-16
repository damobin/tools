#CC := g++
#TYPE := cpp
CC := gcc
TYPE := c
CFLAGS := -fPIC -g 
CFLAGSLINK := -L ../lib
#-masm=intel  嵌入intel汇编

INC_DIR := -I ../include
INC_DIR += -I ../data

LIB_DIR :=
LIB_DIR +=

GLOBAL_LIB_FILE := -lws2_32
GLOBAL_LIB_FILE += -lstdc++
GLOBAL_LIB_FILE += -lpthread
SRC_DIR := .
OBJ_DIR := $(SRC_DIR)/obj

TARGET_DIR := ../target
TARGET := CHECK_DIFF

INSTALL_LIB_PATH :=
#INSTALL_LIB_PATH += -L F:\soft\Ming_X86\mingw64\x86_64-w64-mingw32\lib\

#lib += -lpthread libwsock32 libws2_32
#包含所有以.a结尾的文件
LIB_TARGET := *.a

#头文件添加
CFLAGS += $(INC_DIR)

#库路径添加
CFLAGSLINK += $(INSTALL_LIB_PATH)
#库文件添加	
CFLAGSLINK += $(LIB_DIR)
#动态库添加	
CFLAGSLINK += $(GLOBAL_LIB_FILE)



SOURCE = $(wildcard $(SRC_DIR)/*.$(TYPE))
SOURCER = $(notdir $(SOURCE))
OBJS = $(patsubst %.$(TYPE),%.o,$(SOURCER))
OBJS := $(foreach X,$(OBJS),$(OBJ_DIR)/$(X))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(TYPE)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "!!!!!"$(INC_DIR)
#生成可执行文件
#连接库必须放在link阶段的最后边!!!!!!!!!!
$(TARGET):$(OBJS)
	$(CC) -o $(TARGET_DIR)/$(TARGET) $(OBJS) $(CFLAGSLINK)

	@echo "------------------------ MAKEFILE COMPLETE -----------------------"
#$(TARGET):$(OBJS)
#	$(CC) -o $(TARGET_DIR)/$(TARGET) $(OBJS) \
#	$(INSTALL_LIB_PATH)/$(LIB_TARGET)
#
#	@echo "------------------------ MAKEFILE COMPLETE -----------------------"

.PHONY:clean
clean:
	rm -rf $(OBJ_DIR)