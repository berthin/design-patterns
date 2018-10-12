#ifndef MAZE_BUILDER_HPP
#define MAZE_BUILDER_HPP

#include <memory>

#include "MazeComponents.hpp"


namespace Builder
{


class MazeBuilder
{
public:
    virtual void buildMaze()
    {
    }

    virtual void buildRoom(int room_number)
    {
    }

    virtual void buildDoor(
        int room_from,
        int room_to)
    {
    }

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
