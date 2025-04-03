# קובץ Makefile לפרויקט גרפים - תומך בהרצה, בדיקות, ולגרינד
#Email: timsitmelosa@gmail.com
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = Algorithms.cpp Graph.cpp Priority_queue.cpp Union_find.cpp
HEADERS = Algorithms.hpp Graph.hpp Priority_queue.hpp Union_find.hpp

MAIN = main.cpp
TEST = All_test.cpp 

OBJS = $(SRC:.cpp=.o)

main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(MAIN)

test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o test $(SRC) $(TEST)
	./test

valgrind: main
	valgrind --leak-check=full ./main
clean:
	rm -f *.o test main *.out *.exe
