#pragma once

#include "Knapsack.h"

class Solver {
    public:
    int bestResult;
    ProblemInstance instance;

    virtual void solve() = 0;
};

std::ostream& operator<<(std::ostream& os, const Solver& solver);

class BruteForce : public Solver {
public:
    void solve();

    BruteForce(ProblemInstance& instance) {
        this->instance = instance;
        bestResult = 0;
    }
};

class DynamicSolver : public Solver {

int** cache;
int solveRec(int n, int W);

public:
    void solve();

    DynamicSolver() {
        cache = nullptr;
    }

    DynamicSolver(ProblemInstance& instance) {
        this->instance = instance;
        bestResult = 0;
        cache = new int*[instance.size() + 1];
        for(int i = 0; i <= instance.size(); i++) {
            cache[i] = new int[instance.C + 1];
            for(int j = 0; j <= instance.C; j++) {
                cache[i][j] = -1;
            }
        }
    }

    ~DynamicSolver() {
        for(int i = 0; i < instance.size() + 1; i++) {
            delete[] cache[i];
        }
        delete[] cache;
    }
};


class GreedySolver : public Solver {
public:
    void solve();

    GreedySolver(ProblemInstance& instance) {
        this->instance = instance;
        bestResult = 0;
    }
};   
