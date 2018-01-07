#include "../headers/NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<int> layer) {
    std::vector<Neuron *> neurons;
    std::vector<Neuron *> entries;
    for (unsigned int i(0); i < layer.size(); i++) {
        for (unsigned int j(0); j < layer[i]; j++) {
            neurons.push_back(new Neuron(entries));
        }
        this->net.push_back(neurons);
        entries = neurons;
        neurons.clear();
    }
}

NeuralNetwork::NeuralNetwork(const std::vector<int> layer,
                             const std::vector<std::vector<std::vector<double>>> weights) {
    std::vector<Neuron *> neurons;
    std::vector<Neuron *> entries;
    for (unsigned int i(0); i < layer.size(); i++) {
        for (unsigned int j(0); j < layer[i]; j++) {
            if (i == 0) {
                neurons.push_back(new Neuron(entries));
            } else {
                neurons.push_back(new Neuron(entries, weights[i - 1][j]));
            }
        }
        this->net.push_back(neurons);
        entries = neurons;
        neurons.clear();
    }
}

void NeuralNetwork::displayNet() {
    std::cout << "<------NETWORK BRIEF------>\n\nNb of layers : " << this->net.size() << "\n";
    for (unsigned int i(0); i < this->net.size(); i++) {
        std::cout << "\nLayer " << i + 1 << ", nb of neurons : " << this->net[i].size() << "\n\n";
        for (unsigned int j(0); j < this->net[i].size(); j++) {
            if (i == 0) {
                std::cout << "Entrie " << j + 1 << " : no weights\n";
            } else {
                std::cout << "Neuron " << j + 1;
                this->net[i][j]->displayNeuron();
            }
        }
    }
}

std::vector<double> NeuralNetwork::forward(std::vector<double> entries) {
    std::vector<double> outputs;
    if (entries.size() == this->net[0].size()) {
        setEntries(entries);
        runNetwork();
        outputs = getOutputs();
    }
    return outputs;
}

std::vector<double> NeuralNetwork::getOutputs() {
    std::vector<double> outputs;
    int lastLayer(this->net.size() - 1);
    for (unsigned int i(0); i < this->net[lastLayer].size(); i++) {
        outputs.push_back(this->net[lastLayer][i]->output);
    }
    return outputs;
}

void NeuralNetwork::setEntries(std::vector<double> entries) {
    for (unsigned int i(0); i < this->net[0].size(); i++) {
        this->net[0][i]->output = entries[i];
    }
}

void NeuralNetwork::runNetwork() {
    for (unsigned int i(1); i < this->net.size(); i++) {
        for (unsigned int j(0); j < this->net[i].size(); j++) {
            this->net[i][j]->compute();
        }
    }
}

void NeuralNetwork::displayOutputs() {
    std::cout << "\n<------OUTPUTS------>\n\n";
    std::vector<double> outputs = getOutputs();
    for (unsigned int i(0); i < outputs.size(); i++) {
        std::cout << i + 1 << " : " << outputs[i] << "\n";
    }
}
