#pragma once

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define MAX_VALUE 100
#define MAX_W_TO_C_RATIO 0.3

struct Item {
    int w;
    int v;
};

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

    bool isSolutionValid();
};

std::ostream& operator<<(std::ostream& os, const ProblemInstance& instance);

ProblemInstance generateRandomProblemInstance(int n, int C);
