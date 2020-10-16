PARE = $(HOST_CFLAGS)

DIR_INC = -I./include
DIR_INC += -I./data
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin
DIR_LIB = ./lib
AR      = ar
RANLIB  = ranlib
TAR_GET = libcrc.a
SRC = $(wildcard ${DIR_SRC}/*.c)  
#文件路径+***.o
OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC})) 

TARGET = main

BIN_TARGET = ${DIR_BIN}/${TARGET}
LIB_TARGET = ${DIR_LIB}/${TAR_GET}
CC = gcc
CFLAGS = -g -Wall ${DIR_INC}


LINK_PATH = -L./lib
LINK_PATH += 

LINK_LIBS = -lcrc
LINK_FLAGS = $(LINK_PATH)
LINK_FLAGS += $(LINK_LIBS)
#生成可执行文件
ifneq ($(HOST_CFLAGS), TRUE)
${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ)  -o $@ $(LINK_FLAGS)
	
else
#生成动态库
${LIB_TARGET}:${OBJ}
	${AR} cru ${LIB_TARGET} $(OBJ)
	${RANLIB} ${LIB_TARGET}
endif



${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c -fPIC $< -o $@
.PHONY:clean
clean:
	rm ${DIR_OBJ}/*.o
	rm ${DIR_BIN}/*
	rm ${DIR_LIB}/*	