#pragma once

#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>


struct Edge {
	int to;
	int weight;
};


struct Station {
	int id;
	std::string name;
	int line_id;
	std::string line_name;
	std::string line_color;
};


class Graph
{
public:
	Graph(bool directed) : isDirected_(directed) {}


	// Добавление вершины
	void addTop(int top);

	// Добавление ребра
	void addEdge(int from, int to);

	// Удаление вершины
	void removeTop(int top);

	// Удаление ребра
	void removeEdge(int from, int to);

	bool hasTop(int top);

	bool hasEdge(int from, int to);


	void loadFromCSV(const std::string& filename);

	std::vector<int> dijkstra(int start, int end);

	void loadStations(const std::string& filename);

	void printRoute(const std::vector<int>& path);


private:
	std::unordered_map<int, std::list<int>> list_;
	bool isDirected_;

	std::unordered_map<int, std::vector<Edge>> adj_;

	std::unordered_map<int, Station> stations_;
};

