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


void DynamicSolver::solve() {
    bestResult = solveRec(instance.size()-1, instance.C);
}

int DynamicSolver::solveRec(int n, int W) {
    if(n >= 0 && cache[n][W] != -1) {
        return cache[n][W];
    }

    int result, tmp1, tmp2;
    if(n < 0 || W == 0) {
        return 0;
    } else if (instance.items[n].w > W) {
        result = solveRec(n-1, W);
    } else {
        tmp1 = solveRec(n-1, W);
        tmp2 = instance.items[n].v + solveRec(n-1, W - instance.items[n].w);
        result = std::max(tmp1, tmp2);
    }

    cache[n][W] = result;
    return result;
}