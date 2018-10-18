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

    ~FancyPathPrinter() = default;
private:
    std::vector<std::string> getTreeFromRoot(
        FileSystem& file) const;
    //std::unique_ptr<FancyPrinter> printer;
};

}

#endif // FANCY_PATH_PRINTER_HPP
