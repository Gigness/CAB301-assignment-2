//
// Created by Paul Foo on 8/05/2016.
//

#include "experiment.h"


Experiment::Experiment(int size) : size(size)
{
    for(int i = 0; i < size; i++) {
        inputVector.push_back(i);
    }
    // shuffle vector using clocks() as seed
//    std::shuffle(inputVector.begin(), inputVector.end(), std::default_random_engine(clock()));
    std::cout << "vector of size: " << size << " created and randomized" << std::endl;
}

Experiment::~Experiment()
{
    // just to see garbage collection in action..
    std::cout << "Experiment deleted" << std::endl;
}

/*
 * TODO Median
 */
void Experiment::median() {
    
}

/*
 * TODO bruteForceMedian
 */
int Experiment::bruteForceMedian() {

    int n = inputVector.size();
    int k = (int)std::ceil(n / 2.0);
    int counter = 0;

    for (int i = 0; i < n; i++) {
        int numSmaller = 0;
        int numEqual = 0;

        for (int j = 0; j < n; j++) {
            counter++;
            if (inputVector[j] < inputVector[i]) {
                numSmaller++;
            }

            else if (inputVector[j] == inputVector[i]) {
                numEqual++;
            }

        }
        if ( (numSmaller < k) && (k <= (numEqual + numSmaller)) ) {
            this->basicOpsB = counter;
            return inputVector[i];
        }
    }
    return -1; // Something went wrong
}

/*
 * Run's median and bruteForceMedian on array
 * Saves time and basic ops in instance vars
 */
void Experiment::run() {
    // Run the brute force median
    clock_t begin1 = clock();
    // bruteForceMedian();
    clock_t end1 = clock();
    this->timeB  = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    // write results to csv

    // Run the median test
    clock_t begin2 = clock();
    // median();
    clock_t end2 = clock();
    this->timeM  = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    // write results to csv
}

/*
 * Helper function for Console logging of results...
 */
void Experiment::outputExpData() {
    std::cout << "Median" << std::endl
    << "Input Size: " << size << std::endl
    << "Basic Operations performed: " << basicOpsM << std::endl
    << "Time taken: " << timeM << std::endl
    << "BruteForce" << std::endl
    << "Input Size: " << size << std::endl
    << "Basic Operations performed: " << basicOpsB << std::endl
    << "Time taken: " << timeB << std::endl;
}

/*
 * Write results header to file
 */
void Experiment::writeHeader(std::string fileName) {
    std::ofstream dataFile;
    dataFile.open(fileName);
    if(dataFile.fail()) {
        std::cout << "FILE couldn't be opened" << std::endl;
        exit(1);
    }
    dataFile << "n,operations_median,time_median,operations_brute, time_brute" << std::endl;
    dataFile.close();
}

/*
 * Write results of exp to file
 */
void Experiment::writeResults(std::string fileName) {
    std::ofstream dataFile;
    dataFile.open(fileName, std::ios::app);
    if(dataFile.fail()) {
        std::cout << "FILE couldn't be opened" << std::endl;
        exit(1);
    }

    dataFile << size << "," << basicOpsM << "," << timeM << "," << basicOpsM << "," << timeB << std::endl;
    dataFile.close();
}
