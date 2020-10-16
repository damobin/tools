#最外层的makefile负责创建相关目录和进入每个子目录去make

#后边里目录要根据前面一个的目录为基准
SUBDIRS = ./src
SUBDIRS +=

.PHONY:all
all:
	mkdir -p ./target
	mkdir -p ./src/obj
	
	@list='$(SUBDIRS)';for subdir in $$list; do \
		cd $$subdir && make; \
	done
	
.PHONY:clean
clean:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		echo "Clean in $$subdir";\
		cd $$subdir && make clean;\
	done
	rm -rf ./target