rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

COMPILER = g++

CPP_FILES_SRC = $(call rwildcard,src/,*.cpp)
CPP_FILES_TESTS = $(filter-out src/main.cpp,$(CPP_FILES_SRC)) $(call rwildcard,tests/,*.cpp)

CODE_COVERAGE_FILES = $(call rwildcard,./,*.gcda) $(call rwildcard,./,*.gcno) $(call rwildcard,./,*.gcov)

OBJ_FILES_SRC = $(CPP_FILES_SRC:.cpp=.o)
OBJ_FILES_TESTS = $(CPP_FILES_TESTS:.cpp=.o)

INC = -I./src
INC_TESTS = -I ./lib/cute -I ./lib/boost $(INC)
FLAGS_DEVELOPMENT = -std=c++11 -g -O2 -ftest-coverage -fprofile-arcs
FLAGS_PRODUCTION = -std=c++11 -O3
FLAGS = $(FLAGS_PRODUCTION)

EXECUTABLE_MAIN = rechteckpackungen.exe
EXECUTABLE_TESTS = test.exe

all: $(EXECUTABLE_MAIN) $(EXECUTABLE_TESTS)

$(EXECUTABLE_MAIN): $(OBJ_FILES_SRC) 
	$(COMPILER) $(FLAGS) -o $@ $^

$(EXECUTABLE_TESTS): $(OBJ_FILES_TESTS)
	$(COMPILER) $(INC) $(FLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(COMPILER) $(INC) $(FLAGS) -c -o $@ $<

tests/%.o: tests/%.cpp
	$(COMPILER) $(INC_TESTS) $(FLAGS) -c -o $@ $<

lib/%.o: lib/%.cpp
	$(COMPILER) $(FLAGS) -c -o $@ $<

clean: clean_executables clean_code_coverage
	-rm -f $(OBJ_FILES_SRC) $(OBJ_FILES_TESTS) test.xml

clean_executables:
	-rm -f $(EXECUTABLE_MAIN) $(EXECUTABLE_TESTS) 
	
clean_code_coverage:
	-rm -f $(CODE_COVERAGE_FILES)
	
.PHONY: clean all clean_executables clean_code_coverage

.DELETE_ON_ERROR: $(EXECUTABLE_MAIN) $(EXECUTABLE_TESTS) %.o