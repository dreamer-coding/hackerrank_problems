/**
 * ==============================================================================
 * Author: Michael Gene Brockus (Dreamer)
 * Email: michaelbrockus@gmail.com
 * Organization: Fossil Logic
 * Description: 
 *     This file is part of the Fossil Logic project, where innovation meets
 *     excellence in software development. Michael Gene Brockus, also known as
 *     "Dreamer," is a dedicated contributor to this project. For any inquiries,
 *     feel free to contact Michael at michaelbrockus@gmail.com.
 * ==============================================================================
 */
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <cstdint>

using namespace std;

enum {
    ERROR_CODE_VALUE = -1
};

int32_t solveMeFirst(int32_t a, int32_t b) {
    try {
        // Perform the addition, check for any
        // possible exceptions (e.g., overflow)
        if (a < 0 || b < 0) {
            throw std::invalid_argument("Negative numbers are not allowed.");
        }
        return a + b;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Error code
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Error code
    }
}

int main() {
    int32_t num1, num2;
    int32_t sum;
    cin>>num1>>num2;
    sum = solveMeFirst(num1,num2);
    cout<<sum;
    return 0;
}
