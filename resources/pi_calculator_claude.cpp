
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>

// This is a pi calculation script
double calculate(int iterations, int p1, int p2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j = i * p1 - p2;
        result -= (1.0/j);
        j = i * p1 + p2;
        result += (1.0/j);
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Default iterations
    int iterations = 100000000;
    
    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--iterations" && i + 1 < argc) {
            iterations = std::atoi(argv[i + 1]);
            i++; // Skip the next argument
        }
    }
    
    // Measure execution time
    auto start_time = std::chrono::high_resolution_clock::now();
    double result = calculate(iterations, 4, 1) * 4;
    auto end_time = std::chrono::high_resolution_clock::now();
    
    // Calculate duration in seconds
    std::chrono::duration<double> elapsed = end_time - start_time;
    
    // Output results with appropriate precision
    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << std::endl;
    std::cout << "Execution time: " << std::fixed << std::setprecision(6) 
              << elapsed.count() << " seconds" << std::endl;
    
    return 0;
}
