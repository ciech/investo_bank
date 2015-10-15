
PROJECT=digi.exe
CXX= g++
CXXFLAGS= -g -std=c++11 -Wpedantic -Wall -Wformat-security
INCLUDES= -Idigi/include
SRC_DIR=digi/src
OBJ_DIR=obj

SRC_CPP := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(addprefix obj/,$(notdir $(SRC_CPP:.cpp=.o)))


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

all: $(OBJS)
	mkdir -p obj
	$(CXX) $(FLAGS) $(OBJS) -o $(PROJECT)

clean:
	rm -fr $(OBJ_DIR)/*
	rm $(PROJECT)

.PHONY: all test
