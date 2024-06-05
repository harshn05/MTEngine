//source code by Harsh Kumar Narula, harsh.narula@iitbombay.org
#include "MTEngine.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Constructs an instance of the MTEngine class.
 *
 * This constructor initializes the random number generator (RNG) with the specified seed.
 *
 * @param myseed The seed value to initialize the RNG.
 */
MTEngine::MTEngine(long long myseed)
{
	rng.seed(myseed);
	wasseededwith = myseed;
}

/**
 * \brief Constructs an instance of the MTEngine class.
 *
 * This constructor initializes the random number generator (RNG) of the MTEngine class
 * with a seed based on the current system time. The seed is used to generate random numbers
 * in subsequent calls to the RNG.
 */
MTEngine::MTEngine()
{
	long long myseed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	// std::seed_seq ss{ uint32_t(myseed & 0xffffffff), uint32_t(myseed >> 32) };
	// rng.seed(ss);
	rng.seed(myseed);
	wasseededwith = myseed;
}

// THIS SHOULD BE USED WITH EXTREME CARE
/**
 * Reseeds the random number generator with a specified seed value.
 *
 * @param None
 * @return None
 */
void MTEngine::reseed()
{
	rng.seed(wasseededwith);
}

/**
 * Seeds the random number generator with a random value based on the current time.
 * This function uses the high-resolution clock to generate a seed value and sets it as the seed for the random number generator.
 * The seed value is also stored in the `wasseededwith` member variable.
 */
void MTEngine::randomseed()
{
	long long myseed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	// std::seed_seq ss{ uint32_t(myseed & 0xffffffff), uint32_t(myseed >> 32) };
	// rng.seed(ss);
	rng.seed(myseed);
	wasseededwith = myseed;
}

/**
 * Sets the seed value for the random number generator.
 *
 * @param myseed The seed value to set.
 */
void MTEngine::setseed(long long myseed)
{
	rng.seed(myseed);
	wasseededwith = myseed;
}

/**
 * Generates a random double value between 0 and 1.
 *
 * @return The generated random double value.
 */
double MTEngine::rand()
{
	std::uniform_real_distribution<double> unif(0, 1);
	return unif(rng);
}

/**
 * Returns a random choice between two given values.
 *
 * @param a The first value.
 * @param b The second value.
 * @return The randomly chosen value between `a` and `b`.
 */
double MTEngine::choice(double a, double b)
{
	double r = rand();
	if (r <= 0.5)
	{
		return a;
	}
	else
	{
		return b;
	}
	return a;
}

/**
 * Returns a random choice between three given values.
 *
 * @param a The first value.
 * @param b The second value.
 * @param c The third value.
 * @return A random choice between a, b, and c.
 */
double MTEngine::choice(double a, double b, double c)
{
	double r = rand();
	if (r <= 1.0 / 3.0)
	{
		return a;
	}
	else if (r <= 2.0 / 3.0)
	{
		return b;
	}
	else
	{
		return c;
	}
	return a;
}

// template int MTEngine::Choice<int>(int, int);

/**
 * Returns a randomly chosen element from the given vector A based on the provided probability distribution function (PDF).
 *
 * @param A The vector of elements to choose from.
 * @param PDF The probability distribution function corresponding to each element in vector A.
 * @return The randomly chosen element from vector A.
 */
/**
 * Returns a randomly chosen element from the given vector A based on the provided probability distribution function (PDF).
 *
 * @param A The vector of elements to choose from.
 * @param PDF The probability distribution function (PDF) corresponding to the elements in vector A.
 * @return The randomly chosen element from vector A.
 */
double MTEngine::choice(std::vector<double> A, std::vector<double> PDF)
{
	unsigned int points = A.size();
	std::vector<double> CDF(points, 0);

	CDF[0] = PDF[0];
	for (size_t i = 0; i < points - 1; i++)
	{
		CDF[i + 1] = CDF[i] + PDF[i];
	}

	double r = CDF[points - 1] * rand();

	if (r < CDF[0])
	{
		return A[0];
	}

	else
	{
		for (size_t i = 0; i < points - 1; i++)
		{
			if (r >= CDF[i] && r < CDF[i + 1])
			{
				return A[i + 1];
			}
		}
	}
}

/**
 * Generates a random number from a normal distribution with mean 0 and standard deviation 1.
 *
 * @return The generated random number.
 */
double MTEngine::randn()
{
	std::normal_distribution<double> gauss(0, 1);
	return gauss(rng);
}

