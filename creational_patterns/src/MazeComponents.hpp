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
    MapSite() = default;

    // @TODO: Implement this function.
    //virtual void enter() = 0;

    virtual MapSite* clone() const;
};



class Room: public MapSite
{
public:
    Room(int room_number_p);

    Room(const Room& other);            // copy-constructor
    //Room(Room&& other);                 // move-constructor
    //Room& operator=(const Room& other); // copy-assignment
    //Room& operator=(Room&& other);      // move-assignment

    // @TODO: Implement this function.
    //virtual void enter();

    int getNumber() const;

    void setSide(Direction dir,
                 MapSite* maze);

    MapSite* getSide(Direction dir);

    ~Room();

    // The following function members are required
    // for the Prototype pattern
    Room() = default;
    virtual void initialize(int room_number);

private:
    int room_number;
    std::array<MapSite*, 4> sides;
};


class Wall: public MapSite
{
public:
    Wall() = default;

    // @TODO: Implement this function.
    //virtual void enter();

    // The following function members are required
    // for the Prototype pattern
    //virtual Wall* clone() const;
    virtual void initialize();
};


// -----------------------------------
// DOOR
// -----------------------------------
class Door: public MapSite
{
public:
    Door();

    Door(Room* from_room_p,
         Room* to_room_p);

    // @TODO: Implement this function.
    //virtual void enter();

    Room* otherSideFrom(Room* room);

    // The following function members are required
    // for the Prototype pattern
    //virtual Door* clone() const;
    virtual void initialize(
        Room* from,
        Room* to);

private:
    bool is_open;
    Room* from_room;
    Room* to_room;
};


class Maze final
{
public:
    Maze();

    Maze(const Maze& other);        // copy-constructor

    void addRoom(std::unique_ptr<Room> room);

    Room* getRoom(int room_number);

    ~Maze() = default;

    // The following function members are required
    // for the Prototype pattern
    Maze* clone() const;
    void initialize();

private:
    std::unordered_map<int, std::unique_ptr<Room>> rooms;
};


}
#endif // MAZE_COMPONENTS_HPP
