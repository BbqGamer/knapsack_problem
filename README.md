# Knapsack problem

This project is an analysis of a knapsack problem and attempt to solve it in C++.
There were used three methods:
- Brute Force
- Greedy algorithm
- Dynamic programming

Experiments were run with random instances of a problem for all these methods.
Analysis can be found in report/analysis.ipynb


## Configuration and building:

### First time:
cd lib
git clone https://github.com/google/googletest.git

cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" 

### Then:
cd build
make all

./bin/Knapsack_run