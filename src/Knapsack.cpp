#include "Knapsack.h"

bool operator<(const Item &lhs, const Item &rhs) {
    return lhs.v/lhs.w < rhs.v/rhs.w;
}

ProblemInstance generateRandomProblemInstance(int n, int C) {
    ProblemInstance instance;
    instance.C = C;

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{WEIGHTS_CENTERED_AROUND * C, (float)C/10};
    std::normal_distribution<> vd{VALUES_CENTERED_AROUND, (float)VALUES_CENTERED_AROUND/5};

    for (int i = 0; i < n; i++) {
        Item item;
        item.w = std::round(d(gen));
        item.v = std::round(vd(gen));
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

std::vector<ProblemInstance> generateProblemInstanceSet(int startN, int endN, int step, int KnapsackCapacity, int redundant) {
    std::vector<ProblemInstance> instances;

    for(int n = startN; n <= endN; n += step) {
        for (int i = 0; i < redundant; i++) {
            ProblemInstance instance = generateRandomProblemInstance(n, KnapsackCapacity);
            instances.push_back(instance);
        }
    }

    return instances;
}