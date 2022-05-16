#include "Knapsack.h"
#include "Solver.h"

int main() {
    ProblemInstance instance = generateRandomProblemInstance(10, 1000);
    std::cout << instance << std::endl;

    BruteForce solver(instance);
    solver.solve();
    std::cout << solver << std::endl;

    DynamicSolver solver2(instance);
    solver2.solve();
    std::cout << solver2 << std::endl;

    GreedySolver solver3(instance);
    solver3.solve();
    std::cout << solver3 << std::endl;

    return 0;
}