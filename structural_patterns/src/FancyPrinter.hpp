//===================================================
// This class emulates a third party library that
// receives a list of strings and prints them out.
//===================================================
#ifndef FANCY_PRINTER
#define FANCY_PRINTER

#include <vector>           // for std::vector
#include <string>           // for std::string


namespace StructuralPatterns
{


enum class OperativeSystem
{
    WINDOWS = '\\',
    UNIX    = '/'
};


class FancyPrinter
{
public:
    FancyPrinter(OperativeSystem os);

    std::string print(
        const std::vector<std::string>& tree) const;

private:
    const char delimiter;
    std::vector<std::string> getTreeFromRoot() const;
};


}

#endif // FANCY_PRINTER
