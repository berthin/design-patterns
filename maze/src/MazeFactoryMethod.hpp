#ifndef MAZE_FACTORY_METHOD_HPP
#define MAZE_FACTORY_METHOD_HPP

#include "MazeComponents.hpp"


namespace CreationalPatterns
{


class MazeFactoryMethod
{

public:
    MazeComponents::Maze* createMaze();

    virtual MazeComponents::Maze* makeMaze() const;

    virtual MazeComponents::Room* makeRoom(
        int room_number) const;

    virtual MazeComponents::Wall* makeWall() const;

    virtual MazeComponents::Door* makeDoor(
        MazeComponents::Room* from,
        MazeComponents::Room* to) const;

};


class EnchantedMazeFactoryMethod: public MazeFactoryMethod
{

public:
    virtual MazeComponents::Room* makeRoom(
        int room_number) const;
};

}

#endif // MAZE_FACTORY_METHOD_HPP
