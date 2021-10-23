#include <iostream>
#include "funcs.h"

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
    std::vector<std::vector<long long>> result;
    result = Johnson(edges, n, m);
    if(!result.empty()){
        PrintMatrix(result, n);
    }
}  