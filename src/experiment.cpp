//
// Created by Paul Foo on 8/05/2016.
//

#include "experiment.h"

/**
 * Experiment
 * engine is an external source for number generatation
 */
Experiment::Experiment(int size) : size(size) {

    for(int i = 0; i < size; i++) {
        inputVector.push_back(i);
    }

    std::random_shuffle(inputVector.begin(), inputVector.end());
//    for(int i = 0; i < size; i++) {
//        std::cout << inputVector[i] << " ";
//    }
    std::cout << "vector of size: " << size << " created and randomized" << std::endl;

}

Experiment::~Experiment() {
    // just to see garbage collection in action..
    std::cout << "Experiment deleted" << std::endl;
}

int Experiment::median() {

    int n = (int)inputVector.size();
    this->basicOpsM = 0;

    if (n == 1){
        return inputVector[0];
    }
    else {
        return select(0, floor(n/2), n-1);
    }
}

int Experiment::select(int l, int m, int h){

    int pos = partition(l, h);
    if (pos == m){
        return inputVector[pos];
    }
    if (pos > m){
        return select(l, m, pos - 1);
    }
    if (pos < m){
        return select(pos + 1, m, h);
    }
    return 0;
}

int Experiment::partition(int l, int h){

    int pivotval = inputVector[l];
    int pivotloc = l;
    int temp;
    for(int j = l + 1; j < h + 1; j++){
        if(inputVector[j] < pivotval){
            this->basicOpsM++;
            pivotloc++;
            temp = inputVector[pivotloc];
            inputVector[pivotloc] = inputVector[j];
            inputVector[j] = temp;
        }
    }
    temp = inputVector[pivotloc];
    inputVector[pivotloc] = inputVector[l];
    inputVector[l] = temp;
    return pivotloc;
}

/*
 * TODO bruteForceMedian
 */
int Experiment::bruteForceMedian() {

    int n = (int)inputVector.size();
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
    bruteForceMedian();
    clock_t end1 = clock();
    this->timeB  = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    // write results to csv

    // Run the median test
    clock_t begin2 = clock();
    median();
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

    dataFile << size << "," << basicOpsM << "," << timeM << "," << basicOpsB << "," << timeB << std::endl;
    dataFile.close();
}

void Experiment::writeVector(std::ofstream& file) {
    for (int i = 0; i < this->inputVector.size(); i++) {
        file << this->inputVector[i] << " ";
    }
    file << std::endl;
}

void Experiment::randomVectorTest() {
    std::cout << "Randomness Test" << std::endl;

    std::ofstream testFile;
    testFile.open("randomness_test.txt");
    if(testFile.fail()) {
        std::cout << "FILE couldn't be opened" << std::endl;
        exit(1);
    }

    int size = 20;
    int trials = 20;

    for (int i = 0; i < trials; i++) {
        Experiment test(size);
        std::cout << testFile.is_open() << std::endl;
        test.writeVector(testFile);
    }
}

void Experiment::bruteForceMedianTest() {
    std::ofstream testFile;
    testFile.open("brute_force_median_test.txt");
    if(testFile.fail()) {
        std::cout << "FILE couldn't be opened" << std::endl;
        exit(1);
    }
    int size1 = 100;
    int size2 = 101;
    int actual_median1 = size1 / 2 - 1;
    int actual_median2 = (int)std::ceil(size2 / 2.0) - 1;
    int median1;
    int median2;
    int median3;
    int median4;
    int median5;
    int median6;

    // case 1: random vector (odd and even size)
    Experiment test1(size1);
    test1.writeVector(testFile);
    median1 = test1.bruteForceMedian();
    testFile << median1 << std::endl;

    Experiment test2(size2);
    test2.writeVector(testFile);
    median2 = test2.bruteForceMedian();
    testFile << median2 << std::endl;

    // case2: sorted vector
    Experiment test3(size1);
    test3.setSortedVector();
    test3.writeVector(testFile);
    median3 = test3.bruteForceMedian();
    testFile << median3 << std::endl;

    Experiment test4(size2);
    test4.setSortedVector();
    test4.writeVector(testFile);
    median4 = test4.bruteForceMedian();
    testFile << median4 << std::endl;

    // case3: reverse sorted vector
    Experiment test5(size1);
    test5.setReverseVector();
    test5.writeVector(testFile);
    median5 = test5.bruteForceMedian();
    testFile << median5 << std::endl;

    Experiment test6(size2);
    test6.setReverseVector();
    test6.writeVector(testFile);
    median6 = test6.bruteForceMedian();
    testFile << median6 << std::endl;
}

void Experiment::medianTest() {
    std::ofstream testFile;
    testFile.open("median_test.txt");
    if(testFile.fail()) {
        std::cout << "FILE couldn't be opened" << std::endl;
        exit(1);
    }
    int size0 = 6;
    int size1 = 100;
    int size2 = 101;
    int actual_median1 = size1 / 2 - 1;
    int actual_median2 = (int)std::ceil(size2 / 2.0) - 1;
    int median1;
    int median2;
    int median3;
    int median4;
    int median5;
    int median6;
    int median7;

    // case 1: random vector (odd and even size)
    Experiment test1(size1);
    test1.writeVector(testFile);
    median1 = test1.median();
    testFile << median1 << std::endl;

    Experiment test2(size2);
    test2.writeVector(testFile);
    median2 = test2.median();
    testFile << median2 << std::endl;

    // case2: sorted vector
    Experiment test3(size1);
    test3.setSortedVector();
    test3.writeVector(testFile);
    median3 = test3.median();
    testFile << median3 << std::endl;

    Experiment test4(size2);
    test4.setSortedVector();
    test4.writeVector(testFile);
    median4 = test4.median();
    testFile << median4 << std::endl;

    // case3: reverse sorted vector
    Experiment test5(size1);
    test5.setReverseVector();
    test5.writeVector(testFile);
    median5 = test5.median();
    testFile << median5 << std::endl;

    Experiment test6(size2);
    test6.setReverseVector();
    test6.writeVector(testFile);
    median6 = test6.median();
    testFile << median6 << std::endl;
    
    // case5: small vector
    Experiment test7(size0);
    test7.writeVector(testFile);
    median7 = test7.median();
    testFile << median7 << std::endl;
}


void Experiment::setSortedVector() {
    for(int i = 0; i < inputVector.size(); i++) {
        inputVector[i] = i;
    }
    std::cout << "Set inputVector to sorted: " << std::endl;
//    for(int i = 0; i < this->inputVector.size(); i++) {
//        std::cout << inputVector[i] << " ";
//    }
    std::cout << std::endl;
}

void Experiment::setReverseVector() {
    for (int i = inputVector.size() - 1; i >= 0; i--) {
        inputVector[inputVector.size() - 1 - i] = i;
    }
    std::cout << "Set inputVector to reverse sorted: " << std::endl;
//    for(int i = 0; i < this->inputVector.size(); i++) {
//        std::cout << inputVector[i] << " ";
//    }
    std::cout << std::endl;
}

