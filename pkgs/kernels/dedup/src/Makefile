# Makefile for dedup kernel

PREFIX=${PARSECDIR}/pkgs/kernels/dedup/inst/${PARSECPLAT}

TARGET=dedup

BIGFILE_CFLAGS=$(shell getconf LFS_CFLAGS)

CFLAGS += -Wall -std=c99 -fno-strict-aliasing -D_XOPEN_SOURCE=600
CXXFLAGS += -Wall -fno-strict-aliasing -D_XOPEN_SOURCE=600 -g
LIBS += -lcrypto -lz

DEDUP_OBJ =  hashtable.o queue.o util.o binheap.o tree.o decoder.o dedup.o rabin.o #encoder.o

ifdef version
  ifeq "$(version)" "pthreads"
    CFLAGS += -DPTHREADS -pthread
    COMPILER=$(CC)
    COMPILER_FLAGS=$(CFLAGS)
    DEDUP_OBJ += encoder.o
  endif
  ifeq "$(version)" "tbb"
    CFLAGS += -DPTHREADS -DTBB
    CXXFLAGS += -DPTHREADS -DTBB -I${PARSECDIR}/pkgs/libs/ssl/inst/amd64-linux.gcc-tbb/include -I${PARSECDIR}/pkgs/libs/zlib/inst/amd64-linux.gcc-tbb/include
    COMPILER=$(CXX)
    COMPILER_FLAGS=$(CXXFLAGS)
    DEDUP_OBJ += encoder-tbb.o
  endif
  ifeq "$(version)" "taskflow"
    CFLAGS += -DPTHREADS
    CXXFLAGS += -DPTHREADS -I${PARSECDIR}/pkgs/libs/ssl/inst/amd64-linux.gcc-taskflow/include -I${PARSECDIR}/pkgs/libs/zlib/inst/amd64-linux.gcc-taskflow/include -I/home/zhicheng/taskflow/taskflow/algorithm/ 
    CXXFLAGS += -std=c++17 -fexceptions
    COMPILER=$(CXX)
    COMPILER_FLAGS=$(CXXFLAGS)
    LIBS += -lpthread
    DEDUP_OBJ += encoder-taskflow.o
  endif
endif

# $(info CFLAGS is $(CFLAGS))
# $(info COMPILER_FLAGS is $(COMPILER_FLAGS))


all: $(TARGET)

.c.o:
# $(CC) -c $(CFLAGS) $< -o $@
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(TARGET): $(DEDUP_OBJ)
	$(COMPILER) $(COMPILER_FLAGS) $(LDFLAGS) -o $(TARGET) $(DEDUP_OBJ) $(LIBS)
	#$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(DEDUP_OBJ) $(LIBS)

clean:
	rm -f *~ *.o $(TARGET)

install:
	mkdir -p $(PREFIX)/bin
	cp -f $(TARGET) $(PREFIX)/bin/$(TARGET)

