#include "Graph.hpp"


using namespace std;

namespace StructuralPatterns
{


void Graph::addEdge(int u, int v, int w)
{
    impl->addEdge(u, v, w);
}


WeightedGraph::WeightedGraph(int n_nodes):
    Graph::impl(make_unique<AdjListGraphImpl>(n_nodes))
{}


int WeightedGraph::shortestPath(int u, int v)
{
    static const int INF = numeric_limits<int>::max();
    static vector<int> cost;
    static auto cmp = [](const pair<int, int>& a,
                         const pair<int, int>& b) {
        return a.second < b.second;
    };

    cost.assign(n, INF);
    priority_queue<pair<int, int>, vector<int, int>, decltype(cmp)> q(cmp);
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


UnweightedGraph::UnweightedGraph(int n_nodes):
    Graph::impl(make_unique<AdjMatrixGraphImpl>(n_nodes))
{}


int UnweightedGraph::shortestPath(int u, int v)
{
    static vector<bool> seen;

    seen.assign(n, false);
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

    return false;
}

}
