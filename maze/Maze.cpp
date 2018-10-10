#include "NaiveMaze.hpp"

#include <iostream>
#include <memory>

using namespace std;
using NaiveApproach::Maze;
using NaiveApproach::MazeGame;

int main()
{
    try
    {
        cout << "Creating a maze" << endl;
        unique_ptr<Maze> firstMaze(MazeGame::createMaze());
        cout << "Naive maze created" << endl;
    }
    catch (...)
    {
        cout << "Something went wrong" << endl;
    }
    return 0;
}
