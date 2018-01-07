#ifndef UNTITLED_NEURALNETWORK_H
#define UNTITLED_NEURALNETWORK_H

#include "Neuron.h"

class NeuralNetwork {
private:
    std::vector<std::vector<Neuron *>> net;
    std::vector<double> getOutputs();
    void setEntries(std::vector<double> vector);
    void runNetwork();
public:
    NeuralNetwork(const std::vector<int>);
    NeuralNetwork(const std::vector<int>, const std::vector<std::vector<std::vector<double>>>);
    void displayNet();
    std::vector<double> forward(std::vector<double>);
    void displayOutputs();
};


#endif //UNTITLED_NEURALNETWORK_H
