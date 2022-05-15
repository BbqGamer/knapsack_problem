#include "Solver.h"

std::ostream& operator<<(std::ostream& os, const Solver& solver) {
    std::cout << "Found the solution with value of " << solver.bestResult << std::endl;
    for(int i = 0; i < solver.instance.size(); i++) {
        if (solver.instance.solution[i]) {
            std::cout << "Item " << i << ": " << solver.instance.items[i] << std::endl;
        }
    }
    return os;
}

void BruteForce::solve() {
    int n = instance.size();
    int C = instance.C;
    int s = 0;
    for (int i = 0; i < (1 << n); i++) {
        int weight = 0;
        int value = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                weight += instance.items[j].w;
                value += instance.items[j].v;
            }
        }
        if (weight <= C && value > bestResult) {
            bestResult = value;
            s = i;
        }
    }
    for (int j = 0; j < n; j++) {
        if (s & (1 << j)) {
            instance.solution[j] = 1;
        }
    }
}