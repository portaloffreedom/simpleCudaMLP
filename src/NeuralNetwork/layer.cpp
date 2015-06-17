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

#include "layer.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include "debug.h"

using namespace SCMLP;

Layer::Layer(unsigned int neuronSize, unsigned int size) :
    neurons(size)
{
    for (int i=0; i<size; i++) {
        neurons[i] = new Neuron(neuronSize);
    }
}

std::vector< real >* Layer::processInputs(std::vector< real >* input) const
{
    std::vector< real > *tmp = new std::vector< real >(neurons.size(), 0);

    TRACING(std::cout<<"neuron size ("<<neurons[0]->size()<<") input size ("<<input->size()<<')'<<std::endl);
    assert(neurons[0]->size() == input->size());

    for (int i=0; i<neurons.size(); i++) {
        Neuron* neuron = neurons[i];
        (*tmp)[i] = (*neuron) * input;
    }

    return tmp;
}


Layer::~Layer()
{
    for (int i=0; i<neurons.size(); i++) {
        delete neurons[i];
    }
}

