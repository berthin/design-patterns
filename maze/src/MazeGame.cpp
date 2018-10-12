#include "MazeGame.hpp"

#include <iostream>

using namespace std;
using namespace MazeComponents;


namespace CreationalPatterns
{


Maze* MazeGame::createMaze()
{
    cout << "Creating a maze following a naive approach." << endl;
    Maze* a_maze = new Maze();

    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* the_door = new Door(r1, r2);

    a_maze->addRoom(unique_ptr<Room>(r1));
    a_maze->addRoom(unique_ptr<Room>(r2));

    r1->setSide(Direction::North, new Wall);
    r1->setSide(Direction::East, the_door);
    r1->setSide(Direction::South, new Wall);
    r1->setSide(Direction::West, new Wall);

    r2->setSide(Direction::North, new Wall);
    r2->setSide(Direction::West, the_door);
    r2->setSide(Direction::South, new Wall);
    r2->setSide(Direction::East, new Wall);

    return a_maze;
}


Maze* MazeGame::createMaze(MazeAbstractFactory& factory)
{
    cout << "Creating a maze using the AbstractFactory pattern." << endl;

    Maze* a_maze = factory.makeMaze();

    Room* r1 = factory.makeRoom(1);
    Room* r2 = factory.makeRoom(2);
    Door* the_door = factory.makeDoor(r1, r2);

    a_maze->addRoom(unique_ptr<Room>(r1));
    a_maze->addRoom(unique_ptr<Room>(r2));

    r1->setSide(Direction::North, factory.makeWall());
    r1->setSide(Direction::East, the_door);
    r1->setSide(Direction::South, factory.makeWall());
    r1->setSide(Direction::West, factory.makeWall());

    r2->setSide(Direction::North, factory.makeWall());
    r2->setSide(Direction::West, the_door);
    r2->setSide(Direction::South, factory.makeWall());
    r2->setSide(Direction::West, factory.makeWall());

    return a_maze;
}


Maze* MazeGame::createMaze(
    MazeBuilder& builder)
{
    cout << "Creating a maze using the Builder pattern." << endl;
    builder.buildMaze();

    builder.buildRoom(1);
    builder.buildRoom(2);
    builder.buildDoor(1, 2);

    return builder.getMaze();
}


}

