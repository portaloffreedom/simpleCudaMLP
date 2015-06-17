
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "data_types.h"
#include "NeuralNetwork/neuralnetwork.h"
using namespace std;

int main() {
    srand(time(0));

    SCMLP::NeuralNetwork nn(8,{2,4,3},2);

    std::vector<SCMLP::real> input {1,2,3,4,5,6,7,8};
    auto output = nn.calculateOutput(input);

    cout<<"test write"<<endl;

    nn.save(cout);
    ofstream outputJson("/tmp/test.json");
    nn.save(outputJson);

    cout<<endl<<"test read"<<endl;

    ifstream inputJson("/tmp/test.json");
    SCMLP::NeuralNetwork nn2(inputJson);

    nn2.save(cout);

    output = nn.calculateOutput(input);

}
