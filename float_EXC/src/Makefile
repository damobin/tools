CC := gcc
CFLAGS := -fPIC -g -masm=intel
#加入宏 相当于#define DATAEXCMAINKEY
CFLAGS += -DDATAEXCMAINKEY

INC_DIR := -I ../include
INC_DIR += -I ../data

SRC_DIR := .
OBJ_DIR := $(SRC_DIR)/obj

TARGET_DIR := ../target
TARGET := Float_Exc_Int
#连接库文件
INSTALL_LIB_PATH := -L../lib
LINK :=
#包含所有以.a结尾的文件
LIB_TARGET := *.a

CFLAGS += $(INC_DIR)

SOURCE = $(wildcard $(SRC_DIR)/*.c)
SOURCER = $(notdir $(SOURCE))
OBJS = $(patsubst %.c,%.o,$(SOURCER))
OBJS := $(foreach X,$(OBJS),$(OBJ_DIR)/$(X))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "!!!!!"$(INC_DIR)
#生成可执行文件
$(TARGET):$(OBJS)
	$(CC) -o $(TARGET_DIR)/$(TARGET) $(OBJS) $(INSTALL_LIB_PATH) $(LINK)

	@echo "------------------------ MAKEFILE COMPLETE -----------------------"
#$(TARGET):$(OBJS)
#	$(CC) -o $(TARGET_DIR)/$(TARGET) $(OBJS) \
#	$(INSTALL_LIB_PATH)/$(LIB_TARGET)
#
#	@echo "------------------------ MAKEFILE COMPLETE -----------------------"

.PHONY:clean
clean:
	rm -rf $(OBJ_DIR)