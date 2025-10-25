#include <iostream>
#include "Graph1.h"

int main12() {   
    std::cout << "Неориентированный граф ---" << std::endl;
    Graph undirectedGraph(6, false);
    
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.addEdge(2, 4);
    undirectedGraph.addEdge(3, 5);
    undirectedGraph.addEdge(4, 5);
    
    std::cout << std::endl;
    
    undirectedGraph.DFS(0);
    undirectedGraph.BFS(0);
    
    std::cout << "\nОриентированный граф ---" << std::endl;
    Graph directedGraph(5, true);
    
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(2, 4);
    directedGraph.addEdge(3, 4);

    std::cout << std::endl;
    
    directedGraph.DFS(0);
    directedGraph.BFS(0);
    
    std::cout << "\nОбход с разных вершин ---" << std::endl;
    Graph graph(7, false);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    std::cout << std::endl;
    
    graph.DFS(0);
    graph.BFS(0);
    
    std::cout << "\nОбход с вершины 3:" << std::endl;
    graph.DFS(3);
    graph.BFS(3);
    
    return 0;
}
