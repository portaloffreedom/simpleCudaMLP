
#include <iostream>
#include <vector>
#include "data_types.h"
#include "NeuralNetwork/neuralnetwork.h"
using namespace std;

int main() {
    SCMLP::NeuralNetwork nn(8,{3,4,5},2);

    std::vector<SCMLP::real> input {1,2,3,4,5,6,7,8};
    auto output = nn.calculateOutput(input);

    cout<<"Hello World"<<endl;

}
