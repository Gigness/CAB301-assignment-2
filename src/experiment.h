//
// Created by Paul Foo on 8/05/2016.
//

#ifndef CAB301_ASSIGNMENT2_EXPERIMENT_H
#define CAB301_ASSIGNMENT2_EXPERIMENT_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>



class Experiment {
public:
    Experiment(int size);
    virtual ~Experiment();
    int bruteForceMedian();
    void median();
    void outputExpData();
    void run();
    void writeResults(std::string fileName);
    static void writeHeader(std::string fileName);
    unsigned int basicOpsB = 0;



private:
    std::vector<int> inputVector;
    int size;
    unsigned int basicOpsM = 0;
    double timeM = 0;
    double timeB = 0;
};


#endif //CAB301_ASSIGNMENT2_EXPERIMENT_H
