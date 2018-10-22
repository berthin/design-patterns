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
    g->addEdge(1, 5, 30);
    g->addEdge(2, 5, 25);
}


void runExample(Graph* g)
{
    createGraph(g);
    cout << "The shortest path between nodes 1 and 5 is: ";
    cout << g->shortestPath(1, 5) << endl;
}


void BridgeClient::run()
{
    // Create a weighted AdjMatrix graph
    unique_ptr<AdjMatrixGraphImpl> matrix_graph = make_unique<AdjMatrixGraphImpl>(20);
    unique_ptr<Graph> my_graph = make_unique<WeightedGraph>(move(matrix_graph));

    cout << "Weighted graph" << endl;
    runExample(my_graph.get());

    // Create an unweighted AdjList graph
    unique_ptr<AdjListGraphImpl> list_graph = make_unique<AdjListGraphImpl>(15);
    my_graph = move(make_unique<UnweightedGraph>(move(list_graph)));

    cout << "Unweighted graph" << endl;
    runExample(my_graph.get());
}


}
