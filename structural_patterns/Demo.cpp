#include <iostream>

#include "AdapterClient.hpp"

using namespace std;
using namespace StructuralPatterns;

int main()
{
    cout << ("The following structural patterns are implemented:") << endl;
    cout << (" - Adapter") << endl;
    cout << endl;
    try {
        cout << "Adapter" << endl;
        cout << "=======" << endl;
        AdapterClient::run();
    }
    catch (...) {
        cout << "Something bad happened." << endl;
    }
    return 0;
}
