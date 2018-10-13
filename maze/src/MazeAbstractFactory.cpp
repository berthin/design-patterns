#include "MazeAbstractFactory.hpp"

#include <iostream>             // for std::cout

using namespace std;
using namespace MazeComponents;


namespace CreationalPatterns
{


Maze* MazeAbstractFactory::makeMaze() const
{
    return new Maze;
}


Wall* MazeAbstractFactory::makeWall() const
{
    return new Wall;
}


Room* MazeAbstractFactory::makeRoom(int room_number) const
{
    return new Room(room_number);
}


Door* MazeAbstractFactory::makeDoor(
    MazeComponents::Room* from,
    MazeComponents::Room* to) const
{
    return new Door(from, to);
}


Room* BombedMazeAbstractFactory::makeRoom(
    int room_number) const
{
    cout << "Creating a bombed room!" << endl;
    return new Room(room_number);
}


}
