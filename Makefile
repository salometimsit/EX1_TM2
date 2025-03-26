
CXX = clang++-9
CXXFLAGS =-std=c++2a 
RM=rm -f

TARGET = graph 
SRCS = main.cpp Graph.cpp Algorithms.cpp Priority_queue.cpp Union_find.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Union_find.o: Union_find.cpp Union_find.hpp
	$(CXX) $(CXXFLAGS) -c Union_find.cpp -o Union_find.o

valgrind:
	valgrind --tool=memcheck $(TARGET)
clean:
	$(RM) $(OBJS) $(TARGET) *.gch
