#include "Graph.hpp"

void Graph::addTop(int top)
{
    if (list_.find(top) == list_.end())
    {
        list_[top] = std::list<int>();
    }
}



void Graph::addEdge(int from, int to)
{
    addTop(from);
    addTop(to);

    list_[from].push_back(to);

    if (!isDirected_)
    {
        list_[to].push_back(from);
    }
}



void Graph::removeTop(int top)
{
    if (list_.find(top) == list_.end()) return;

    if (!isDirected_) 
    {
        for (auto& pair : list_) 
        {
            pair.second.remove(top);
        }
    }
    else 
        for (auto& pair : list_) 
        {
            if (pair.first != top) 
            {
                pair.second.remove(top);
            }
        }

    list_.erase(top);
}



void Graph::removeEdge(int from, int to)
{
    if (list_.find(from) != list_.end())
    {
        list_[from].remove(to);
    }

    if (!isDirected_ && list_.find(to) != list_.end())
    {
        list_[to].remove(from);
    }
}



bool Graph::hasTop(int top)
{
    return list_.find(top) != list_.end();
}



bool Graph::hasEdge(int from, int to)
{
    if (list_.find(from) != list_.end())
    {
        return true;
    }

    if (!isDirected_ && list_.find(to) != list_.end())
    {
        return true;
    }
}



void Graph::loadFromCSV(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string fromStr, toStr, timeStr;

        std::getline(ss, fromStr, ';');
        std::getline(ss, toStr, ';');
        std::getline(ss, timeStr, ';');

        int from = std::stoi(fromStr);
        int to = std::stoi(toStr);
        int time = std::stoi(timeStr);

        adj_[from].push_back({ to, time });
        adj_[to].push_back({ from, time }); // граф не направленный
    }
}



std::vector<int> Graph::dijkstra(int start, int end)
{
    std::unordered_map<int, int> dist;
    std::unordered_map<int, int> prev;
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>> pq;

    for (const auto& pair : adj_)
        dist[pair.first] = std::numeric_limits<int>::max();

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        if (current == end) break;

        for (const Edge& edge : adj_[current])
        {
            int alt = dist[current] + edge.weight;
            if (alt < dist[edge.to])
            {
                dist[edge.to] = alt;
                prev[edge.to] = current;
                pq.push({ alt, edge.to });
            }
        }
    }

    std::vector<int> path;
    for (int at = end; at != start; at = prev[at])
    {
        path.push_back(at);
        if (prev.find(at) == prev.end()) return {}; // путь не найден
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}



void Graph::loadStations(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // пропускаем заголовок

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string idStr, name, lineIdStr, lineName, lineColor;

        std::getline(ss, idStr, ';');
        std::getline(ss, name, ';');
        std::getline(ss, lineIdStr, ';');
        std::getline(ss, lineName, ';');
        std::getline(ss, lineColor, ';');

        Station station;
        station.id = std::stoi(idStr);
        station.name = name;
        station.line_id = std::stoi(lineIdStr);
        station.line_name = lineName;
        station.line_color = lineColor;

        stations_[station.id] = station;
    }
}



void Graph::printRoute(const std::vector<int>& path)
{
    if (path.empty())
    {
        std::cout << "Маршрут не найден.\n";
        return;
    }

    std::cout << "Маршрут:\n";
    for (size_t i = 0; i < path.size(); ++i)
    {
        const Station& st = stations_[path[i]];
        std::cout << st.name << " (" << st.line_name << ", " << st.line_color << ")";
        if (i < path.size() - 1)
        {
            const Station& next = stations_[path[i + 1]];
            if (st.line_id != next.line_id)
            {
                std::cout << " → [Пересадка на " << next.line_name << "] → ";
            }
            else
            {
                std::cout << " → ";
            }
        }
    }
    std::cout << "\n";
}
