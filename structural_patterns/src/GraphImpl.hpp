//==========================================================
// This class represents the Implementor from the Bridge
// pattern. See Graph.hpp for the Abstraction.
// GraphImp describes the abstract class to represent a
// graph. There are two concrete classes:
// - Adjacent list
// - Matrix of adjacency
//
// @TODO: Those graph representations do not support
//        multiple edges between the same pair of nodes.
//==========================================================

#ifndef GRAPH_IMPL_HPP
#define GRAPH_IMPL_HPP

#include <vector>               // for std::vector
#include <unordered_map>        // for std::unordered_map
#include <utility>              // for std::pair
#include <functional>           // for std::hash
#include <cstring>              // for std::size_t

namespace StructuralPatterns
{


class GraphImpl
{

public:
    GraphImpl(int n_nodes);

    virtual ~GraphImpl();

    virtual void addEdge(int u, int v, int w) = 0;

    virtual int getCost(int u, int v) = 0;

    virtual std::vector<int> getNeighbors(int u) = 0;

    virtual int numNodes() const;

protected:
    int n_nodes;
};


class AdjListGraphImpl: public GraphImpl
{

public:
    AdjListGraphImpl(int n_nodes);

    virtual void addEdge(int u, int v, int w);

    virtual int getCost(int u, int v);

    virtual std::vector<int> getNeighbors(int u);

private:
    template<class T1, class T2>
    struct HashPair final
    {
        std::size_t operator() (const std::pair<T1, T2>& data) const
        {
            return std::hash<T1>()(data.first) ^
                   std::hash<T2>()(data.second);
        };
    };

    std::unordered_map<std::pair<int, int>, int, HashPair<int, int>> cache;
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
};


}

#endif // GRAPH_IMPL_HPP
