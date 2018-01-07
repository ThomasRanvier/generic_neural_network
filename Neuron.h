#ifndef UNTITLED_NEURON_H
#define UNTITLED_NEURON_H

#include <iostream>
#include <vector>
#include <random>

class Neuron {
private:
    std::vector<double> weights;
    std::vector<Neuron *> entries;
public:
    double output;
    Neuron(std::vector<Neuron *>);
    Neuron(std::vector<Neuron *>, std::vector<double>);
    void displayNeuron();
    void compute();
};


#endif //UNTITLED_NEURON_H
