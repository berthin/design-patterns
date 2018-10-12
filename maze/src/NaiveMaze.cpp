#include "NaiveMaze.hpp"

#include <iostream>


using namespace std;
using namespace MazeComponents;
using namespace AbstractFactory;
using namespace Builder;


namespace NaiveApproach
{


Maze* MazeGame::createMaze()
{
    cout << "Creating a maze following a native approach." << endl;
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


Maze* MazeGame::createMaze(MazeFactory& factory)
{
    cout << "Creating a maze following the AbstractFactory design pattern." << endl;

    Maze* a_maze = factory.createMaze();

    Room* r1 = factory.createRoom(1);
    Room* r2 = factory.createRoom(2);
    Door* the_door = factory.createDoor(r1, r2);

    a_maze->addRoom(unique_ptr<Room>(r1));
    a_maze->addRoom(unique_ptr<Room>(r2));

    r1->setSide(Direction::North, factory.createWall());
    r1->setSide(Direction::East, the_door);
    r1->setSide(Direction::South, factory.createWall());
    r1->setSide(Direction::West, factory.createWall());

    r2->setSide(Direction::North, factory.createWall());
    r2->setSide(Direction::West, the_door);
    r2->setSide(Direction::South, factory.createWall());
    r2->setSide(Direction::West, factory.createWall());

    return a_maze;
}


Maze* MazeGame::createMaze(
    MazeBuilder& builder)
{
    builder.buildMaze();

    builder.buildRoom(1);
    builder.buildRoom(2);
    builder.buildDoor(1, 2);

    return builder.getMaze();
}


}

