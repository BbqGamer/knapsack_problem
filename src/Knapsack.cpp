#include "Knapsack.h"

bool operator<(const Item &lhs, const Item &rhs) {
    return lhs.v/lhs.w < rhs.v/rhs.w;
}

ProblemInstance generateRandomProblemInstance(int n, int C) {
    ProblemInstance instance;
    instance.C = C;
    for (int i = 0; i < n; i++) {
        Item item;
        item.w = rand() % int(MAX_W_TO_C_RATIO * C) + 1;
        item.v = rand() % MAX_VALUE + 1;
        instance.items.push_back(item);
        instance.solution.push_back(0);
    }
    return instance;
}

bool ProblemInstance::isSolutionValid() const {
    int weight = 0;
    for(int i = 0; i < this->size(); i++) {
        if (solution[i]) {
            weight += items[i].w;
        }
    }
    return weight <= C;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "(" << item.w << ", " << item.v << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ProblemInstance& instance) {
    os << "C: " << instance.C << std::endl;
    os << "Items: " << std::endl;
    for (int i = 0; i < instance.size(); i++) {
        os << instance.items[i] << std::endl;
    }
    return os;
}