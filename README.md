# **General explanation** 
In this Project I was asked to implement Algorthms such as: BFS,DFS, Dijakstra,Kruskal,Prim's using a adjencendy list https://en.wikipedia.org/wiki/Adjacency_list

In this Project I used a bunch of internet sites for help and insparation, all the bibliographes will be added at the end of this readme.
## **Classes:**
## **Graph**:
- in this class i implemented a graph using **adjacency list**,  
in this class we have a **Node** struct that keeps the pointer to the next node, the vertex and weight of the edge.  

    **We have 7 functions in this class (constructor and destructor excluded):**

1. **initadjlist()** - this is a *private* function that is to initialize the graph at the begining.  
2. **int get_weight(int src, int dst)** - function that returns an edge's weight between to given vertexes `src` and `dst`.  
3. **void Addedge(int src, int dst, int weight = 1)** - this function adds an edge between 2 vertexes given `src` and `dst` and the default weight will be 1 if we didnt specify otherwise.  
4. **void Removeedge(int src, int dst)** - removes an edge by pointing to the next node in the list.  
5. **void print_graph()** - print the graph given iterating throw the list.  
6. **bool hasedge(int src, int dst)** - this function added was to avoid checking everytime if the edge even exist in functions like add edge or remove edge.  
7. **int count_edge()** - count the number of edges exists in a graph.

## **Priority Queue:**
- I chose to use priority queue as my main structure because it can be easilly used for nearly all off the algorithms all i need to do was change the priorities, it will be more explained in the algorithm class specifically in BFSS,DFS .
The priority queue works that we can chose to put different priorities and the one with the less priority will be the first one to be popped, if i want the queue to behave like  a standart queue i will put prioritys going up from the first to the n index. because i implemented it as a min-heap.
in this class we have a **Node**(I could've called it differently), struct that keeps the value and the priority.
In addition, i implemented priority queue as a min-heap so it can work easly with DIjakstra's algorithm.

 **We have 7 functions in this class (constructor and destructor excluded):**

**1. void swap(Node &a, Node &b)-** change between two nodes

**2. void heapifyup(int index)-** keeping the heaps properties by moving the index up

**3. void heapifydown(int index)-** keeping the heaps properties by moving the index down

**4. void push(int value, int priority)-** enetring a new value into the priority queue

**5. int pop()-** extracting the most priority value in the queue

**6. int top()**-showing the most priority value in the queue

## **Union-Find:**
- In this Class i implemented the union- find struct in  order to implement the kruskal's Algorithm. i have a struct named **Nodeu** that has a pointer to the nodes representative, the nodes next and the constructor of the node(i put it inside the struct so that it will be initialized). 

**We have 3 functions in this class (constructor and destructor excluded):**

**1. Nodeu*find(Nodeu* x)-** this function return the nodes representative

**2. voidadd(Nodeu* x, Nodeu* y)-** combines two nodes together when one of them representative will be boths.
**3. Nodeu* getNode(int index)-** returns me a node in a specific index.

## **Algorithms**:
- in this class we have a few interesting functions and implements this is basically the union class of the project, all the other classes help for this class.
**We have 3 functions in this class (constructor and destructor excluded):**

**1. BFS-** as learned in algorithm 1 course it performs Breadth-First Search starting from vertex ori(for original) and returns the traversal as a graph. 

**2. DFS-** as learned in algorithm 1 course it performs Depth-First Search starting from vertex ori(for original) and returns the traversal as a graph.  


**3. Dijakstra-** as learned in algorithm 1 course this algorithm returns shortest path from vertex original.

**4. Prim's-** as learned in algorithm 1 course we use Prim's algorithm to find the Minimum Spanning Tree starting from original by adding everytime a new vertex and chosing the minimum edge from the "discovered" vertexes.

**5. Kruskal-**  as learned in algorithm 1 course we use kruskal's algorithm to find the Minimum Spanning Tree by sorting the edgess and chosing the edges that are the minimum and that do not close a circle.
- for kruskal i used a helper functions: 
    **void bubbleSort** 
## **Tests and Makefile**

