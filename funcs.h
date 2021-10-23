#pragma once
#include <iostream>
#include <vector>
#include <limits>

const long long inf = std::numeric_limits<long long>::max();

struct Edge{
    Edge(int a, int b, long long k): first(a), second(b), weight(k){};
    int first, second;
    long long weight;
};

std::vector<std::vector<long long>> Johnson(std::vector<Edge>& edges, int N, int M);
std::vector<long long> BellmanFord(std::vector<Edge>& edges, int N);
void ChangeWeight(std::vector<Edge>& edges, std::vector<long long>& res, int M);
std::vector<long long> Dijkstra(std::vector<Edge>& positiveEdges, int N, int M, std::vector<Edge>& edges, int s);
void PrintMatrix(std::vector<std::vector<long long>>& result, int N);