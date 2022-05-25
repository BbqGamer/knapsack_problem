#include "Knapsack.h"
#include "Solver.h"
#include "Stopwatch.h"

void exp1() {
    BruteForce s1 = BruteForce();
    DynamicSolver s2 = DynamicSolver();
    GreedySolver s3 = GreedySolver();
    Solver* s[] = {&s1, &s2, &s3};

    std::string output_filename = "../output/test.csv";
    std::vector<SolverStopwatch> solverWatches = {SolverStopwatch(s[0]), SolverStopwatch(s[1]), SolverStopwatch(s[2])};
    std::vector<ProblemInstance> instances = generateProblemInstanceSet(10, 30, 1, 1000, 5);
    Experiment experiment = Experiment(output_filename, solverWatches, instances);   
    experiment.run(); 
}

void exp2() {
    DynamicSolver s2 = DynamicSolver();
    GreedySolver s3 = GreedySolver();
    Solver* s[] = {&s2, &s3};

    std::string output_filename = "../output/exp2.csv";
    std::vector<SolverStopwatch> solverWatches = {SolverStopwatch(s[0]), SolverStopwatch(s[1])};
    std::vector<ProblemInstance> instances = generateProblemInstanceSet(1000, 10000, 200, 1000, 5);
    Experiment experiment = Experiment(output_filename, solverWatches, instances);   
    experiment.run(); 
}

int main() {

    exp1();
    exp2();

    return 0;
}