#ifndef NAIVE_MAZE_HPP
#define NAIVE_MAZE_HPP


#include <array>
#include <unordered_map>


namespace NaiveApproach
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
    //virtual void enter() = 0;
};



class Room: public MapSite
{
public:
    Room(int room_number_p);

    Room(const Room& other);      // copy-constructor
    Room(Room&& other);         // move-constructor
    Room& operator=(const Room& other); // copy-assignment
    Room& operator=(Room&& other);     // move-assignment

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

    //virtual void enter();
};


class Door: public MapSite
{
public:
    Door();

    Door(Room* from_room_p,
         Room* to_room_p);

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

    void addRoom(std::unique_ptr<Room> room);

    Room* getRoom(int room_number);

    ~Maze() = default;
private:
    std::unordered_map<int, std::unique_ptr<Room>> rooms;
};


class MazeGame final
{
public:
    static Maze* createMaze();
};


}
#endif// NAIVE_MAZE_HPP
