#ifndef NAIVE_MAZE_HPP
#define NAIVE_MAZE_HPP

#include "MazeComponents.hpp"

namespace NaiveApproach
{


class MazeGame final
{
public:
    static MazeComponents::Maze* createMaze();
};


}
#endif // NAIVE_MAZE_HPP
