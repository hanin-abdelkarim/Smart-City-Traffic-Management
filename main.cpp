#include <iostream>
#include <string>
#include "header_files/Simulator.h"

using namespace std;

int main(int argc, char* argv[]) {
    Simulator sim;

    // Default mode is SILENT
    SimulationMode mode = SILENT;
    string inputFilename = "input.txt";

    // Handle command line arguments for mode selection
    if (argc > 1) {
        string modeArg = argv[1];
        if (modeArg == "step") {
            mode = STEP_BY_STEP;
            cout << "Running in Step-by-Step Mode." << endl;
        } else if (modeArg == "interactive") {
            mode = INTERACTIVE;
            cout << "Running in Interactive Mode." << endl;
        } else if (modeArg == "silent") {
            mode = SILENT;
            cout << "Running in Silent Mode." << endl;
        } else {
            cout << "Warning: Unknown mode '" << modeArg << "'. Defaulting to Silent Mode." << endl;
        }
    } else {
        cout << "No mode specified. Defaulting to Silent Mode." << endl;
    }

    // Load input file
    sim.loadInputFile(inputFilename);

    // Set mode and run simulation
    sim.setMode(mode);
    sim.run();
    
    cout << "Simulation finished successfully!" << endl;

    return 0;
}
