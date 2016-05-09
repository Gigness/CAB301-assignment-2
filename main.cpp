#include <iostream>
#include "src/experiment.h"

using namespace std;

int main() {

    Experiment test(7);

    int median = test.bruteForceMedian();

    cout << "Median: " << median << " operations: " << test.basicOpsB << endl;

    return 0;
}