#include "GraphImpl.hpp"

#include <climits>          // for std::numeric_limits
#include <iostream>

using namespace std;


namespace StructuralPatterns
{


static const int INF = numeric_limits<int>::max();

GraphImpl::GraphImpl(int n_nodes_p):
    n_nodes(n_nodes_p)
{}


GraphImpl::~GraphImpl()
{}


int GraphImpl::numNodes() const
{
    return n_nodes;
}


// ----------------------------------------------------------
// AdjListGraphImpl
// ----------------------------------------------------------


AdjListGraphImpl::AdjListGraphImpl(int n_nodes):
    GraphImpl(n_nodes),
    cache(),
    edges(n_nodes),
    weights(n_nodes)
{}


void AdjListGraphImpl::addEdge(int u, int v, int w)
{
    edges[u].push_back(v);
    weights[u].push_back(w);
}


int AdjListGraphImpl::getCost(int u, int v)
{
    const pair<int, int> key = {u, v};
    if (cache.count(key))
        return cache[key];

    const int n = edges[u].size();
    for (int i = 0; i < n; ++i) {
        if (edges[u][i] == v) {
            return cache[key] = weights[u][i];
        }
    }

    return INF;
}


vector<int> AdjListGraphImpl::getNeighbors(int u)
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


// ----------------------------------------------------------
// AdjMatrixGraphImpl
// ----------------------------------------------------------


AdjMatrixGraphImpl::AdjMatrixGraphImpl(int n_nodes):
    GraphImpl(n_nodes),
    edges(n_nodes, vector<int>(n_nodes, INF))
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
    for (int v = 0; v < n_nodes; ++v) {
        if (edges[u][v] == INF) continue;
        neighbors.push_back(v);
    }
    return neighbors;
}


}
