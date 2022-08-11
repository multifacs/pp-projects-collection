// Copyright 2022 Shelepin Nikita
#ifndef MODULES_OMP_DIJKSTRA_DIJKSTRA_H_
#define MODULES_OMP_DIJKSTRA_DIJKSTRA_H_

#include <vector>

using VectorInt = std::vector<int>;
using VectorBool = std::vector<bool>;
using Graph = std::vector<std::vector<int>>;

Graph getRandomGraph(int V);
Graph sequentialDijkstra(const Graph& graph, int V);
Graph parallelDijkstra(const Graph& graph, int V);

#endif  // MODULES_OMP_DIJKSTRA_DIJKSTRA_H_
