#include "headers/NeuralNetwork.h"

int main() {
    srand(time(NULL));
    std::vector<int> layer;
    layer.push_back(2);
    layer.push_back(2);

    std::vector<std::vector<std::vector<double>>> testWeights;
    std::vector<double> weightsN1, weightsN2;
    weightsN1.push_back(0.5);
    weightsN1.push_back(-0.5);
    weightsN2.push_back(1);
    weightsN2.push_back(-1);

    std::vector<std::vector<double>> neurons;
    neurons.push_back(weightsN1);
    neurons.push_back(weightsN2);

    testWeights.push_back(neurons);

    NeuralNetwork net(layer, testWeights);
    net.displayNet();

    std::vector<double> testEntries;
    testEntries.push_back(0.5);
    testEntries.push_back(-0.5);

    net.forward(testEntries);
    net.displayOutputs();//Expected outputs for those weights and entries : 0.5 and 1

    return 0;
}