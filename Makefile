CPP_FILES := $(wildcard **/*.cpp)
OBJ_FILES := $(CPP_FILES:.cpp=.o)
INC := -I ./lib/cute -I ./lib/boost
FLAGS := -std=c++11 -g 

all: test.exe

test.exe: $(OBJ_FILES)
	g++ $(FLAGS) -o $@ $^ 

%.o: %.cpp
	g++ $(INC) $(FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	-rm -f $(OBJ_FILES)