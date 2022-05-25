#pragma once

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <random>

#define VALUES_CENTERED_AROUND 1000
#define WEIGHTS_CENTERED_AROUND 0.5

struct Item {
    int w;
    int v;
};

bool operator<(const Item &lhs, const Item &rhs); //FOR GREEDY METHOD

std::ostream& operator<<(std::ostream& os, const Item& item);

class ProblemInstance {
    public:
    int C;
    std::vector<Item> items;
    
    std::vector<bool> solution;

    ProblemInstance() {
        C = 0;
    }
    
    int size() const {
        return items.size();
    }

    bool isSolutionValid() const;
};

std::ostream& operator<<(std::ostream& os, const ProblemInstance& instance);

ProblemInstance generateRandomProblemInstance(int n, int C);
std::vector<ProblemInstance> generateProblemInstanceSet(int startN, int endN, int step, int KnapsackCapacity, int redundant=1);