/**
 * Generates a random number from a normal distribution with the specified mean and variance.
 *
 * @param mean The mean of the normal distribution.
 * @param var The variance of the normal distribution.
 * @return A random number from the normal distribution.
 */
double MTEngine::randn(double mean, double var)
{
	std::normal_distribution<double> gauss(mean, var);
	return gauss(rng);
}
/**
 * Generates a vector of random numbers between 0 and 1.
 *
 * @param m The number of random numbers to generate.
 * @return A vector of random numbers between 0 and 1.
 */
vector<double> MTEngine::rand(int m)
{
	// initialize a uniform distribution between a and b
	std::uniform_real_distribution<double> unif(0, 1);
	vector<double> A(m, 0.0);
	for (int i = 0; i < m; i++)
	{
		A[i] = unif(rng);
	}
	return A;
}

/**
 * Generates a vector of random numbers from a standard normal distribution.
 *
 * @param m The number of random numbers to generate.
 * @return A vector of random numbers from a standard normal distribution.
 */
vector<double> MTEngine::randn(int m)
{
	std::normal_distribution<double> gauss(0, 1);
	vector<double> A(m, 0.0);
#pragma omp parallel for
	for (int i = 0; i < m; i++)
	{
		A[i] = gauss(rng);
	}
	return A;
}

/**
 * Generates a random matrix of size m x n.
 *
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 * @return A vector of vectors representing the random matrix.
 */
vector<vector<double>> MTEngine::rand(int m, int n)
{
	std::vector<std::vector<double>> matrix;
	matrix.resize(m, std::vector<double>(n, 0.0)); // Initialized With 0.0
	std::uniform_real_distribution<double> unif(0, 1);
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = unif(rng);
		}
	}

	return matrix;
}

/**
 * Generates a matrix of random numbers from a standard normal distribution.
 *
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 * @return A matrix of size m x n with random numbers from a standard normal distribution.
 */
vector<vector<double>> MTEngine::randn(int m, int n)
{
	std::vector<std::vector<double>> matrix;
	matrix.resize(m, std::vector<double>(n, 0.0)); // Initialized With 0.0
	std::normal_distribution<double> gauss(0, 1);
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = gauss(rng);
		}
	}

	return matrix;
}

/**
 * Generates a vector of random double values within the range [a, b].
 *
 * @param a The lower bound of the range.
 * @param b The upper bound of the range.
 * @param p The number of random values to generate.
 * @return A vector of random double values.
 */
vector<double> MTEngine::rand(double a, double b, int p)
{
	if (a > b)
	{
		double tmp1 = a;
		b = a;
		a = tmp1;
	}

	// initialize a uniform distribution between a and b
	std::uniform_real_distribution<double> unif(a, b);
	vector<double> A(p, 0.0);
	for (int i = 0; i < p; i++)
	{
		A[i] = unif(rng);
	}
	return A;
}

/**
 * Generates a random number between the given range [a, b].
 *
 * @param a The lower bound of the range.
 * @param b The upper bound of the range.
 * @return A random number between the range [a, b].
 */
double MTEngine::rand(double a, double b)
{
	double r = rand();

	return r * a + (1 - r) * b;
}

/**
 * Generates a random integer between the given range [a, b].
 *
 * @param a The lower bound of the range.
 * @param b The upper bound of the range.
 * @return A random integer between the range [a, b].
 */
int MTEngine::randint(int a, int b)
{
	// initialize a uniform distribution between a and b
	std::uniform_int_distribution<int> unif(a, b);
	return unif(rng);
}

/**
 * Generates a vector of random integers within a specified range.
 *
 * @param a The lower bound of the range (inclusive).
 * @param b The upper bound of the range (inclusive).
 * @param p The number of random integers to generate.
 * @param repeatation Determines whether repeated values are allowed in the generated vector.
 *                   If set to true, repeated values are allowed; otherwise, each value in the vector will be unique.
 * @return A vector of random integers within the specified range.
 */
vector<int> MTEngine::randint(int a, int b, int p, bool repeatation)
{
	// initialize a uniform distribution between a and b
	std::uniform_int_distribution<int> unif(a, b);
	vector<int> A(p, 0);
	if (repeatation == true)
	{
		for (int i = 0; i < p; i++)
		{
			A[i] = unif(rng);
		}
	}
	else
	{
		vector<bool> Auxilary(p, false);
		int count = 0;
		while (count < p)
		{
			int proposed = unif(rng);
			if (Auxilary[proposed] == 0)
			{
				A[count] = proposed;
				Auxilary[proposed] = 1;
				count++;
			}
		}
	}

	return A;
}

