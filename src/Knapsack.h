#pragma once

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define MAX_VALUE 1000
#define MAX_W_TO_C_RATIO 0.3

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
