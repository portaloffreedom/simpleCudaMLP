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

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "data_types.h"
#include <json/value.h>
#include "layer.h"

namespace SCMLP {

class NeuralNetwork
{
public:
    NeuralNetwork(unsigned int inputSize, std::vector<unsigned int> layerSizes, unsigned int outputSize);
    NeuralNetwork(std::istream& input);
    ~NeuralNetwork();

    void save(std::ostream &stream) const;
    Json::Value toJson() const;

    std::vector<real> calculateOutput(std::vector< SCMLP::real >& input) const;

private:
    std::vector<Layer*> layers;

    void load(std::istream& stream);
};

}

#endif // NEURALNETWORK_H
