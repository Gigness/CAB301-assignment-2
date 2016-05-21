#include <iostream>
#include "src/experiment.h"
#include "src/experimentrunner.h"

using namespace std;

int main() {
    ExperimentRunner cab301Assignment2(1000, 10000, 1000, 10, "data_1000_10000_1000_10.csv");
    cab301Assignment2.start();
}