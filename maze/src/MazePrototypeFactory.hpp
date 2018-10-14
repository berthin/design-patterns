#ifndef MAZE_PROTOTYPE_FACTORY_HPP
#define MAZE_PROTOTYPE_FACTORY_HPP

#include "MazeComponents.hpp"

#include "MazeAbstractFactory.hpp"

namespace CreationalPatterns
{


class MazePrototypeFactory: public MazeAbstractFactory
{
public:
    MazePrototypeFactory(
        MazeComponents::Maze* maze,
        MazeComponents::Wall* wall,
        MazeComponents::Room* room,
        MazeComponents::Door* door);

    virtual MazeComponents::Maze* makeMaze() const;

    virtual MazeComponents::Wall* makeWall() const;

    virtual MazeComponents::Room* makeRoom(
        int room_number) const;

    virtual MazeComponents::Door* makeDoor(
        MazeComponents::Room* from,
        MazeComponents::Room* to) const;

private:
    MazeComponents::Maze* prototype_maze;
    MazeComponents::Wall* prototype_wall;
    MazeComponents::Room* prototype_room;
    MazeComponents::Door* prototype_door;
};


}

#endif // MAZE_PROTOTYPE_FACTORY_HPP
