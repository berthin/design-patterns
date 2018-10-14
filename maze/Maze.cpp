#include <iostream>
#include <memory>

#include "MazeGame.hpp"
#include "MazeAbstractFactory.hpp"
#include "MazeBuilder.hpp"
#include "MazeFactoryMethod.hpp"
#include "MazePrototypeFactory.hpp"

using namespace std;
using namespace CreationalPatterns;
using namespace MazeComponents;


void naiveApproach()
{
    unique_ptr<Maze> maze(MazeGame::createMaze());
}


void abstractFactory()
{
    BombedMazeAbstractFactory factory;
    unique_ptr<Maze> maze(MazeGame::createMaze(factory));
}


void prototype()
{
    MazePrototypeFactory factory(
        new Maze,
        new Wall,
        new Room,
        new Door);
    unique_ptr<Maze> maze(MazeGame::createMaze(factory));
}


void builderPattern()
{
    StandardMazeBuilder builder;

    MazeGame game;
    game.createMaze(builder);

    // @TODO: Refactor the ownership of Maze in Builder.
    // Currently the ownership is maintained in Builder, but
    // it must be transfered to the instance which calls
    // `Builder::getMaze()`.
    Maze* maze(builder.getMaze());
}


void factoryMethod()
{

    // @TODO: Fix memory leak problem.
    //        Probably an issue in MazeComponents::Room
    EnchantedMazeFactoryMethod factory;
    unique_ptr<Maze> maze(factory.createMaze());
}


int main()
{
    try
    {
        cout << "Naive Approach" << endl;
        cout << "==============" << endl;
        naiveApproach();
        cout << endl;

        cout << "Abstract Factory" << endl;
        cout << "================" << endl;
        abstractFactory();
        cout << endl;

        cout << "Builder" << endl;
        cout << "=======" << endl;
        builderPattern();
        cout << endl;

        cout << "Factory Method" << endl;
        cout << "==============" << endl;
        factoryMethod();
        cout << endl;

        //cout << "Prototype" << endl;
        //cout << "=========" << endl;
        //prototype();
        //cout << endl;
    }
    catch (...)
    {
        cout << "Something went wrong" << endl;
    }
    return 0;
}
