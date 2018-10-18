#include "MazeComponents.hpp"

#include <cassert>
#include <iostream>
#include <utility>
#include <algorithm>


using namespace std;


namespace MazeComponents
{

// -----------------------------------
// MAPSITE
// -----------------------------------

MapSite* MapSite::clone() const
{
    return new MapSite(*this);
}

// -----------------------------------
// ROOM
// -----------------------------------

Room::Room(int room_number_p):
    room_number(room_number_p),
    sides()
{
    cout << "Normal constructor" << endl;
}


Room::Room(const Room& other):
    room_number(other.room_number),
    //sides(other.sides)
    sides()
{
    cout << "Copy constructor" << endl;
}


//Room::Room(Room&& other):
    //room_number(move(other.room_number)),
    //sides(move(other.sides))
//{
    ////swap(room_number, other.room_number);
    ////swap(sides, other.sides);
    //cout << "Move constructor" << endl;
//}


//Room& Room::operator=(const Room& other)
//{
    //cout << "Copy assignment" << endl;
    //room_number = other.room_number;
    //sides = other.sides;
    //return *this;
//}


//Room& Room::operator=(Room&& other)
//{
    //cout << "Move assignment" << endl;
    //if (this != &other) {
        //swap(room_number, other.room_number);
        //swap(sides, other.sides);
    //}
    //return *this;
//}


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


void Room::initialize(
    int room_number_p)
{
    room_number = room_number_p;
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

// -----------------------------------
// WALL
// -----------------------------------

void Wall::initialize()
{}

// -----------------------------------
// DOOR
// -----------------------------------
Door::Door():
    Door(nullptr, nullptr)
{}


Door::Door(Room* from, Room* to):
    from_room(from),
    to_room(to),
    is_open(false)
{}


void Door::initialize(Room* from, Room* to)
{
    from_room = from;
    to_room = to;
}

// -----------------------------------
// MAZE
// -----------------------------------
Maze::Maze():
    rooms()
{}


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


Maze::Maze(const Maze& other):
    rooms()
{}


Maze* Maze::clone() const
{
    return new Maze(*this);
}


void Maze::initialize()
{
    rooms.clear();
}

}

