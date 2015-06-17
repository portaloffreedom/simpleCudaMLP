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

#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "data_types.h"

namespace SCMLP {

class Neuron
{
public:
    Neuron(unsigned int size);
    Neuron(std::vector<real> weights);
    ~Neuron();

    void updateWeights(std::vector< real > weights);
    const std::vector< real > getWeights() const;

    unsigned int size() const;
    real operator[](unsigned int pos) const;
    real operator*(std::vector< real >* input);
    real processInput(std::vector< SCMLP::real >* input);

private:
    std::vector<real> weights;
};

}

#endif // NEURON_H
