

#include <iostream>
#include <chrono>
#include <cmath>

// Function to calculate the series using iterations, p1, and p2
double calculate(int iterations, int p1, int p2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j = i * p1 - p2;
        result -= (1.0 / j);
        j = i * p1 + p2;
        result += (1.0 / j);
    }
    return result;
}

int main(int argc, char *argv[]) {
    int iterations = 100000000; // Default number of iterations
    if (argc > 1) {
        iterations = std::stoi(argv[1]); // Read iterations from command line arguments if provided
    }

    auto start_time = std::chrono::high_resolution_clock::now(); // Start timing
    double result = calculate(iterations, 4, 1) * 4; // Call calculation function
    auto end_time = std::chrono::high_resolution_clock::now(); // End timing
    std::chrono::duration<double> elapsed = end_time - start_time; // Calculate elapsed time

    std::cout.precision(12);
    std::cout << "Result: " << result << std::endl;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl; // Output execution time

    return 0;
}
