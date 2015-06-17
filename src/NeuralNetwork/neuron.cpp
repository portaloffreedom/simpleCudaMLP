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

#include "neuron.h"
#include <cassert>
#include <iostream>
using namespace SCMLP;

Neuron::Neuron(unsigned int size) :
    weights(size+1, 0)
{

}

Neuron::Neuron(std::vector< real > weights) :
    weights(weights)
{

}

void Neuron::updateWeights(std::vector< real > weights)
{
    assert(this->weights.size() == weights.size());
    this->weights = weights;
}

const std::vector< real > Neuron::getWeights() const
{
    return this->weights;
}

unsigned int Neuron::size() const
{
    return weights.size()-1;
}

real Neuron::operator[](unsigned int pos) const
{
    assert(pos < weights.size());
    return weights[pos];
}

real Neuron::operator*(std::vector< real >* input)
{
    return this->processInput(input);
}

real Neuron::processInput(std::vector< real >* input)
{
    assert(input->size() == weights.size()-1);

    real total = weights[0];
    for (int i=0; i<weights.size(); i++) {
        total += weights[i+1] * (*input)[i];
    }

    return total;
}


Neuron::~Neuron()
{

}
