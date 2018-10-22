//==========================================================
// This class represents the Abstraction from the Bridge
// pattern. See GraphImpl.hpp for the Implementor.
// Graph describes the abstract class to create a graph and
// find the shortest path given two nodes.
// There are two concrete classes that implement Graph:
// - WeightedGraph, internally implements the shortest path
//                  with a Dijkstra algorithm.
// - UnweightedGraph, internally implements the shortest
//                    path with a BFS.
//==========================================================

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <memory>           // for std::unique_ptr

#include "GraphImpl.hpp"

namespace StructuralPatterns
{


// ----------------------------------------------------------
// Graph
// ----------------------------------------------------------


class Graph
{

public:
    static const int INF;

    Graph(std::unique_ptr<GraphImpl> impl_p);

    virtual ~Graph();

    virtual int shortestPath(int u, int v) = 0;

    void addEdge(int u, int v, int w);
;
protected:
    std::unique_ptr<GraphImpl> impl;
};


// ----------------------------------------------------------
// WeightedGraph
// ----------------------------------------------------------


class WeightedGraph : public Graph
{

public:
    WeightedGraph(std::unique_ptr<GraphImpl> impl_p);

    virtual int shortestPath(int u, int v);
};


// ----------------------------------------------------------
// UnweightedGraph
// ----------------------------------------------------------


class UnweightedGraph : public Graph
{

public:
    UnweightedGraph(std::unique_ptr<GraphImpl> impl_p);

    virtual int shortestPath(int u, int v);
};

}

#endif // GRAPH_HPP
