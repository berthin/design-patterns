#include "NaiveMaze.hpp"

#include <iostream>
#include <memory>

#include "MazeFactory.hpp"

using namespace std;

using MazeComponents::Maze;
using NaiveApproach::MazeGame;
using AbstractFactory::MazeFactory;


void naiveApproach()
{
    cout << "Creating a maze" << endl;
    unique_ptr<Maze> firstMaze(MazeGame::createMaze());
    cout << "Naive maze created" << endl;
}


void abstractFactory()
{
    cout << "Creating a maze" << endl;
    MazeFactory factory;
    unique_ptr<Maze> abstract_factory_maze(MazeGame::createMaze(factory));
    cout << "Abstract factory maze created" << endl;
}


int main()
{
    try
    {
        naiveApproach();
        abstractFactory();
    }
    catch (...)
    {
        cout << "Something went wrong" << endl;
    }
    return 0;
}
