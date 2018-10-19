#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace StructuralPatterns
{


class Graph
{

public:
    virtual ~Graph();

    virtual int shortestPath(int u, int v) = 0;

//protected:
    void addEdge(int u, int v, int w);

protected:
    Graph(int n_nodes);

    std::unique_ptr<GraphImpl> impl;

private:
    GraphImpl* getGraphImpl();
};


class WeightedGraph: public Graph
{

public:
    WeightedGraph(int n_nodes);

    virtual ~WeightedGraph();

    virtual int shortestPath();
    //virtual void addEdge(int u, int v, int w);
};


class UnweightedGraph : public Graph
{

public:
    UnweightedGraph(int n_nodes);

    //void addEdge(int u, int v);
    virtual int shortestPath();

private:
    //virtual void addEdge(int u, int v, int w);
};

}

#endif // GRAPH_HPP
