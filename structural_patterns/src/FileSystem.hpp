//===================================================
// A class that represent a basic FileSystem.
//
// It is used only in demonstration purposes for the
// Adapter method.
//===================================================
#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

#include <memory>           // for std::unique_ptr
#include <string>           // for std::string
#include <unordered_map>    // for std::unordered_map
#include <vector>           // for std::vector


namespace StructuralPatterns
{


class FileSystem
{

public:
    FileSystem(FileSystem* parent);

    virtual FileSystem* cd(const std::string dir) { return this; };

    virtual ~FileSystem();

    virtual void rename(const std::string name) = 0;

    void mv(FileSystem* parent_p);

    virtual std::string getName() const = 0;

    virtual std::string toString() const = 0;

protected:
    FileSystem* parent;

};


class File: public FileSystem
{

public:
    File(const std::string name_p,
         const std::string extension_p);

    virtual void rename(const std::string name);

    std::string getExtension() const;

    virtual std::string getName() const;

    virtual std::string toString() const;

private:
    std::string name;
    std::string ext;

    virtual FileSystem* cd(const std::string dir) {
        if (dir != "..") return this;
        return parent;
    };

};


class JpegFile: public File
{

public:
    JpegFile(const std::string name);

    int getCompressionLevel() const;

    static const std::string jpeg_ext;
};


class Mp3File: public File
{

public:
    Mp3File(const std::string name);

    void play() const;

    static const std::string mp3_ext;
};


class Directory: public File
{

public:
    Directory(const std::string name_p);

    virtual Directory* cd(
        const std::string dir);

    virtual std::vector<File*> ls();

    Directory* mkdir(const std::string dir);

    void touch(std::unique_ptr<File> file);

    virtual ~Directory();

    virtual std::string toString() const;

private:
    std::unordered_map<std::string, std::unique_ptr<File>> files;
};

}
#endif // FILE_SYSTEM_HPP
