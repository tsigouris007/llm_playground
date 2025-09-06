
#include <iostream> // Required for input/output operations (cout, cerr)
#include <chrono>   // Required for high-resolution timing (chrono::high_resolution_clock)
#include <iomanip>  // Required for output formatting (setprecision, fixed)
#include <string>   // Required for string manipulation (std::stoi, std::string)
#include <stdexcept> // Required for exception handling (std::invalid_argument, std::out_of_range)

// Function to calculate the series based on the given iterations and parameters
double calculate(int iterations, int p1, int p2) {
    double result = 1.0; // Initialize result as a double for floating-point precision
    for (int i = 1; i <= iterations; ++i) { // Loop from 1 up to and including 'iterations'
        // Calculate the 'j' term for the subtraction part, ensuring floating-point arithmetic
        double j_minus = static_cast<double>(i) * p1 - p2;
        result -= (1.0 / j_minus); // Subtract the term, using 1.0 for floating-point division

        // Calculate the 'j' term for the addition part, ensuring floating-point arithmetic
        double j_plus = static_cast<double>(i) * p1 + p2;
        result += (1.0 / j_plus); // Add the term, using 1.0 for floating-point division
    }
    return result;
}

int main(int argc, char* argv[]) {
    int iterations = 100000000; // Default number of iterations as specified in Python code

    // Parse command-line arguments for 'iterations'
    if (argc > 1) {
        try {
            iterations = std::stoi(argv[1]); // Convert the first argument to an integer
        } catch (const std::invalid_argument& e) {
            // Handle error if the argument is not a valid number
            std::cerr << "Error: Invalid argument for iterations. Please provide an integer." << std::endl;
            return 1; // Exit with an error code
        } catch (const std::out_of_range& e) {
            // Handle error if the argument is a number but out of integer range
            std::cerr << "Error: Iterations value out of integer range." << std::endl;
            return 1; // Exit with an error code
        }
    }

    // Record the starting time using a high-resolution clock
    auto start_time = std::chrono::high_resolution_clock::now();

    // Call the calculation function and multiply the result by 4, as in the Python script
    double result = calculate(iterations, 4, 1) * 4;

    // Record the ending time
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the duration of the execution in seconds
    std::chrono::duration<double> duration_seconds = end_time - start_time;

    // Print the calculated result, formatted to 12 decimal places
    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << std::endl;

    // Print the execution time, formatted to 6 decimal places
    std::cout << "Execution time: " << std::fixed << std::setprecision(6) << duration_seconds.count() << " seconds" << std::endl;

    return 0; // Indicate successful program execution
}
