//
// Created by Paul Foo on 21/05/2016.
//

#ifndef CAB301_ASSIGNMENT2_EXPERIMENTRUNNER_H
#define CAB301_ASSIGNMENT2_EXPERIMENTRUNNER_H


#include <string>
#include "experiment.h"


class ExperimentRunner {
public:
    ExperimentRunner(int smallestInputSize, int largestInputSize, int increments, int trialsPerDataSet, std::string fileName);
    virtual ~ExperimentRunner();
    void start();

protected:

private:
    int minVectorSize;
    int maxVectorSize;
    int increments;
    int trials;
    std::string resultsFile;
};


#endif //CAB301_ASSIGNMENT2_EXPERIMENTRUNNER_H
