#include "MTEngine.hpp"
#include <vector> 
#include <iostream>


int main() {
    MTEngine engine;
    std::cout<<engine.rand()<<std::endl;
    std::cout<<engine.choice(1,2,3)<<std::endl;
    std::vector<double> v = {1,2,3,4,5};
    engine.Shuffle(v);
    std::cout<<v<<std::endl;
    return 0;
}