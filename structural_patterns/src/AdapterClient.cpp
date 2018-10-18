#include "AdapterClient.hpp"

#include <iostream>         // for std::cout
#include <string>           // for std::string

#include "FileSystem.hpp"
#include "FancyPathPrinter.hpp"

using namespace std;


namespace StructuralPatterns
{


unique_ptr<PathPrinter> AdapterClient::printer =
    make_unique<FancyPathPrinter>();


void AdapterClient::run()
{
    unique_ptr<FileSystem> fs = make_unique<FileSystem>("root");

    FileSystem* file = fs->cd("home")
                         ->cd("demo")
                         ->cd("hello_world.txt");

    cout << "File system example" << endl;
    cout << printer->print(*file) << endl;
}


}

