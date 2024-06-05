//source code by Harsh Kumar Narula, harsh.narula@iitbombay.org
#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <array>
#include<iostream>
#include <initializer_list>

/**
 * @class MTEngine
 * @brief A class that represents a random number generator engine based on the Mersenne Twister algorithm.
 */
class MTEngine
{
private:
	std::mt19937_64 rng; /**< The random number generator engine. */
public:
	/**
	 * @brief Default constructor.
	 */
	MTEngine();

	/**
	 * @brief Constructor that initializes the engine with a given seed.
	 * @param myseed The seed value to initialize the engine.
	 */
	MTEngine(long long myseed);

	/**
	 * @brief Reseeds the engine with the previously used seed.
	 */
	void reseed();

	long long wasseededwith; /**< The seed value that was used to initialize the engine. */

	/**
	 * @brief Generates a random seed value and initializes the engine with it.
	 */
	void randomseed();

	/**
	 * @brief Sets the seed value to be used by the engine.
	 * @param myseed The seed value to set.
	 */
	void setseed(long long myseed);

	/**
	 * @brief Generates a random number between 0 and 1.
	 * @return The generated random number.
	 */
	double rand();

	/**
	 * @brief Generates a random number from a standard normal distribution (mean = 0, variance = 1).
	 * @return The generated random number.
	 */
	double randn();

	/**
	 * @brief Generates a random number from a normal distribution with a given mean and variance.
	 * @param mean The mean of the distribution.
	 * @param var The variance of the distribution.
	 * @return The generated random number.
	 */
	double randn(double mean, double var);

	/**
	 * @brief Generates a random number between two given values.
	 * @param a The lower bound of the range.
	 * @param b The upper bound of the range.
	 * @return The generated random number.
	 */
	double choice(double a, double b);

	/**
	 * @brief Generates a random number between three given values.
	 * @param a The first value.
	 * @param b The second value.
	 * @param c The third value.
	 * @return The generated random number.
	 */
	double choice(double a, double b, double c);

	/**
	 * @brief Generates a random number from a set of values.
	 * @tparam T The type of the values.
	 * @tparam Args The variadic template arguments representing the values.
	 * @param Start The first value.
	 * @param args The remaining values.
	 * @return The generated random number.
	 */
	template<typename T, typename... Args>
	inline T Choice(T Start, Args... args);

	/**
	 * @brief Generates a random number between two given values.
	 * @tparam T The type of the values.
	 * @param A The first value.
	 * @param B The second value.
	 * @return The generated random number.
	 */
	template<typename T>
	inline T choice(T A, T B);

	/**
	 * @brief Generates a random number from a set of values with corresponding probabilities.
	 * @param A The set of values.
	 * @param PDF The set of probabilities corresponding to the values.
	 * @return The generated random number.
	 */
	double choice(std::vector<double> A, std::vector<double> PDF);

	/**
	 * @brief Generates a vector of random numbers between 0 and 1.
	 * @param m The size of the vector.
	 * @return The generated vector of random numbers.
	 */
	std::vector<double> rand(int m);

	/**
	 * @brief Generates a vector of random numbers from a standard normal distribution (mean = 0, variance = 1).
	 * @param m The size of the vector.
	 * @return The generated vector of random numbers.
	 */
	std::vector<double> randn(int m);

	/**
	 * @brief Generates a matrix of random numbers between 0 and 1.
	 * @param m The number of rows in the matrix.
	 * @param n The number of columns in the matrix.
	 * @return The generated matrix of random numbers.
	 */
	std::vector<std::vector<double>> rand(int m, int n);

	/**
	 * @brief Generates a matrix of random numbers from a standard normal distribution (mean = 0, variance = 1).
	 * @param m The number of rows in the matrix.
	 * @param n The number of columns in the matrix.
	 * @return The generated matrix of random numbers.
	 */
	std::vector<std::vector<double>> randn(int m, int n);

	/**
	 * @brief Generates a vector of random numbers between two given values.
	 * @param a The lower bound of the range.
	 * @param b The upper bound of the range.
	 * @param p The size of the vector.
	 * @return The generated vector of random numbers.
	 */
	std::vector<double> rand(double a, double b, int p);

