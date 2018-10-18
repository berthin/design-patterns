//===================================================
// This class represents the Adapter that implements
// both: PathPrinter and FancyPrinter.
// Considering that PathPrinter is the Interface we
// are using and FancyPrinter is a "thrid-party"
// library that we want to use, FancyPathPrinter
// allows us to wrap and use the third-party library
// in our system.
//===================================================

#ifndef FANCY_PATH_PRINTER_HPP
#define FANCY_PATH_PRINTER_HPP

#include <vector>           // for std::vector
#include <string>           // for std::string
#include <memory>           // for std::unique_ptr

#include "PathPrinter.hpp"
#include "FancyPrinter.hpp"


namespace StructuralPatterns
{


class FancyPathPrinter: public PathPrinter,
                        private FancyPrinter
{


public:
    FancyPathPrinter();

    virtual std::string print(
        FileSystem& file) const;

    virtual ~FancyPathPrinter() = default;

private:
    std::vector<std::string> getTreeFromRoot(
        FileSystem& file) const;
};

}

#endif // FANCY_PATH_PRINTER_HPP
