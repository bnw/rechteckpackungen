rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

COMPILER = g++

OBJDIR_PRODUCTION = _build/Production
OBJDIR_DEBUG = _build/Debug

CPP_FILES_MAIN = $(call rwildcard,src/,*.cpp)
CPP_FILES_TESTS = $(filter-out src/main.cpp,$(CPP_FILES_MAIN)) $(call rwildcard,tests/,*.cpp)

CODE_COVERAGE_FILES = $(call rwildcard,./,*.gcda) $(call rwildcard,./,*.gcno) $(call rwildcard,./,*.gcov)

OBJ_FILES_MAIN = $(CPP_FILES_MAIN:.cpp=.o)
OBJ_FILES_TESTS = $(CPP_FILES_TESTS:.cpp=.o)

OBJ_FILES_MAIN_PRODUCTION = $(addprefix $(OBJDIR_PRODUCTION)/, $(OBJ_FILES_MAIN))
OBJ_FILES_MAIN_DEBUG = $(addprefix $(OBJDIR_DEBUG)/, $(OBJ_FILES_MAIN)) 
OBJ_FILES_TESTS_DEBUG = $(addprefix $(OBJDIR_DEBUG)/, $(OBJ_FILES_TESTS)) 

INC_PRODUCTION = -I./src
INC_DEBUG = -I ./lib/cute -I ./lib/boost $(INC_PRODUCTION)
FLAGS_PRODUCTION = -std=c++11 -O3
FLAGS_DEBUG = -std=c++11 -g -O0 -ftest-coverage -fprofile-arcs -Wall

EXECUTABLE_MAIN_PRODUCTION = rechteckpackungen.exe
EXECUTABLE_MAIN_DEBUG = rechteckpackungen_debug.exe
EXECUTABLE_TESTS_DEBUG = tests.exe

all: production tests debug

production: $(EXECUTABLE_MAIN_PRODUCTION)

debug: $(EXECUTABLE_MAIN_DEBUG)

tests: $(EXECUTABLE_TESTS_DEBUG)

$(EXECUTABLE_MAIN_PRODUCTION): $(OBJ_FILES_MAIN_PRODUCTION)
	$(COMPILER) $(FLAGS_PRODUCTION) -o $@ $^

$(EXECUTABLE_MAIN_DEBUG): $(OBJ_FILES_MAIN_DEBUG)
	$(COMPILER) $(FLAGS_DEBUG) -o $@ $^

$(EXECUTABLE_TESTS_DEBUG): $(OBJ_FILES_TESTS_DEBUG)
	$(COMPILER) $(FLAGS_DEBUG) -o $@ $^

$(OBJDIR_PRODUCTION)/%.o: %.cpp
	@mkdir -p $(@D)
	$(COMPILER) $(INC_PRODUCTION) $(FLAGS_PRODUCTION) -c -o $@ $<

$(OBJDIR_DEBUG)/%.o: %.cpp
	@mkdir -p $(@D)
	$(COMPILER) $(INC_DEBUG) $(FLAGS_DEBUG) -c -o $@ $<

clean: clean_executables clean_code_coverage
	-rm -rf $(OBJDIR_PRODUCTION) $(OBJDIR_DEBUG) test.exe.xml

clean_executables:
	-rm -f $(EXECUTABLE_MAIN_PRODUCTION) $(EXECUTABLE_MAIN_DEBUG) $(EXECUTABLE_TESTS)
	
clean_code_coverage:
	-rm -f $(CODE_COVERAGE_FILES)
	
.PHONY: clean all clean_executables clean_code_coverage production debug tests
