//===================================================
// This class presents the interface used to
// represent the Target (in the Adapter pattern).
//
// The target depicts the contract that we need to
// follow if we want to use any solution to solve the
// problem that this interfaces is intented to.
//===================================================
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

    virtual ~PathPrinter() = default;
};


}
#endif // PATH_PRINTER_HPP
