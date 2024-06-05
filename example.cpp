#include "MTEngine.hpp"
#include "PrintUtils/PrintUtils.hpp"
#include <vector>
#include <iostream>

/**
 * This is the main function where the execution of the program begins.
 */
int main()
{
    /**
     * An instance of the MTEngine class is created.
     * The MTEngine class is  a pseudorandom number generator,
     * based on the Mersenne Twister algorithm.
     */
    MTEngine engine;

    /**
     * The rand() function of the MTEngine class is called to generate a random number.
     * The generated number is then printed to the console.
     */
    std::cout << engine.rand() << std::endl;

    /**
     * The choice() function of the MTEngine class is called with three arguments: 1, 2, and 3.
     * This function is assumed to randomly select and return one of the provided arguments.
     * The selected number is then printed to the console.
     */
    std::cout << engine.choice(1, 2, 3) << std::endl;

    /**
     * A vector of doubles is created with the values 1, 2, 3, 4, and 5.
     */
    std::vector<double> v = {1, 2, 3, 4, 5};

    /**
     * The Shuffle() function of the MTEngine class is called with the vector as an argument.
     * This function is assumed to randomly rearrange the elements in the provided vector.
     */
    engine.Shuffle(v);

    /**
     * The contents of the vector are printed to the console.
     * Note: This operation requires either a loop to print each element individually
     * or an overloaded operator<< for vectors, neither of which are present in this code.
     */
    std::cout << v << std::endl;

    /**
     * The main function returns 0, indicating successful execution of the program.
     */
    return 0;
}