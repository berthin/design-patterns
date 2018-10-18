#include "MazeFactoryMethod.hpp"

#include <iostream>             // for std::cout

using namespace std;
using namespace MazeComponents;


namespace CreationalPatterns
{


Maze* MazeFactoryMethod::createMaze()
{
    Maze* a_maze = makeMaze();

    Room* r1 = makeRoom(1);
    Room* r2 = makeRoom(2);
    Door* the_door = makeDoor(r1, r2);

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


Maze* MazeFactoryMethod::makeMaze() const
{
    return new Maze;
}


Room* MazeFactoryMethod::makeRoom(int room_number) const
{
    return new Room(room_number);
}


Door* MazeFactoryMethod::makeDoor(
    Room* from,
    Room* to) const
{
    return new Door(from, to);
}


Wall* MazeFactoryMethod::makeWall() const
{
    return new Wall;
}


Room* EnchantedMazeFactoryMethod::makeRoom(
    int room_number) const
{
    cout << "Creating an enchanted room!" << endl;
    return new Room(room_number);
}


}
