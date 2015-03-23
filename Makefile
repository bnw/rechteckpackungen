rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CPP_FILES_SRC = $(call rwildcard,src/,*.cpp)
CPP_FILES_TESTS = $(filter-out src/main.cpp,$(CPP_FILES_SRC)) $(call rwildcard,tests/,*.cpp)

CODE_COVERAGE_FILES = $(call rwildcard,./,*.gcda) $(call rwildcard,./,*.gcno) $(call rwildcard,./,*.gcov)

OBJ_FILES_SRC = $(CPP_FILES_SRC:.cpp=.o)
OBJ_FILES_TESTS = $(CPP_FILES_TESTS:.cpp=.o)

INC = -I ./lib/cute -I ./lib/boost -I./src
FLAGS = -std=c++11 -g -o0 -ftest-coverage -fprofile-arcs

EXECUTABLE_MAIN = rechteckpackungen.exe
EXECUTABLE_TESTS = test.exe

all: clean_executables $(EXECUTABLE_MAIN) $(EXECUTABLE_TESTS)

$(EXECUTABLE_MAIN): $(OBJ_FILES_SRC)
	g++ $(FLAGS) -o $@ $^ 

$(EXECUTABLE_TESTS): $(OBJ_FILES_TESTS)
	g++ $(INC) $(FLAGS) -o $@ $^ 

%.o: %.cpp
	g++ $(INC) $(FLAGS) -c -o $@ $<

clean: clean_executables clean_code_coverage
	-rm -f $(OBJ_FILES_SRC) $(OBJ_FILES_TESTS) test.xml

clean_executables:
	-rm -f $(EXECUTABLE_MAIN) $(EXECUTABLE_TESTS) 
	
clean_code_coverage:
	-rm -f $(CODE_COVERAGE_FILES)

.PHONY: clean all