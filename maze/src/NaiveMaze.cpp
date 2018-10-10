#include "NaiveMaze.hpp"

#include <iostream>


using namespace std;
using namespace MazeComponents;


namespace NaiveApproach
{


Maze* MazeGame::createMaze()
{
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


}

