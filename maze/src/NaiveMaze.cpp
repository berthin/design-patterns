#include "NaiveMaze.hpp"

#include <cassert>
#include <iostream>


using namespace std;


namespace NaiveApproach
{


// ROOM
//
Room::Room(int room_number_p):
    room_number(room_number_p),
    sides()
{
    cout << "Normal constructor" << endl;
}


Room::Room(const Room& other):
    room_number(other.room_number),
    sides(other.sides)
{
    cout << "Copy constructor" << endl;
}


Room::Room(Room&& other):
    room_number(move(other.room_number)),
    sides(move(other.sides))
{
    cout << "Move constructor" << endl;
}


Room& Room::operator=(const Room& other)
{
    cout << "Copy assignment" << endl;
    room_number = other.room_number;
    sides = other.sides;
    return *this;
}


Room& Room::operator=(Room&& other)
{
    cout << "Move assignment" << endl;
    if (this != &other) {
        swap(room_number, other.room_number);
        swap(sides, other.sides);
    }
    return *this;
}


int Room::getNumber() const
{
    return room_number;
}


void Room::setSide(
    Direction dir,
    MapSite* maze)
{
    sides[static_cast<int>(dir)] = maze;
}


MapSite* Room::getSide(Direction dir)
{
    return sides[static_cast<int>(dir)];
}


// WALL
//
Wall::Wall()
{
}


// DOOR
//
Door::Door():
    Door(nullptr, nullptr)
{
}


Door::Door(Room* from, Room* to):
    from_room(from),
    to_room(to),
    is_open(false)
{
}


Room* Door::otherSideFrom(Room* room)
{
    if (room == from_room)
        return to_room;
    if (room == to_room)
        return from_room;
    return nullptr;
}


Room::~Room()
{
    cout << "Destructor for room (" << room_number << ")"
         << " was called." << endl;
}


// MAZE
//
Maze::Maze():
    rooms()
{
}


void Maze::addRoom(unique_ptr<Room> room)
{
    rooms[room->getNumber()] = move(room);
}


Room* Maze::getRoom(int room_number)
{
    if (rooms.count(room_number) == 0)
        return nullptr;
    return rooms[room_number].get();
}


Maze* MazeGame::createMaze()
{
    Maze* a_maze = new Maze();

    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* the_door = new Door(r1, r2);

    a_maze->addRoom(unique_ptr<Room>(r1));
    a_maze->addRoom(unique_ptr<Room>(r2));

    r1->setSide(Direction::North, new Wall);
    r1->setSide(Direction::East, the_door);
    r1->setSide(Direction::South, new Wall);
    r1->setSide(Direction::West, new Wall);

    r2->setSide(Direction::North, new Wall);
    r2->setSide(Direction::West, the_door);
    r2->setSide(Direction::South, new Wall);
    r2->setSide(Direction::East, new Wall);

    return a_maze;
}


}

