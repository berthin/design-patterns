#include <iostream>
#include <memory>

#include "MazeFactory.hpp"
#include "NaiveMaze.hpp"
#include "MazeBuilder.hpp"

using namespace std;

using MazeComponents::Maze;
using NaiveApproach::MazeGame;
using AbstractFactory::MazeFactory;
using Builder::StandardMazeBuilder;


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


void builderPattern()
{
    cout << endl;
    cout << "Builder Pattern" << endl;
    cout << "===============" << endl;

    StandardMazeBuilder builder;

    MazeGame game;
    game.createMaze(builder);

    Maze* maze(builder.getMaze());

    cout << "Builder maze created" << endl;
}


int main()
{
    try
    {
        naiveApproach();
        abstractFactory();
        builderPattern();
    }
    catch (...)
    {
        cout << "Something went wrong" << endl;
    }
    return 0;
}
