#include "BridgeClient.hpp"

#include <iostream>             // for std::cout, std::endl
#include <memory>               // for std::unique_ptr

#include "Graph.hpp"
#include "GraphImpl.hpp"

using namespace std;


namespace StructuralPatterns
{


void createGraph(Graph* g)
{
    g->addEdge(1, 2, 10);
    g->addEdge(1, 2, 5);
    g->addEdge(2, 1, 8);
    g->addEdge(1, 3, 7);
    g->addEdge(2, 3, 1);
    g->addEdge(2, 4, 5);
    g->addEdge(3, 4, 9);
    g->addEdge(3, 5, 10);
    g->addEdge(1, 5, 20);
    g->addEdge(2, 5, 25);
}


void runExample(Graph* g)
{
    createGraph(g);
    cout << "The shortest path between nodes 1 and 5 is: ";
    cout << g->shortedPath(1, 5) << endl;
}


void BridgeClient::run()
{
    unique_ptr<Graph> g = make_unique<WeightedGraph>(5);
    cout << "Weighted graph" << endl;
    runExample(g);

    g = make_unique<UnweightedGraph>(5);
    cout << "Unweighted graph" << endl;
    runExample(g.get());
}


}
