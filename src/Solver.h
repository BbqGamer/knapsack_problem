#pragma once

#include "Knapsack.h"

class Solver {
    public:
    int bestResult;
    ProblemInstance instance;

    virtual void solve() = 0;

    virtual std::string getName() = 0;
    virtual void setInstance(ProblemInstance instance) = 0;
};

std::ostream& operator<<(std::ostream& os, const Solver& solver);

class BruteForce : public Solver {
public:
    void solve();

    BruteForce() {};

    BruteForce(ProblemInstance& instance) {
        this->instance = instance;
        bestResult = 0;
    }

    std::string getName() {
        return "BruteForce";
    }

    void setInstance(ProblemInstance instance) {
        this->instance = instance;
    }
};

class DynamicSolver : public Solver {

int** cache;
int solveRec(int n, int W);

void allocateMemory();
void freeMemory();

public:
    void solve();

    DynamicSolver() {
        cache = nullptr;
    }

    DynamicSolver(ProblemInstance& instance) {
        this->instance = instance;
        allocateMemory();
    }

    ~DynamicSolver() {
        freeMemory();
    }

    std::string getName() {
        return "Dynamic";
    }

    void setInstance(ProblemInstance instance) {
        freeMemory();

        this->instance = instance;
        allocateMemory();
    }
};


class GreedySolver : public Solver {
public:
    void solve();

    GreedySolver() {};

    GreedySolver(ProblemInstance& instance) {
        this->instance = instance;
        bestResult = 0;
    }

    std::string getName() {
        return "Greedy";
    }

    void setInstance(ProblemInstance instance) {
        this->instance = instance;
    }

};   
