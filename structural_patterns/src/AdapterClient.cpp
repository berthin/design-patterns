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
    unique_ptr<Directory> root = make_unique<Directory>("root");

    root->mkdir("home")->cd("home")
        ->mkdir("demo")->cd("demo")
        ->touch(make_unique<Mp3File>("ThisLandIsMine"));

    cout << "FileSystem example." << endl << endl;

    for (File* file: root->cd("home")->cd("demo")->ls()) {
        // Check file type
        if (file->getExtension() != Mp3File::mp3_ext)
            continue;

        // Print path
        cout << printer->print(static_cast<FileSystem*>(file)) << endl;

        // Play song
        static_cast<Mp3File*>(file)->play();
    }
}


}

