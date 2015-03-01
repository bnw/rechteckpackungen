CPP_FILES := $(wildcard **/*.cpp)
OBJ_FILES := $(CPP_FILES:.cpp=.o)
INC := -I ./lib/cute -I ./lib/boost

all: test.exe

test.exe: $(OBJ_FILES)
	g++ -g -o $@ $^

%.o: %.cpp
	g++ $(INC) -g -c -o $@ $<

.PHONY: clean

clean:
	-rm -f $(OBJ_FILES)