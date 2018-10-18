#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

//#include "PathPrinter.hpp"

#include <memory>           // for std::unique_ptr
#include <string>           // for std::string


namespace StructuralPatterns
{


class FileSystem final
{

public:
    FileSystem(const std::string name_p);

    FileSystem(
        const std::string name_p,
        FileSystem* parent);

    FileSystem* cd(
        const std::string dir);

    ~FileSystem();

public:
    std::string name;

private:
    FileSystem* parent;
};


}
#endif // FILE_SYSTEM_HPP
