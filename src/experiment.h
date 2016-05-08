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

class Experiment {
public:
    Experiment(int size);
    virtual ~Experiment();
    void bruteForceMedian();
    void median();
    void outputExpData();
    void run();
    void writeResults(std::string fileName);
    static void writeHeader(std::string fileName);

private:
    int size;
    std::vector<int> inputData;
    unsigned int basicOpsM = 0;
    double timeM = 0;
    unsigned int basicOpsB = 0;
    double timeB = 0;
};


#endif //CAB301_ASSIGNMENT2_EXPERIMENT_H
