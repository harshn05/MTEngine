# MTEngine

The MTEngine project is a C++ implementation of a random number generator based on the Mersenne Twister algorithm. The Mersenne Twister is a pseudorandom number generating algorithm that is widely used because of its fast generation times and high period.

The MTEngine class provides a flexible and user-friendly interface for generating random numbers. It offers several functionalities:

1. **Initialization with a given seed:** 
   The constructor MTEngine(long long myseed) allows users to initialize the random number generator with a specific seed value. This is useful when deterministic behavior is required, i.e., the same sequence of random numbers needs to be generated across multiple runs.

2. **Reseeding with the previously used seed:** 
   The reseed() method allows users to reseed the random number generator with the previously used seed. This can be useful when the same sequence of random numbers needs to be generated again during a program's execution.

3. **Automatic generation of a random seed:**
    The randomseed() method generates a random seed value and initializes the engine with it. This is useful when non-deterministic behavior is required, i.e., a different sequence of random numbers needs to be generated on each run.

4. **Setting a specific seed:**
   The setseed(long long myseed) method allows users to set a specific seed value to be used by the engine.

5. **Random number generation:** 
   The rand(), randn(), and randn(double mean, double var) methods generate random numbers between 0 and 1, from a standard normal distribution, and from a normal distribution with a given mean and variance, respectively.

6. **Random choice between two values:** 
   The choice(T A, T B) method randomly chooses between two given values.

7. **Random choice from a list of values:**
   The Choice(T Start, Args... args) method randomly chooses an element from the given arguments.
   

   Harsh Kumar Narula
   <harsh.narula@iitbombay.org>

