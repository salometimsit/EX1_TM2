//#include "Graph.hpp"
//#include <Graph.cpp>
// using namespace graph;
// using namespace std;
// int main()
// {
//     graph::Graph g(6);

//     // Add edges
//     g.Addedge(0, 3);
//     g.Addedge(0, 4);
//     g.Addedge(1, 4);
//     g.Addedge(1, 5);
//     g.Addedge(1, 2);
//     g.Addedge(2, 5);
//     g.Addedge(2, 3);
//     g.Addedge(3, 5);
//     g.Addedge(4, 5);

//     // Print the adjacency matrix
//     g.print_graph();

//     // Try removing an edge
//     try {
//         g.Removeedge(0, 3);
//         cout << "\nAfter removing edge (0,3):" << endl;
//         g.print_graph();
//     } catch (exception& e) {
//         cout << e.what() << endl;
//     }

//     return 0;
// }
#include <iostream>
using namespace std;
#include "Priority_queue.hpp"

// Make sure to include the Priority_queue class either by:
// 1. Including the header file if you have one
// #include "Priority_qeue.h"
// 2. Or ensure the class definition is included before main
// (if both files are compiled together)

int main() {
    // Create a priority queue with capacity 10
    Priority_queue pq(10);
    
    cout << "Testing priority queue operations:" << endl;
    
    // Test push operations
    cout << "\nPushing elements with different priorities:" << endl;
    pq.push(100, 3);  // Value 100 with priority 3
    pq.push(200, 1);  // Value 200 with priority 1 (higher priority)
    pq.push(300, 4);  // Value 300 with priority 4
    pq.push(400, 2);  // Value 400 with priority 2
    pq.push(500, 5);  // Value 500 with priority 5
    
    // Test top operation
    cout << "Top element (should be 200): " << pq.top() << endl;
    
    // Test pop operations
    cout << "\nPopping elements (should come out in priority order):" << endl;
    cout << "Pop 1: " << pq.pop() << endl;  // Should be 200 (priority 1)
    cout << "Pop 2: " << pq.pop() << endl;  // Should be 400 (priority 2)
    cout << "Pop 3: " << pq.pop() << endl;  // Should be 100 (priority 3)
    
    // Test top after several pops
    cout << "Top element after 3 pops (should be 300): " << pq.top() << endl;
    
    // Test more pops
    cout << "\nPopping remaining elements:" << endl;
    cout << "Pop 4: " << pq.pop() << endl;  // Should be 300 (priority 4)
    cout << "Pop 5: " << pq.pop() << endl;  // Should be 500 (priority 5)
    
    // Test empty queue behavior
    cout << "\nTesting empty queue behavior:" << endl;
    cout << "Pop on empty queue: " << pq.pop() << endl;
    cout << "Top on empty queue: " << pq.top() << endl;
    
    // Test refilling the queue
    cout << "\nRefilling the queue:" << endl;
    pq.push(150, 2);
    pq.push(250, 1);
    cout << "Top element after refill (should be 250): " << pq.top() << endl;
    
    // Test capacity limit
    cout << "\nTesting capacity limits:" << endl;
    for (int i = 0; i < 8; i++) {  // Push 8 more (already have 2)
        pq.push(i * 100, 10 - i);
    }
    
    return 0;
}