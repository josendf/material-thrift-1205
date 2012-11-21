PLATFORM_NAME     =linux32
WORKSPACE_USR_DIR =../../../usr/${PLATFORM_NAME}
INCS_DIRS         =-I${WORKSPACE_USR_DIR}/include \
		   -I${WORKSPACE_USR_DIR}/include/thrift
LIBS_DIRS         =-L${WORKSPACE_USR_DIR}/lib
CPP_OPTS          =-O2 -Wall -DHAVE_CONFIG_H
LIBS              =-lthrift -lthriftnb -levent

GEN_SRC = gen-cpp/MyService.cpp \
	  gen-cpp/example_constants.cpp \
	  gen-cpp/example_types.cpp

GEN_INC = -Igen-cpp

GEN_OBJ = $(patsubst %.cpp,%.o, $(GEN_SRC))

.PHONY: all clean

all: bindir server client

%.o: %.cpp
	$(CXX) ${CPP_OPTS} ${INCS_DIRS} ${GEN_INC} -c $< -o $@

server: Server.o $(GEN_OBJ)
	$(CXX) $^ -o bin/$@ ${LIBS_DIRS} ${LIBS}

client: Client.o $(GEN_OBJ)
	$(CXX) $^ -o bin/$@ ${LIBS_DIRS} ${LIBS}

bindir:
	mkdir -p bin

clean:
	$(RM) *.o gen-cpp/*.o bin/server bin/client
