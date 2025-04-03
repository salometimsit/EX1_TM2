# **Graph Algorithms Implementation Project**
Email: timsitmelosa@gmail.com
## **General explanation** 
In this Project I was asked to implement Algorthms such as: BFS, DFS, Dijakstra, Kruskal, Prim's using a adjencendy list https://en.wikipedia.org/wiki/Adjacency_list

In this Project I used a bunch of internet sites for help and insparation, all the bibliographes will be added at the end of this readme.

## **Technical Info**:
To run the project follow the following instructions:
1. Firstly, run the command: `make`
2. If you would like to run the main file enter: `./main`
3. In order to run tests all together run: `./test`
4. In order to clean files run: `make clean`
5. In order to test memory leaks with valgrind run: `make valgrind` and pay attention that because its linked to my main program to test all algorithms you have to do it several times.
## **Classes**:

### **Graph**:
In this class I implemented a graph using **adjacency list**.  
In this class we have a **Node** struct that keeps the pointer to the next node, the vertex and weight of the edge.  

**We have 7 functions in this class (constructor and destructor excluded):**

1. **initadjlist()** - This is a *private* function that is to initialize the graph at the begining.  
2. **int get_weight(int src, int dst)** - Function that returns an edge's weight between to given vertexes `src` and `dst`.  
3. **void Addedge(int src, int dst, int weight = 1)** - This function adds an edge between 2 vertexes given `src` and `dst` and the default weight will be 1 if we didnt specify otherwise.  
4. **void Removeedge(int src, int dst)** - Removes an edge by pointing to the next node in the list.  
5. **void print_graph()** - Print the graph given iterating throw the list.  
6. **bool hasedge(int src, int dst)** - This function added was to avoid checking everytime if the edge even exist in functions like add edge or remove edge.  
7. **int count_edge()** - Count the number of edges exists in a graph.

### **Priority Queue**:
I chose to use priority queue as my main structure because it can be easilly used for nearly all off the algorithms all I need to do was change the priorities, it will be more explained in the algorithm class specifically in BFSS, DFS.

The priority queue works that we can chose to put different priorities and the one with the less priority will be the first one to be popped, if I want the queue to behave like a standart queue I will put prioritys going up from the first to the n index. because I implemented it as a min-heap.

In this class we have a **Node** (I could've called it differently), struct that keeps the value and the priority.
In addition, I implemented priority queue as a min-heap so it can work easly with DIjakstra's algorithm.

**We have 7 functions in this class (constructor and destructor excluded):**

1. **void swap(Node &a, Node &b)** - Change between two nodes
2. **void heapifyup(int index)** - Keeping the heaps properties by moving the index up
3. **void heapifydown(int index)** - Keeping the heaps properties by moving the index down
4. **void push(int value, int priority)** - Enetring a new value into the priority queue
5. **int pop()** - Extracting the most priority value in the queue
6. **int top()** - Showing the most priority value in the queue

### **Union-Find**:
In this Class I implemented the union-find struct in order to implement the kruskal's Algorithm. I have a struct named **Nodeu** that has a pointer to the nodes representative, the nodes next and the constructor of the node (I put it inside the struct so that it will be initialized). 

**We have 3 functions in this class (constructor and destructor excluded):**

1. **Nodeu* find(Nodeu* x)** - This function return the nodes representative
2. **void add(Nodeu* x, Nodeu* y)** - Combines two nodes together when one of them representative will be boths.
3. **Nodeu* getNode(int index)** - Returns me a node in a specific index.

### **Algorithms**:
In this class we have a few interesting functions and implements this is basically the union class of the project, all the other classes help for this class.

**We have 5 functions in this class (constructor and destructor excluded):**

1. **BFS** - As learned in algorithm 1 course it performs Breadth-First Search starting from vertex ori(for original) and returns the traversal as a graph. 

2. **DFS** - As learned in algorithm 1 course it performs Depth-First Search starting from vertex ori(for original) and returns the traversal as a graph.  

3. **Dijakstra** - As learned in algorithm 1 course this algorithm returns shortest path from vertex original.

4. **Prim's** - As learned in algorithm 1 course we use Prim's algorithm to find the Minimum Spanning Tree starting from original by adding everytime a new vertex and chosing the minimum edge from the "discovered" vertexes.

5. **Kruskal** - As learned in algorithm 1 course we use kruskal's algorithm to find the Minimum Spanning Tree by sorting the edgess and chosing the edges that are the minimum and that do not close a circle.
   - For kruskal I used a helper function: **void bubbleSort**

## **Tests and Makefile**:
- in my test casses i tried to make as much as possible edge casses such as what if i add an edge from u to v with weight 5 but from v to u with weight 3? 
you can see each class has a test file that includes doctest.h and i hae a main file for all the tests to run alltogether.

- In the makefile I implemented all the categories:
make Main 
make test 
make valgrind 
make clean

## **Bibliograpy:**
- Algorithm knowledge from course Algorithm 1 in Ariel University.

https://www.geeksforgeeks.org/cpp-program-to-implement-adjacency-matrix/

https://rollbar.com/blog/error-exceptions-in-c/#:~:text=An%20exception%20in%20C%2B%2B%20is,immediately%20after%20the%20try%20block.

https://www.geeksforgeeks.org/introduction-to-min-heap-data-structure/

https://stackoverflow.com/questions/49802012/different-ways-of-initializing-an-object-in-c

https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

https://www.geeksforgeeks.org/detect-cycle-in-graph-using-dsu/

https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/
https://codescracker.com/cpp/program/cpp-program-bubble-sort.htm

https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

https://www.youtube.com/watch?v=CerlT7tTZfY

