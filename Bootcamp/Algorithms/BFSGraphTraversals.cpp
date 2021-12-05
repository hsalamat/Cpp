/** @file DepthFirstGraphTreeTraversal.cpp
 *  @brief graph tree traversal - Breadth First Search (BFS)
    A standard BFS implementation puts each vertex of the graph into one of two categories:

    Visited
    Not Visited
    The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

    The algorithm works as follows:

    Start by putting any one of the graph's vertices at the back of a queue.
    Take the front item of the queue and add it to the visited list.
    Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
    Keep repeating steps 2 and 3 until the queue is empty.
    The graph might have two different disconnected parts so to make sure that we cover every vertex, we can also run the BFS algorithm on every node

    BFS Algorithm Applications
    To build index by search index
    For GPS navigation
    Path finding algorithms
    In Ford-Fulkerson algorithm to find maximum flow in a network
    Cycle detection in an undirected graph
    In minimum spanning tree

    1.	BFS stands for Breadth First Search.	DFS stands for Depth First Search.
    2.	BFS(Breadth First Search) uses Queue data structure for finding the shortest path.	DFS(Depth First Search) uses Stack data structure.
    3.	BFS can be used to find single source shortest path in an unweighted graph, because in BFS, we reach a vertex with minimum number of edges from a source vertex.	In DFS, we might traverse through more edges to reach a destination vertex from a source.
    3.	BFS is more suitable for searching vertices which are closer to the given source.	DFS is more suitable when there are solutions away from source.
    4.	BFS considers all neighbors first and therefore not suitable for decision making trees used in games or puzzles.	DFS is more suitable for game or puzzle problems. We make a decision, then explore all paths through this decision. And if this decision leads to win situation, we stop.
    5.	The Time complexity of BFS is O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used, where V stands for vertices and E stands for edges.	The Time complexity of DFS is also O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used, where V stands for vertices and E stands for edges.

    Vector: Vector is a type of dynamic array which has the ability to resize automatically after insertion or deletion of elements. The elements in vector are placed in contiguous storage so that they can be accessed and traversed using iterators. Element is inserted at the end of the vector.
    Example:

    vector v;
    v.insert(5);
    v.delete();

    List: List is a double linked sequence that supports both forward and backward traversal. 
    The time taken in the insertion and deletion in the beginning, end and middle is constant. 
    It has the non-contiguous memory and there is no pre-allocated memory.
    Example:

    list  l;
    l.insert_begin(5);
    l.delete_end();


 *  @author Hooman Salamat
 *  @bug No known bugs.
 */
 // C++ program for different tree traversals

// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}