	/**
	 * @brief Generates a random number between two given values.
	 * @param a The lower bound of the range.
	 * @param b The upper bound of the range.
	 * @return The generated random number.
	 */
	double rand(double a, double b);

	/**
	 * @brief Generates a random integer between two given values.
	 * @param a The lower bound of the range.
	 * @param b The upper bound of the range.
	 * @return The generated random integer.
	 */
	int randint(int a, int b);

	/**
	 * @brief Generates a vector of random integers between two given values.
	 * @param a The lower bound of the range.
	 * @param b The upper bound of the range.
	 * @param p The size of the vector.
	 * @param repeatation Flag indicating whether repetition of values is allowed.
	 * @return The generated vector of random integers.
	 */
	std::vector<int> randint(int a, int b, int p, bool repeatation = false);

	/**
	 * @brief Generates a matrix of random integers within a given range.
	 * @param xmin The minimum value for the x-coordinate.
	 * @param xmax The maximum value for the x-coordinate.
	 * @param ymin The minimum value for the y-coordinate.
	 * @param ymax The maximum value for the y-coordinate.
	 * @param p The number of points to generate.
	 * @param repeatation Flag indicating whether repetition of points is allowed.
	 * @return The generated matrix of random integers.
	 */
	std::vector<std::vector<int>> randint(int xmin, int xmax, int ymin, int ymax, int p, bool repeatation = false);

	/**
	 * @brief Generates a vector of 3D points with random integer coordinates within given ranges.
	 * @param xmin The minimum value for the x-coordinate.
	 * @param xmax The maximum value for the x-coordinate.
	 * @param ymin The minimum value for the y-coordinate.
	 * @param ymax The maximum value for the y-coordinate.
	 * @param zmin The minimum value for the z-coordinate.
	 * @param zmax The maximum value for the z-coordinate.
	 * @param p The number of points to generate.
	 * @param repeatation Flag indicating whether repetition of points is allowed.
	 * @return The generated vector of 3D points.
	 */
	std::vector<std::array<double, 3>> randint(int xmin, int xmax, int ymin, int ymax, int zmin, int zmax, int p, bool repeatation = false);

	/**
	 * @brief Generates a sequence of integers from a given start value to a given end value.
	 * @param a The start value.
	 * @param b The end value.
	 * @return The generated sequence of integers.
	 */
	std::vector<int> sequence(int a, int b);

	/**
	 * @brief Generates a vector of ones.
	 * @param n The size of the vector.
	 * @return The generated vector of ones.
	 */
	std::vector<int> ones(int n);

	/**
	 * @brief Shuffles the elements of a vector randomly.
	 * @tparam T The type of the elements in the vector.
	 * @param X The vector to shuffle.
	 */
	template<class T>
	void Shuffle(std::vector<T>& X);
};

template<class T>
/**
 * Shuffles the elements in the given vector using the Mersenne Twister engine.
 *
 * @param X The vector to be shuffled.
 */
inline void MTEngine::Shuffle(std::vector<T>& X)
{
	std::shuffle(X.begin(), X.end(), rng);
}



template<typename T>
/**
 * Makes a random choice between two values.
 *
 * @param A The first value to choose from.
 * @param B The second value to choose from.
 * @return The randomly chosen value between A and B.
 */
inline T MTEngine::choice(T A, T B)
{
	double r = this->rand();
	if (r <= 0.5)
		return A;
	else
		return B;
}

template<typename T, typename... Args>
/**
 * Returns a randomly chosen element from the given arguments.
 *
 * @param Start The first element to consider for selection.
 * @param args The remaining elements to consider for selection.
 * @return The selected element.
 */
inline T MTEngine::Choice(T Start, Args... args)
{
	double r = rand();
	const std::size_t n = sizeof...(Args) + 1;
	if (r <= 1.0 / n)
	{
		std::cout << "First Element Returned" <<  Start<<std::endl;
		return Start;
	}
	int I = 0;
	int i = 2;
	while (i<=n)
	{
		if (r <= double(i) / n)
		{
			I = i - 1;
			break;
		}
		i++;
	}

	
	int count = 1;
	for (const auto p : { args... }) {
		if (count == I)
		{
			std::cout << I+1<<  " Element Returned " << p << std::endl;
			return p;
		}
		count++;
	}


	return 0;


}