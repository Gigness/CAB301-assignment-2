//
// Created by Paul Foo on 8/05/2016.
//

#include "experiment.h"

Experiment::Experiment(int size) : size(size)
{
    for(int i = 0; i < size; i++) {
        inputData.push_back(i);
    }
    random_shuffle(inputData.begin(), inputData.end());
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
void Experiment::bruteForceMedian() {

}

/*
 * Run's median and bruteForceMedian on array
 * Saves time and basic ops in instance vars
 */
void Experiment::run() {
    clock_t begin = clock();
    clock_t end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
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

