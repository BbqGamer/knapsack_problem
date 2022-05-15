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