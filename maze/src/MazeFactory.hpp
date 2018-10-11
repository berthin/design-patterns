#ifndef MAZE_FACTORY_HPP
#define MAZE_FACTORY_HPP

#include "MazeComponents.hpp"


namespace AbstractFactory
{


class MazeFactory
{
public:
    MazeFactory();

    virtual MazeComponents::Maze* createMaze() const;

    virtual MazeComponents::Wall* createWall() const;

    virtual MazeComponents::Room* createRoom(
        int room_number) const;

    virtual MazeComponents::Door* createDoor(
        MazeComponents::Room* from,
        MazeComponents::Room* to) const;
};


}

#endif // MAZE_FACTORY_HPP
