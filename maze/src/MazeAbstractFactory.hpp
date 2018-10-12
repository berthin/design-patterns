#ifndef MAZE_ABSTRACT_FACTORY_HPP
#define MAZE_ABSTRACT_FACTORY_HPP

#include "MazeComponents.hpp"


namespace CreationalPatterns
{


class MazeAbstractFactory
{
public:
    MazeAbstractFactory() = default;

    virtual MazeComponents::Maze* makeMaze() const;

    virtual MazeComponents::Wall* makeWall() const;

    virtual MazeComponents::Room* makeRoom(
        int room_number) const;

    virtual MazeComponents::Door* makeDoor(
        MazeComponents::Room* from,
        MazeComponents::Room* to) const;
};


class EnchantedMazeAbstractFactory: public MazeAbstractFactory
{

public:
    virtual MazeComponents::Room* makeRoom(
        int room_number) const;

};

}

#endif // MAZE_ABSTRACT_FACTORY_HPP
