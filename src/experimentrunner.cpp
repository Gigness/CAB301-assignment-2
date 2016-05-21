//
// Created by Paul Foo on 21/05/2016.
//

#include "experimentrunner.h"


/**
* Constructor for experiment runner.
* @param smallestInputSize minimum vector size for experiment
* @param largestInputSize maximum vector size for experiment
* @param increments used to increase the vector size from mimimum to maximum
* @param trails number of times to repeat experiment for a given vector size
* @param resultsFile location of the results csv
*/
ExperimentRunner::ExperimentRunner(int smallestInputSize, int largestInputSize, int increments, int trialsPerDataSet, std::string file)
        : minVectorSize(smallestInputSize), maxVectorSize(largestInputSize), increments(increments), trials(trialsPerDataSet), resultsFile(file) {
    int totalExperiments = ((largestInputSize - smallestInputSize) / increments) * trials;
    std::cout << "Experiment runner" << std::endl
    << "minVectorSize: " << minVectorSize << std::endl
    << "maxVectorSize: " << maxVectorSize << std::endl
    << "increments: " << increments << std::endl
    << "trials: " << trials << std::endl
    << "total experiments: " << totalExperiments << std::endl
    << "resultsFile: " << resultsFile << std::endl;
}

ExperimentRunner::~ExperimentRunner() {
    std::cout << "ExperimentRunner completed" << std::endl;
}

/**
* Wrapper to run all experiments. Writes results to the results file.
*/
void ExperimentRunner::start() {
    Experiment::writeHeader(resultsFile);
    std::cout << "ExperimentRunner starting..." << std::endl;
    for(int i = minVectorSize; i <= maxVectorSize; i += increments) {
        for(int j = 0; j < trials; j++) {
            Experiment e(i);
            e.run();
            e.writeResults(resultsFile);
        }
    }
}


