#include "GraphImpl.hpp"

#include <climits>          // for std::numeric_limits

using namespace std;


namespace StructuralPatterns
{


static const int INF = numeric_limits<int>::max();


// AdjListGraphImpl
//
AdjListGraphImpl::AdjListGraphImpl(int n_nodes_p):
    n_nodes(n_nodes_p),
    cache(),
    edges(n_nodes, {}),
    weights(n_nodes, {})
{}


void AdjListGraphImpl::addEdge(int u, int v, int w)
{
    edges[u].push_back(v);
    weights[u].push_back(w);
}


int getCost(int u, int v)
{
    const pair<int, int> key = {u, v};
    if (cache.count(key))
        return cache[key];

    const int n = edges.size();
    for (int i = 0; i < n; ++i) {
        if (edges[i] == v) {
            return cache[key] = weights[i];
        }
    }

    return INF;
}


vector<int> getNeighbors(int u)
{
    cache.clear();

    const int n = edges[u].size();
    for (int i = 0; i < n; ++i) {
        const int v = edges[u][i];
        const int w = weights[u][i];
        cache[make_pair(u, v)] = w;
    }
    return edges[u];
}

// AdjMatrixGraphImpl
//
AdjMatrixGraphImpl::AdjMatrixGraphImpl(int n_nodes_p):
    n_nodes(n_nodes_p),
    edges(n_nodes_p, vector<int>(n_nodes_p, INF))
{}


void AdjMatrixGraphImpl::addEdge(int u, int v, int w)
{
    edges[u][v] = w;
}


int AdjMatrixGraphImpl::getCost(int u, int v)
{
    return edges[u][v];
}


vector<int> AdjMatrixGraphImpl::getNeighbors(int u)
{
    vector<int> neighbors;
    for (const int v: edges[u]) {
        if (v == INF) continue;
        neighboars.push_back(v);
    }
    return neighboars;
}

}
