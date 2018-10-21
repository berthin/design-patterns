#include "FancyPathPrinter.hpp"

using namespace std;


namespace StructuralPatterns
{


FancyPathPrinter::FancyPathPrinter():
    FancyPrinter(OperativeSystem::UNIX)
{}


string FancyPathPrinter::print(
    FileSystem* file) const
{
    auto tree = getTreeFromRoot(file);
    return FancyPrinter::print(tree);
}


vector<string> FancyPathPrinter::getTreeFromRoot(
    FileSystem* file) const
{
    vector<string> tree;
    tree.push_back(file->toString());
    while (file->cd("..") != file) {
        file = file->cd("..");
        tree.push_back(file->toString());
    }
    return vector<string>(tree.rbegin(), tree.rend());
}


}