/**
 * Generates a 2D vector of random integers within the specified range.
 *
 * @param xmin The minimum value for the x-coordinate.
 * @param xmax The maximum value for the x-coordinate.
 * @param ymin The minimum value for the y-coordinate.
 * @param ymax The maximum value for the y-coordinate.
 * @param p The number of points to generate.
 * @param repeatation Determines whether repeated points are allowed (true) or not (false).
 * @return A 2D vector of random integers.
 */
vector<vector<int>> MTEngine::randint(int xmin, int xmax, int ymin, int ymax, int p, bool repeatation)
{
	// initialize a uniform distribution
	std::uniform_int_distribution<int> unifx(xmin, xmax);
	std::uniform_int_distribution<int> unify(ymin, ymax);

	int rowCount = xmax - xmin + 1;
	int colCount = ymax - ymin + 1;

	std::vector<std::vector<int>> points;
	points.resize(p, std::vector<int>(2, 0)); // Initialized With 0

	if (repeatation == true)
	{
		for (size_t i = 0; i < p; i++)
		{
			points[i][0] = unifx(rng);
			points[i][1] = unifx(rng);
		}
	}

	else
	{
		std::vector<std::vector<bool>> Auxilary;
		Auxilary.resize(rowCount, std::vector<bool>(colCount, 0.0)); // Initialized With 0.0
		int count = 0;
		while (count < p)
		{
			int propx = unifx(rng);
			int propy = unify(rng);
			if (Auxilary[propx][propy] == 0)
			{
				points[count][0] = propx;
				points[count][1] = propy;
				Auxilary[propx][propy] = 1;
				count++;
			}
		}
	}
	return points;
}

/**
 * Generates a vector of random points within the specified range.
 *
 * @param xmin The minimum value for the x-coordinate.
 * @param xmax The maximum value for the x-coordinate.
 * @param ymin The minimum value for the y-coordinate.
 * @param ymax The maximum value for the y-coordinate.
 * @param zmin The minimum value for the z-coordinate.
 * @param zmax The maximum value for the z-coordinate.
 * @param p The number of points to generate.
 * @param repeatation Determines whether the points can be repeated.
 * @return A vector of arrays representing the generated points.
 */
vector<std::array<double, 3>> MTEngine::randint(int xmin, int xmax, int ymin, int ymax, int zmin, int zmax, int p, bool repeatation)
{
	// initialize a uniform distribution
	std::uniform_int_distribution<int> unifx(xmin, xmax);
	std::uniform_int_distribution<int> unify(ymin, ymax);
	std::uniform_int_distribution<int> unifz(zmin, zmax);

	int X1 = xmax - xmin + 1;
	int X2 = ymax - ymin + 1;
	int X3 = zmax - zmin + 1;
	int X1X2 = X1 * X2;
	int X1X2X3 = X1 * X2 * X3;

	std::vector<std::array<double, 3>> points(p);
	// points.resize(p, std::vector<int>(3, 0)); //Initialized With 0

	if (repeatation == true)
	{
		for (size_t i = 0; i < p; i++)
		{
			points[i][0] = unifx(rng);
			points[i][1] = unify(rng);
			points[i][2] = unifz(rng);
		}
	}

	else
	{
		vector<int> seq = sequence(0, X1X2X3);
		Shuffle(seq);
#pragma omp parallel for
		for (int i = 0; i < p; i++)
		{
			int zo = seq[i] / X1X2;
			int diff = seq[i] - X1X2 * zo;
			int yo = diff / X1;
			int xo = diff - X1 * yo;
			points[i][0] = xmin + xo;
			points[i][1] = ymin + yo;
			points[i][2] = zmin + zo;
		}
	}

	return points;
}

/**
 * Generates a sequence of integers between 'a' and 'b'.
 *
 * @param a The starting value of the sequence.
 * @param b The ending value of the sequence.
 * @return A vector containing the generated sequence of integers.
 */
vector<int> MTEngine::sequence(int a, int b)
{
	int p = b - a;
	vector<int> I(p, 0);

#pragma omp parallel for
	for (int i = 0; i < p; i++)
	{
		I[i] = a + i;
	}
	return I;
}

/**
 * Returns a vector of size n with all elements set to 1.
 *
 * @param n The size of the vector.
 * @return A vector of size n with all elements set to 1.
 */
vector<int> MTEngine::ones(int n)
{
	vector<int> I(n, 0);
	for (int i = 0; i < n; i++)
	{
		I[i] = 1;
	}
	return I;
}
