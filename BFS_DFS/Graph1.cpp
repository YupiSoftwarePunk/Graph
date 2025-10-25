#include "Graph1.h"

Graph::Graph(int v, bool directed) : vertices(v), isDirected(directed) {
    adjList.resize(v);
}

void Graph::addEdge(int src, int dest) {
    if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
        std::cout << "Ошибка: неверные индексы вершин!" << std::endl;
        return;
    }
    
    adjList[src].push_back(dest);
    
    if (!isDirected) {
        adjList[dest].push_back(src);
    }
}

void Graph::DFSUtil(int vertex, std::vector<bool>& visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";
    
    for (int adjacent : adjList[vertex]) {
        if (!visited[adjacent]) {
            DFSUtil(adjacent, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    if (startVertex < 0 || startVertex >= vertices) {
        std::cout << "Ошибка: неверный начальный индекс!" << std::endl;
        return;
    }
    
    std::vector<bool> visited(vertices, false);
    
    std::cout << "Обход в глубину (DFS) начиная с вершины " << startVertex << ": ";
    DFSUtil(startVertex, visited);
    std::cout << std::endl;
}

void Graph::BFS(int startVertex) {
    if (startVertex < 0 || startVertex >= vertices) {
        std::cout << "Ошибка: неверный начальный индекс!" << std::endl;
        return;
    }
    
    std::vector<bool> visited(vertices, false);
    std::queue<int> queue;
    
    visited[startVertex] = true;
    queue.push(startVertex);
    
    std::cout << "Обход в ширину (BFS) начиная с вершины " << startVertex << ": ";
    
    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        std::cout << currentVertex << " ";
        
        for (int adjacent : adjList[currentVertex]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
    
    std::cout << std::endl;
}
