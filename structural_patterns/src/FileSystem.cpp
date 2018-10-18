#include "FileSystem.hpp"

using namespace std;


namespace StructuralPatterns
{


FileSystem::FileSystem(const string name_p):
    FileSystem(name_p, nullptr)
{}


FileSystem::FileSystem(const string name_p,
                       FileSystem* parent_p):
    name(name_p),
    parent(parent_p)
{}


FileSystem::~FileSystem()
{
    parent = nullptr;
}


FileSystem* FileSystem::cd(const string dir)
{
    if (dir == "..") {
        return parent;
    }
    return new FileSystem(dir, this);
}


//string FileSystem::absolutePath(
    //unique_ptr<PathPrinter> printer)
//{
    //return printer->print(*this);
//}

}
