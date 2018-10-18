#include "FancyPrinter.hpp"

#include <sstream>

using namespace std;


namespace StructuralPatterns
{


FancyPrinter::FancyPrinter(OperativeSystem os):
    delimiter(static_cast<char>(os))
{}


string FancyPrinter::print(
    const vector<string>& tree) const
{
    const int n = tree.size();
    if (n == 0) return "";

    stringstream ss;
    ss << tree.front();
    for (int i = 1; i < n; ++i) {
        ss << delimiter << tree[i];
    }
    return ss.str();
}


}
