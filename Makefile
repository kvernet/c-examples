COMPILER = cc
CFLAGS   = -O02 -fPIC -Wall -Werror -Wextra
LDFLAGS  = -shared
LIB_SRCS = src/pstate.c \
           include/pstate.h \
           src/ptrack.c \
           include/ptrack.h


all: ptransport

ptransport: ptransport.c libptransport.so | bin
	$(COMPILER) $(CFLAGS) -o bin/$@ $< -Iinclude -Llib -lptransport -lm -Wl,-rpath=`pwd`/lib

bin:
	mkdir -p bin

libptransport.so: $(LIB_SRCS) | lib
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o lib/$@ $^ -Iinclude

lib:
	mkdir -p lib

clean:
	rm -rf bin
	rm -rf lib

.PHONY: all bin lib ptransport
