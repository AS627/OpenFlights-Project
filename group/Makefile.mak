
CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++11 -stdlib=libc++ -lc++abi -lm
include clang_enforcement.mk

main.o:	main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

dijkstra.o: dijkstra.cpp
	$(CXX) $(CXXFLAGS) dijkstra.cpp

BFS.o: BFS.cpp
	$(CXX) $(CXXFLAGS) BFS.cpp

iterativeDFS.o: iterativeDFS.cpp
	$(CXX) $(CXXFLAGS) iterativeDFS.cpp

dataExtract.o: dataExtract.cpp
	$(CXX) $(CXXFLAGS) dataExtract.cpp

mapper.o: mapper.cpp
	$(CXX) $(CXXFLAGS) mapper.cpp

