#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <iostream>

class Graph {
private:
    int vertices;
    std::vector<std::list<int>> adjList;
    bool isDirected;
    
    void DFSUtil(int vertex, std::vector<bool>& visited);

public:
    Graph(int v, bool directed = false);
    
    void addEdge(int src, int dest);
    
    void DFS(int startVertex);
    
    void BFS(int startVertex);
    
    int getVertices() const { return vertices; }
};

#endif
