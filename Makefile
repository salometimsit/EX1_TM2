# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Executable Name
TARGET = graph_exec

# Source and Object Files
SRCS = main.cpp Graph.cpp Algorithms.cpp Priority_queue.cpp Union_find.cpp
OBJS = $(SRCS:.cpp=.o)

# Default Rule: Build the Executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile Each `.cpp` File Into a `.o` File
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Explicitly Define Union_find.o Rule
Union_find.o: Union_find.cpp Union_find.hpp
	$(CXX) $(CXXFLAGS) -c Union_find.cpp -o Union_find.o

# Clean Command to Remove Compiled Files
clean:
	rm -f $(OBJS) $(TARGET) *.gch
