#Executable Name
EXENAME = openflights
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = airport_mapper.o main.o graph.o flight.o djikstra.o landmark.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

test: output_msg catch/catchmain.cpp tests/tests.cpp graph.cpp airport_mapper.cpp djikstra.cpp flight.cpp landmark.cpp 
	$(LD) catch/catchmain.cpp tests/tests.cpp graph.cpp airport_mapper.cpp djikstra.cpp flight.cpp landmark.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test


