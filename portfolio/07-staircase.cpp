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
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <stdexcept>
#include <utility>  // For std::pair

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int32_t n) {
    try {
        if (n <= 0) {
            throw std::invalid_argument("The value of n must be a positive integer.");
        }

        // We start with a pair of const char type values.
        std::pair<const char, const char> box = {' ', '#'};
        
        for (auto it = 0; it < n; ++it) {
            // Set sub index to 'n' steps.
            // For each step, print ' ' or '#' based on the current index.
            for (auto sub = n; sub > 0; --sub) {
                std::cout << ((sub > it + 1) ? box.first : box.second);
            }
            // After completing each row, output a newline character.
            std::cout << std::endl;
        }

    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
