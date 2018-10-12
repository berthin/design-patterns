// =====================================================
// This file creates the Maze.
//
// - `MazeGame` uses the creational patterns to create
// the Maze. It contains three approaches:
//      1. Naive approach.
//      2. Abstract factory.
//      3. Builder.
// =====================================================

#ifndef MAZE_GAME_HPP
#define MAZE_GAME_HPP

#include "MazeComponents.hpp"
#include "MazeAbstractFactory.hpp"
#include "MazeBuilder.hpp"


namespace CreationalPatterns
{


class MazeGame final
{

public:
    static MazeComponents::Maze* createMaze();

    static MazeComponents::Maze* createMaze(
        MazeAbstractFactory& factory);

    static MazeComponents::Maze* createMaze(
        MazeBuilder& builder);
};


}
#endif // MAZE_GAME_HPP
