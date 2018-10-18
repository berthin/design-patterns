#ifndef PATH_PRINTER_HPP
#define PATH_PRINTER_HPP

#include <string>       // for std::string

#include "FileSystem.hpp"


namespace StructuralPatterns
{


class PathPrinter
{

public:
    virtual std::string print(FileSystem& file) const = 0;

};


}
#endif // PATH_PRINTER_HPP
