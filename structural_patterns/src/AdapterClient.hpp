//===================================================
// This class represents the Client on the Adapter
// pattern.
//
// It uses a delegate for accessing the printing
// function an implementation of PathPrinter.
//===================================================

#ifndef ADAPTER_CLIENT_HPP
#define ADAPTER_CLIENT_HPP

#include <memory>               // for std::unique_ptr

#include "PathPrinter.hpp"


namespace StructuralPatterns
{


class AdapterClient final
{

public:
    AdapterClient() = default;

    void run();

    ~AdapterClient() = default;

private:
    static std::unique_ptr<PathPrinter> printer;
};


}

#endif // ADAPTER_CLIENT_HPP
