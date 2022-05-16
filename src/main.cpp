#include "Knapsack.h"
#include "Solver.h"
#include "Stopwatch.h"

int main() {
    // ProblemInstance i1 = generateRandomProblemInstance(10, 1000);
    // ProblemInstance i2 = generateRandomProblemInstance(15, 1000);

    BruteForce s1 = BruteForce();
    DynamicSolver s2 = DynamicSolver();
    GreedySolver s3 = GreedySolver();
    Solver* s[] = {&s1, &s2, &s3};

    std::string output_filename = "../output/test.csv";
    std::vector<SolverStopwatch> solverWatches = {SolverStopwatch(s[0]), SolverStopwatch(s[1]), SolverStopwatch(s[2])};
    std::vector<ProblemInstance> instances = generateProblemInstanceSet(10, 25, 1, 1000, 3);
    Experiment experiment = Experiment(output_filename, solverWatches, instances);   
    experiment.run(); 

    return 0;
}