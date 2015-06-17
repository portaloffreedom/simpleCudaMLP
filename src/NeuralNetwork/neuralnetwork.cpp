/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2015  Matteo De Carlo <matteo.dek@covolunablu.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "neuralnetwork.h"
#include <algorithm>
#include <iostream>
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>
#include "debug.h"
using namespace SCMLP;

NeuralNetwork::NeuralNetwork(unsigned int inputSize, std::vector<unsigned int> layerSizes, unsigned int outputSize) :
    layers(layerSizes.size() +1)
{
    unsigned int previousLayerSize = inputSize;

    for (int i=0; i<layerSizes.size(); i++) {
        TRACING(std::cout<<"neuron size ("<<previousLayerSize<<") layerSize ("<<layerSizes[i]<<')'<<std::endl);
        layers[i] = new Layer(previousLayerSize, layerSizes[i]);
        previousLayerSize = layerSizes[i];
    }

    TRACING(std::cout<<"neuron size ("<<previousLayerSize<<") layerSize ("<<outputSize<<')'<<std::endl);
    layers[layerSizes.size()] = new Layer(previousLayerSize, outputSize);

}

NeuralNetwork::NeuralNetwork(std::istream &input) :
    layers(0)
{
    load(input);
}

static const std::string LAYERS_LABEL = "layers";
void NeuralNetwork::load(std::istream& stream)
{
    Json::Value root;
    stream >> root;

    Json::Value layers = root[LAYERS_LABEL];

    TRACING(std::cout<<"layers number("<<layers.size()<<")"<<std::endl);
    this->layers.resize(layers.size());
    for (int i=0; i<layers.size(); i++) {
        this->layers[i] = new Layer(layers[i]);
    }
}

void NeuralNetwork::save(std::ostream& stream) const
{
    stream << this->toJson() << std::flush;
}

Json::Value NeuralNetwork::toJson() const
{
    Json::Value root;

    Json::Value array(Json::arrayValue);
    //array.resize(layers.size());
    for (int i=0; i<layers.size(); i++) {
        array.append( layers[i]->toJson() );
    }

    root[LAYERS_LABEL] = array;

    return root;
}


std::vector< real > NeuralNetwork::calculateOutput(std::vector< real >& input) const
{
    std::vector< real > *middleCalculations = &input;

    for (int i=0; i<layers.size(); i++) {
        TRACING(std::cout<<"middleCalculations ("<<middleCalculations<<") size ("<<middleCalculations->size()<<')'<<std::endl);
        middleCalculations = layers[i]->processInputs(middleCalculations);
    }

    auto returnValue = std::vector<real>(*middleCalculations);
    delete middleCalculations;
    return returnValue;
}


NeuralNetwork::~NeuralNetwork()
{

}
