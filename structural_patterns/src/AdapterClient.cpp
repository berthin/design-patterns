#include "AdapterClient.hpp"

#include <iostream>         // for std::cout
#include <string>           // for std::string
#include <memory>           // for std::unique_ptr

#include "FileSystem.hpp"
#include "FancyPathPrinter.hpp"

using namespace std;


namespace StructuralPatterns
{


void AdapterClient::run()
{
    unique_ptr<FileSystem> fs = make_unique<FileSystem>("root");

    FileSystem* file = fs->cd("home")
                         ->cd("demo")
                         ->cd("hello_world.txt");

    unique_ptr<FancyPathPrinter> printer = make_unique<FancyPathPrinter>();
    cout << "File system example" << endl;
    cout << printer->print(*file) << endl;
}


}

