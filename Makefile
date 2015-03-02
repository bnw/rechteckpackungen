rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CPP_FILES := $(call rwildcard,src/,*.cpp) $(call rwildcard,tests/,*.cpp)
OBJ_FILES := $(CPP_FILES:.cpp=.o)
INC := -I ./lib/cute -I ./lib/boost -I./src
FLAGS := -std=c++11 -g 

all: test.exe

test.exe: $(OBJ_FILES)
	g++ $(INC) $(FLAGS) -o $@ $^ 

%.o: %.cpp
	g++ $(INC) $(FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	-rm -f $(OBJ_FILES)