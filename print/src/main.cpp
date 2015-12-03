// main.cpp

#include "IPrintable.h"
#include "PrintableMap.h"
#include "CommandLineArgs.h"

// utilities
#include "JsonSerializer.h"
#include "files.h"
using utilities::OpenIfstream;
using utilities::OpenOfstream;

// layers
#include "Map.h"
using layers::Map;

#include<iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <stdexcept>
using std::runtime_error;

#include <memory>
using std::dynamic_pointer_cast;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << "usage: print.exe <layers file> <output file>\n";
        return 1;
    }

    try
    {
        CommandLineArgs args;
        auto layersFile = argv[1];
        auto svgFile = argv[2];

        // open file
        ifstream layersFStream = OpenIfstream(layersFile);
        auto map = Map::Deserialize<PrintableMap>(layersFStream);
        
        ofstream svgOStream = OpenOfstream(svgFile);
        map->Print(svgOStream, args);

    }
    catch (runtime_error e)
    {
        cerr << "runtime error: " << e.what() << std::endl;
    }

    // the end
    return 0;
}
