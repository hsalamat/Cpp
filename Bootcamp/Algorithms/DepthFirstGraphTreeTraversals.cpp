/** @file DepthFirstGraphTreeTraversal.cpp
 *  @brief graph tree traversal - Depth First Search (DFS)
    Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have 
	only one logical way to traverse them, trees can be traversed in different ways.
	Depth First or Breadth First Traversals:

    A standard DFS implementation puts each vertex of the graph into one of two categories:

    Visited
    Not Visited
    The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

    The DFS algorithm works as follows:

    Start by putting any one of the graph's vertices on top of a stack.
    Take the top item of the stack and add it to the visited list.
    Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the top of the stack.
    Keep repeating steps 2 and 3 until the stack is empty.

    Application of DFS Algorithm
    For finding the path
    To test if the graph is bipartite (A bipartite graph, also called a bigraph, is a set of graph vertices decomposed into two disjoint sets such that no two graph vertices within the same set are adjacent.)
    For finding the strongly connected components of a graph
    For detecting cycles in a graph

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
// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(2);

    return 0;
}
