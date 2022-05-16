#include "Stopwatch.h"
#include <time.h>
#include <fstream>

float SolverStopwatch::measureSolve() {
    //MEASURES TIME IN MILISECONDS

    time_t end, start = clock();

    solver->solve();

    end = clock();

    return (float)(end - start) / CLOCKS_PER_SEC * 1000;
}

void SolverStopwatch::setInstance(ProblemInstance& instance) {
    solver->setInstance(instance);
}

void Experiment::run() {
    std::ofstream output_file;
    output_file.open(output_filename);

    for(auto& instance : instances) {
        for(auto& sw : solverWatches) {
            sw.setInstance(instance);
            output_file << instance.size() << "," << sw.getSolverName() << "," << sw.measureSolve() << std::endl;
        }
    }

    output_file.close();
}