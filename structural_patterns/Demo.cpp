#include <iostream>

#include "AdapterClient.hpp"
#include "BridgeClient.hpp"

using namespace std;
using namespace StructuralPatterns;

int main()
{
    cout << ("The following structural patterns are implemented:") << endl;
    cout << (" - Adapter") << endl;
    cout << (" - Bridge") << endl;
    cout << endl;

    try {
        cout << "Adapter" << endl;
        cout << "=======" << endl;
        AdapterClient adapter;
        adapter.run();

        cout << "Bridge" << endl;
        cout << "======" << endl;
        BridgeClient::run();
    }
    catch (...) {
        cout << "Something bad happened." << endl;
    }
    return 0;
}
