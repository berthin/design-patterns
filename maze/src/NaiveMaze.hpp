#ifndef NAIVE_MAZE_HPP
#define NAIVE_MAZE_HPP

#include "MazeComponents.hpp"
#include "MazeFactory.hpp"
#include "MazeBuilder.hpp"


namespace NaiveApproach
{


class MazeGame final
{
public:
    static MazeComponents::Maze* createMaze();

    static MazeComponents::Maze* createMaze(
        AbstractFactory::MazeFactory& factory);

    static MazeComponents::Maze* createMaze(
        Builder::MazeBuilder& builder);
};


}
#endif // NAIVE_MAZE_HPP
