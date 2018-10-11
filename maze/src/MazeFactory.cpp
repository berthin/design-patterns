#include "MazeFactory.hpp"


using namespace MazeComponents;


namespace AbstractFactory
{


MazeFactory::MazeFactory()
{
}


Maze* MazeFactory::createMaze() const
{
    return new Maze();
}


Wall* MazeFactory::createWall() const
{
    return new Wall();
}


Room* MazeFactory::createRoom(int room_number) const
{
    return new Room(room_number);
}


Door* MazeFactory::createDoor(
    MazeComponents::Room* from,
    MazeComponents::Room* to) const
{
    return new Door(from, to);
}


}
