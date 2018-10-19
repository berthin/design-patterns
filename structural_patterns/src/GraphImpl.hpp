#ifndef GRAPH_IMPL_HPP
#define GRAPH_IMPL_HPP

#include <vector>           // for std::vector
#include <unoredered_map>   // for std::unoredered_map
#include <utility>          // for std::pair


namespace StructuralPatterns
{


class GraphImpl
{

public:
    virtual ~GraphImpl();

    virtual int addEdge(int u, int v, int w) = 0;

    virtual int getCost(int u, int v) = 0;

    void std::vector<int> getNeighbors(int u) = 0;

protected:
    GraphImpl(int n_nodes);

};


class AdjListGraphImpl: public GraphImpl
{

public:
    AdjListGraphImpl(int n_nodes);

    virtual void addEdge(int u, int v, int w);

    virtual int getCost(int u, int v);

    virtual std::vector<int> getNeighbors(int u);

private:
    std::unordered_map<std::pair<int, int>, int> cache;
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<int>> weights;
};


class AdjMatrixGraphImpl: public GraphImpl
{

public:
    AdjMatrixGraphImpl(int n_nodes);

    virtual void addEdge(int u, int v, int w);

    virtual int getCost(int u, int v);

    virtual std::vector<int> getNeighbors(int u);

private:
    std::vector<std::vector<int>> edges;
}


}

#endif // GRAPH_IMPL_HPP
