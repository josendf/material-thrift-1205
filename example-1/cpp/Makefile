LIBS_DIRS :=-L${HOME}/usr/thrift-0.8.0/lib -L${HOME}/usr/lib

INCS_DIRS :=-I${HOME}/usr/thrift-0.8.0/include/thrift -I${HOME}/usr/include -Igen-cpp

CPP_OPTS  :=-std=c++0x -DHAVE_CONFIG_H

WRN_OPTS  :=-Wall -Wextra -pedantic

CPP_LIBS  :=-lthrift

GEN_SRC   := gen-cpp/MyService.cpp gen-cpp/example_constants.cpp gen-cpp/example_types.cpp

GEN_OBJ   := $(patsubst %.cpp,%.o, $(GEN_SRC))

.PHONY: all clean

all: server client

%.o: %.cpp
	$(CXX) $(WRN_OPTS) ${CPP_OPTS} ${INCS_DIRS} -c $< -o $@

server: Server.o $(GEN_OBJ)
	$(CXX) $^ -o $@ ${LIBS_DIRS} ${CPP_LIBS}

client: Client.o $(GEN_OBJ)
	$(CXX) $^ -o $@ ${LIBS_DIRS} ${CPP_LIBS}

clean:
	$(RM) *.o gen-cpp/*.o server client

