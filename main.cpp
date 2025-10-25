#include <iostream>
#include "Graph.hpp"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Graph graph(false);

	//graph.addTop(10);
	//graph.addTop(17);
	//graph.addTop(22);
	//graph.addTop(33);
	//graph.addTop(1);

	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);


	std::cout << graph.hasTop(10) << "\n";
	std::cout << graph.hasEdge(4, 5) << "\n";

	graph.removeTop(10);
	graph.removeEdge(4, 5);

	std::cout << graph.hasTop(10) << "\n";
	std::cout << graph.hasEdge(4, 5) << "\n";


	Graph graph2(false);

	graph2.loadStations("stations.csv");
	graph2.loadFromCSV("connections.csv");

	int from = 1;   
	int to = 204;

	std::cout << "\n\n";

	auto path = graph2.dijkstra(from, to);
	graph2.printRoute(path);

	return 0;
}