#include "FileSystem.hpp"

#include <iostream>         // for std::cout, std::endl

using namespace std;


namespace StructuralPatterns
{


FileSystem::FileSystem(FileSystem* parent_p):
    parent(parent_p)
{}


void FileSystem::mv(FileSystem* parent_p)
{
    parent = parent_p;
}


FileSystem::~FileSystem()
{
    parent = nullptr;
}


// FILE
//

File::File(const string name_p,
           const string ext_p):
    name(name_p),
    ext(ext_p),
    FileSystem(this)
{}


void File::rename(const string new_name)
{
    name = new_name;
}


string File::getExtension() const
{
    return ext;
}


std::string File::getName() const
{
    return name;
}


std::string File::toString() const
{
    return name + "." + ext;
}

// JpegFile
//

const string JpegFile::jpeg_ext = "jpeg";

JpegFile::JpegFile(const string name):
    File(name, jpeg_ext)
{}


int JpegFile::getCompressionLevel() const
{
    return 90;
}


// Mp3File
//

const string Mp3File::mp3_ext = "mp3";

Mp3File::Mp3File(const string name):
    File(name, mp3_ext)
{}


void Mp3File::play() const
{
    cout << "**Playing song**"                      << endl
         << "This land is mine"                     << endl
         << "All the way to the old fence line"     << endl
         << "Every break of day"                    << endl
         << "I’m working hard just to make it pay"  << endl
         << "This land is mine"                     << endl
         << "Yeah I signed on the dotted line"      << endl
         << "Campfires on the creek bed"            << endl
         << "Bank breathing down my neck"           << endl
         << "They won’t take it away"               << endl
         << "They won’t take it away"               << endl
         << "They won’t take it away from me"       << endl
         << "..."                                   << endl;
}

// Directory
//

Directory::Directory(const string name_p):
    File(name_p, "")
{}


Directory::~Directory()
{}


Directory* Directory::cd(const string dir)
{
    if (dir == "..") {
        return parent != nullptr?
            static_cast<Directory*>(parent) : this;
    }

    if (!files.count(dir)) {
        return this;
    }

    File* file = files[dir].get();
    if (static_cast<Directory*>(file)) {
        return static_cast<Directory*>(file);
    }
    // `dir` is not a directory
    return this;
}


string Directory::toString() const
{
    return getName();
}


vector<File*> Directory::ls()
{
    vector<File*> data;
    for (auto& info: files) {
        data.push_back(info.second.get());
    }
    return data;
}


Directory* Directory::mkdir(const string name)
{
    if (files.count(name) != 0)
        return this;
    files[name] = make_unique<Directory>(name);
    files[name]->mv(this);
    return this;
}


void Directory::touch(unique_ptr<File> file)
{
    if (static_cast<Directory*>(file.get()) == nullptr) {
        // @TODO: Do not inherit from File
        cout << "touch does not work with directories" << endl;
        return;
    }

    const string& file_name = file->getName();
    if (files.count(file_name) != 0) {
        files[file_name].release();
    }
    file->mv(this);
    files[file_name] = move(file);
}

}
