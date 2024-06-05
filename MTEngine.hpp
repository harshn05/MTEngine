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
	 * @tparam T The type of the values.
	 * @param A The first value.
	 * @param B The second value.
	 * @return The generated random number.
	 */
	template<typename T>
	inline T MTEngine::choice(T A, T B)
	{
		double r = this->rand();
		if (r <= 0.5)
			return A;
		else
			return B;
	}

	/**
	 * @brief Returns a randomly chosen element from the given arguments.
	 * @tparam T The type of the elements.
	 * @tparam Args The variadic template arguments representing the elements.
	 * @param Start The first element to consider for selection.
	 * @param args The remaining elements to consider for selection.
	 * @return The selected element.
	 */
	template<typename T, typename... Args>
	inline T MTEngine::Choice(T Start, Args... args)
	{
		double r = rand();
		const std::size_t n = sizeof...(Args) + 1;
		if (r <= 1.0 / n)
		{
			std::cout << "First Element Returned: " << Start << std::endl;
			return Start;
		}
		int I = 0;
		int i = 2;
		while (i <= n)
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
				std::cout << I + 1 << " Element Returned: " << p << std::endl;
				return p;
			}
			count++;
		}

		return 0;
	}
		{
			std::cout << I+1<<  " Element Returned " << p << std::endl;
			return p;
		}
		count++;
	}


	return 0;


}