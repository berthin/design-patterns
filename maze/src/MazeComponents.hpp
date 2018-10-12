#ifndef MAZE_COMPONENTS_HPP
#define MAZE_COMPONENTS_HPP


#include <array>
#include <unordered_map>


namespace MazeComponents
{


enum class Direction
{
    North=0,
    South=1,
    East=2,
    West=3
};


class MapSite
{
public:
    // @TODO: Implement this function.
    //virtual void enter() = 0;
};



class Room: public MapSite
{
public:
    Room(int room_number_p);

    Room(const Room& other);            // copy-constructor
    Room(Room&& other);                 // move-constructor
    Room& operator=(const Room& other); // copy-assignment
    Room& operator=(Room&& other);      // move-assignment

    // @TODO: Implement this function.
    //virtual void enter();

    int getNumber() const;

    void setSide(Direction dir,
                 MapSite* maze);

    MapSite* getSide(Direction dir);

    ~Room();

private:
    int room_number;
    std::array<MapSite*, 4> sides;
};


class Wall: public MapSite
{
public:
    Wall();

    // @TODO: Implement this function.
    //virtual void enter();
};


class Door: public MapSite
{
public:
    Door();

    Door(Room* from_room_p,
         Room* to_room_p);

    // @TODO: Implement this function.
    //virtual void enter();

    Room* otherSideFrom(Room* room);

private:
    bool is_open;
    Room* from_room;
    Room* to_room;
};


class Maze final
{
public:
    Maze();

    //Maze(Maze&& other);
    //Maze& operator=(Maze&& other);
    //Maze& operator=(const Maze& other);

    void addRoom(std::unique_ptr<Room> room);

    Room* getRoom(int room_number);

    ~Maze() = default;

private:
    std::unordered_map<int, std::unique_ptr<Room>> rooms;
};


}
#endif // MAZE_COMPONENTS_HPP
