#pragma once

#include "Solver.h"

class SolverStopwatch {
    Solver* solver;

    public:
    SolverStopwatch(Solver* s): solver(s) {}

    float measureSolve();
    void setInstance(ProblemInstance& instance);
    std::string getSolverName() {return solver->getName();};

};

class Experiment {
    std::string output_filename;
    std::vector<SolverStopwatch> solverWatches;
    std::vector<ProblemInstance> instances;

    public:

    Experiment(std::string filename,
               std::vector<SolverStopwatch> watchesList,
               std::vector<ProblemInstance> problemInstances) 
               : output_filename(filename), solverWatches(watchesList), instances(problemInstances) {};


    void run();

};