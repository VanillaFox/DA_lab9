#include "funcs.h"

std::vector<long long> BellmanFord(std::vector<Edge>& edges, int N){
    std::vector<long long> res(N+1, inf);
    res[0] = 0;
    long long a, b, w;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < edges.size(); j++){
            a = edges[j].first;
            b = edges[j].second;
            w = edges[j].weight;
            if(res[a] != inf && res[a] + w < res[b]){
                res[b] = res[a] + w;
            }
        }
    }

    for(int i = 0; i < edges.size(); i++){
        a = edges[i].first;
        b = edges[i].second;
        w = edges[i].weight;
        if(res[a] != inf && res[a] + w < res[b]){
            res.clear();
            break;
        }
    }
    return res;
}

void ChangeWeight(std::vector<Edge>& edges, std::vector<long long>& res, int M){
    edges.erase(edges.begin()+M, edges.end());

    long long a, b;
    for(int i = 0; i < edges.size(); i++){
        a = edges[i].first;
        b = edges[i].second;
        edges[i].weight += res[a] - res[b];
    }
}


std::vector<long long> Dijkstra(std::vector<Edge>& positiveEdges, int N, int M, std::vector<Edge>& edges, int s){
    std::vector<std::pair<long long, bool>> cur(N, std::make_pair(inf, false));
    std::vector<long long> result(N, inf);
    cur[s].first = 0;
    result[s] = 0;

    long long w, wres;
    int a, b;
    long long weight;
    int idx;

    for(int i = 0; i < N; i++){
        idx = -1;
        w = inf;
        for(int j = 0; j < N; j++){
            if(!cur[j].second && cur[j].first < w){
                w = cur[j].first;
                wres = result[j];
                idx = j+1;
            }
        }

        if(idx == -1){
            break;
        }
        
        cur[idx-1].second = true;
        for(int k = 0; k < M; k++){
            a = positiveEdges[k].first;
            if(a != idx){
                continue;
            }
            b = positiveEdges[k].second;
            weight = positiveEdges[k].weight;
            if(w + weight < cur[b-1].first){
                cur[b-1].first = w + weight;
                result[b-1] = wres + edges[k].weight;
            }
        }
    }

    return result;
}

void PrintMatrix(std::vector<std::vector<long long>>& result, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(result[i][j] == inf){
                std::cout << "inf"; 
            }
            else{
                std::cout << result[i][j];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<long long>> Johnson(std::vector<Edge>& edges, int N, int M){
    std::vector<long long> resBF;
    std::vector<Edge> positiveEdges = edges;

    for(int i = 1; i < N+1; i++){
        positiveEdges.push_back(Edge(0, i, 0));
    }

    resBF = BellmanFord(positiveEdges, N);
    std::vector<std::vector<long long>> result;

    if(resBF.empty()){
        std::cout << "Negative cycle\n";
        return result;
    }

    ChangeWeight(positiveEdges, resBF, M);

    for(int i = 0; i < N; i++){
        result.push_back(Dijkstra(positiveEdges, N, M, edges, i));
    }
    return result;
}
