#include "MazeBuilder.hpp"


#include <iostream>
#include <cassert>


using namespace std;
using namespace MazeComponents;


namespace CreationalPatterns
{


StandardMazeBuilder::StandardMazeBuilder():
    maze()
{
}


void StandardMazeBuilder::buildMaze()
{
    maze = make_unique<Maze>();
}


StandardMazeBuilder::~StandardMazeBuilder()
{
    cout << "Calling destructor from standardbuilder" << endl;
}


void StandardMazeBuilder::buildRoom(int room_number)
{
    assert(maze != nullptr);
    if (maze->getRoom(room_number) != nullptr)
        return;

    Room* room = new Room(room_number);
    maze->addRoom(unique_ptr<Room>(room));

    room->setSide(Direction::North, new Wall);
    room->setSide(Direction::South, new Wall);
    room->setSide(Direction::East, new Wall);
    room->setSide(Direction::West, new Wall);
}


void StandardMazeBuilder::buildDoor(
    int room_from,
    int room_to)
{
    assert(maze != nullptr);
    buildRoom(room_from);
    buildRoom(room_to);

    Room* r1 = maze->getRoom(room_from);
    Room* r2 = maze->getRoom(room_to);

    Door* d = new Door(r1, r2);

    r1->setSide(commonWall(room_from, room_to), d);
    r2->setSide(commonWall(room_to, room_from), d);
}


Maze* StandardMazeBuilder::getMaze()
{
    return maze.get();
}


Direction StandardMazeBuilder::commonWall(
    int room_from,
    int room_to)
{
    assert(abs(room_from - room_to) == 1);
    // For sake of simplicity, rooms are listed
    // horizontally, and in increasin order
    // [1] -> [2] -> [3]
    if (room_from < room_to)
        return Direction::West;
    return Direction::East;
}

}
