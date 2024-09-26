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
#include <fstream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <stdexcept>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

enum {
    ERROR_CODE_VALUE = -1
};

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int32_t pageCount(int32_t n, int32_t p) {
    try {
        // Check if the total number of pages or the target page is negative
        if (n < 0 || p < 0) {
            throw invalid_argument("Negative numbers are not allowed.");
        }
        // Check if target page exceeds total pages
        if (p > n) {
            throw invalid_argument("Target page exceeds total number of pages.");
        }

        // Calculate the number of page turns from the front
        int32_t frontTurns = p / 2;
        
        // Calculate the number of page turns from the back
        int32_t backTurns = (n / 2) - (p / 2);
        
        // Return the minimum of the two counts
        return min(frontTurns, backTurns);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Error code
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Error code
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

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
