#include<iostream>
#include<vector>
#include<algorithm>
#include "funcs.h"
#include <chrono>

void FloydWarshall(std::vector<std::vector<long long>>& matrix, int N){
    for(int k = 0; k < N; k++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(matrix[x][k] < inf && matrix[k][y] < inf){
                    matrix[x][y] = std::min(matrix[x][y], matrix[x][k] + matrix[k][y]);
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(matrix[i][i]){
            throw -1;
        }
    }
}

void FillMatrix(std::vector<Edge>& edges, int N, std::vector<std::vector<long long>>& matrix){
    std::vector<long long> cur(N, inf);
    for(int i = 0; i < N; i++){
        matrix.push_back(cur);
    }
    for(int i = 0; i < edges.size(); i++){
        matrix[edges[i].first - 1][edges[i].second - 1] = edges[i].weight;
    }
    for(int i = 0; i < N; i++){
        matrix[i][i] = 0;
    }
}

int main(){
    std::vector<Edge> edges;
    int n, m;
    int a, b;
    long long w;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        std::cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }
    std::vector<std::vector<long long>> matrix;
    {
        auto start = std::chrono::steady_clock::now();
        matrix = Johnson(edges, n, m);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Johnson time: " <<  elapsed_seconds.count() << std::endl;
    }
    {
        auto start = std::chrono::steady_clock::now();
        FillMatrix(edges, n, matrix);
        FloydWarshall(matrix, n);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "FloydWarshall time: " <<  elapsed_seconds.count() << std::endl;
    }
}