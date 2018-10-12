// =====================================================
// This file implements the Builder creational pattern.
//
// - `MazeBuilder` only defines the abstract class that
// must be implemented.
// - `StandardMazeBuilder` is an implementation of
// `MazeBuilder`, it is in charge of creating all parts
// defined in the base class, and it will store the
// final product.
//
// Notice that the Builder pattern contains two parts:
// one is the *builder* and the other is the *director*.
// This file only implements the *builder* while the
// *director* can be found in `MazeGame::createMaze`
// =====================================================

#ifndef MAZE_BUILDER_HPP
#define MAZE_BUILDER_HPP

#include <memory>               // for std::unique_ptr

#include "MazeComponents.hpp"


namespace CreationalPatterns
{


class MazeBuilder
{

public:
    virtual void buildMaze()
    {}

    virtual void buildRoom(int room_number)
    {}

    virtual void buildDoor(
        int room_from,
        int room_to)
    {}

    virtual MazeComponents::Maze* getMaze()
    {
        return nullptr;
    }

protected:
    MazeBuilder() = default;
};


class StandardMazeBuilder: public MazeBuilder
{

public:
    StandardMazeBuilder();

    virtual void buildMaze();

    virtual void buildRoom(int room);

    virtual void buildDoor(int room_from,
                           int room_to);

    virtual MazeComponents::Maze* getMaze();

    ~StandardMazeBuilder();

private:
    std::unique_ptr<MazeComponents::Maze> maze;

    MazeComponents::Direction commonWall(
        int room_from,
        int room_to);
};

}

#endif // MAZE_BUILDER_HPP
