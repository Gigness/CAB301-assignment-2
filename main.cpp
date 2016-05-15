#include <iostream>
#include "src/experiment.h"

using namespace std;

int main() {

    Experiment test(7);
    Experiment test2(7);

    int bruteForceMedian = test.bruteForceMedian();
    
    cout << "Median: " << bruteForceMedian << " operations: " << test.basicOpsB << endl;
    
    int median = test.median();
    
    cout << "Median:" << median << " operations: " << test.basicOpsM << endl;

    return 0;
}