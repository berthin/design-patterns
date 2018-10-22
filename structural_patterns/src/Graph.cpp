#include "Graph.hpp"

#include <vector>                   // for std::vector
#include <queue>                    // for std::queue
#include <functional>               // for std::function
#include <climits>                  // for std::numeric_limits
#include <iostream>

using namespace std;


namespace StructuralPatterns
{


const int Graph::INF = numeric_limits<int>::max();

// ----------------------------------------------------------
// Graph
// ----------------------------------------------------------


Graph::Graph(unique_ptr<GraphImpl> impl_p):
    impl(move(impl_p))
{}


Graph::~Graph()
{}


void Graph::addEdge(int u, int v, int w)
{
    impl->addEdge(u, v, w);
}


// ----------------------------------------------------------
// WeightedGraph
// ----------------------------------------------------------


WeightedGraph::WeightedGraph(unique_ptr<GraphImpl> impl_p):
    Graph(move(impl_p))
{}


int WeightedGraph::shortestPath(int u, int v)
{
    static auto cmp = [](const pair<int, int>& a,
                         const pair<int, int>& b) {
        return a.second >= b.second;
    };

    const int n_nodes = impl->numNodes();

    static vector<int> cost;
    cost.assign(n_nodes, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    q.push({u, 0});

    while (!q.empty()) {
        const int cur = q.top().first;
        const int wei = q.top().second;
        q.pop();

        if (cost[cur] != INF) continue;
        cost[cur] = wei;

        if (cur == v) break;

        for (int nxt: impl->getNeighbors(cur)) {
            q.push({nxt,
                    wei + impl->getCost(cur, nxt)});
        }
    }
    return cost[v];
}


// ----------------------------------------------------------
// UnweightedGraph
// ----------------------------------------------------------


UnweightedGraph::UnweightedGraph(unique_ptr<GraphImpl> impl_p):
    Graph(move(impl_p))
{}


int UnweightedGraph::shortestPath(int u, int v)
{
    static vector<bool> seen;
    const int n_nodes = impl->numNodes();

    seen.assign(n_nodes, false);
    queue<pair<int, int>> q;
    q.push({u, 0});

    while (!q.empty()) {
        const int cur = q.front().first;
        const int wei = q.front().second;
        q.pop();

        if (seen[cur]) continue;
        seen[cur] = true;

        if (cur == v) return wei;

        for (const int nxt: impl->getNeighbors(cur)) {
            q.push({nxt, wei + 1});
        }
    }

    return INF;
}

}
