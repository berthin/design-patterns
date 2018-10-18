#include "MazePrototypeFactory.hpp"

using namespace MazeComponents;


namespace CreationalPatterns
{

MazePrototypeFactory::MazePrototypeFactory(
    Maze* maze,
    Wall* wall,
    Room* room,
    Door* door):
    prototype_maze(maze),
    prototype_wall(wall),
    prototype_room(room),
    prototype_door(door)
{
    assert(maze != nullptr);
    assert(wall != nullptr);
    assert(room != nullptr);
    assert(door != nullptr);
}


Maze* MazePrototypeFactory::makeMaze() const
{
    return static_cast<Maze*>(prototype_maze->clone());
}


Room* MazePrototypeFactory::makeRoom(
    int room_number) const
{
    Room* room = static_cast<Room*>(prototype_room->clone());
    room->initialize(room_number);
    return room;
}


Door* MazePrototypeFactory::makeDoor(
    Room* from,
    Room* to) const
{
    Door* door = static_cast<Door*>(prototype_door->clone());
    door->initialize(from, to);
    return door;
}


Wall* MazePrototypeFactory::makeWall() const
{
    return static_cast<Wall*>(prototype_wall->clone());
}


}
